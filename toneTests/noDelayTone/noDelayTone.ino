/*
details here: http://richdecibels.com/blog/?p=214

a useful way to achieve pretty accurate event timing without having to delve into the AVR’s Timer registers and learn about Interrupt Service Routines and so on. In your main loop() put:

int x;  //timing interval
long foo;  //timing placeholder
if (millis() - foo > x) {
 foo = millis();
 //run the following chunk of code every x milliseconds
}
This isn’t rocket science if you’ve seen it before, but if you’ve been stumbling around forever (like me) trying to figure out how to trigger multiple unrelated events then it’s genius! You can also replace millis() with micros() for greater precision.

I use that technique to create really simple audio output on the Arduino (bit-banging, they call it). Basically you select a pin and tell it to toggle every few microseconds. I like to use port manipulation to address pins, which I think is not so common in Arduino land but it makes sense to me.

void setup(){
 //set pins 2-7 as output
 DDRD |= B11111100;
}

long t1;  //timing placeholder
int f;  //output frequency in Hz

void loop() {
 if(micros() - t1 > 500000/f){
   t1 = micros();
   PORTD ^= B00000100; //toggle pin 2
 }
}
Now there’s a couple tricks in there. First DDRD is the direction register for port D, used to set which pins are inputs and which are outputs. The instruction DDRD |= B11111100; is a safe way to set pins 2-7 as outputs, leaving pins 0 and 1 alone, as they are needed for communication with the computer.

Then in the timing loop I’ve used 500000/f as the timing interval, where f is the resulting frequency in Hz. The 500,000 factor isn’t immediately obvious but it comes from 0.5*1,000,000 – 0.5 because the code fires every half cycle, and 1,000,000 to convert from seconds to microseconds.

The final trick is using a bitwise XOR to toggle a pin. In this case PORTD ^= B00000100; which toggles pin 2. The ^= operator allows you to toggle up to 8 pins simultaneously with one instruction (e.g. PORTD ^= B10110100; would toggle pins 2, 4, 5, and 7).

So there you have it, the simplest way to generate polyphonic audio on the Arduino. Stay tuned in the next couple of weeks to see what I’ve been using this code for…




INPUTS
A0 pitch pot
A1 separation pot
D8 mode switch

OUTPUTS
D12 - fL - output tone left channel
D13 - 0.5fL - output tone octave down, left channel
D4 - fR - output tone right channel
D7 - 0.5fR - output tone octave down, right channel
D3 - LFO1
D5 - LFO2
D6 - LFO3
D9 - LFO4
D10 - LFO5
D11 - LFO6
*/


void setup(){
  DDRD |= B11111100; //leave pins 0 and 1 for Tx and Rx
  DDRB |= B11111110; //pin 8 is mode switch
  PORTD = 0;
  PORTB = 0;
}

long t1, t2, t3, t4; //timing placeholders
long fL;  //output frequency (left channel)
long fR;  //output frequency (right channel)
int val0, tempVal0;  //pitch knob
int val1, tempVal1;  //seperation knob
int noiseAllowance = 4;
int minF = 1;  //minimum frequency in Hz
int maxF = 440;  //maximum frequency in Hz
int sep; //seperation frequency in Hz
int maxSep = 20; //max seperation frequency in Hz
boolean mode = LOW; //switch on pin 8 sets mode
int brightness[] = {//for LED PWM levels
  0, 1, 20, 255, 20, 1,
  1, 20, 255, 20, 1, 0,
  20, 255, 20, 1, 0, 1,
  255, 20, 1, 0, 1, 20,
  20, 1, 0, 1, 20, 255,
  1, 0, 1, 20, 255, 20
};

boolean tog1 = true;
boolean tog2 = true;
int i = 0;

void loop(){
  if(millis() - t1 > 100){//check inputs every 0.1s
    t1 = millis();

    tempVal0 = analogRead(0); //pitch knob
    if(abs(val0-tempVal0) > noiseAllowance) val0 = tempVal0; //discard any readings that show a change smaller than noiseAllowance
    fL = map(val0, 0, 1023, minF, maxF);  //map value to acceptable range

    tempVal1 = analogRead(1); //separation knob
    if(abs(val1-tempVal1) > noiseAllowance) val1 = tempVal1;
    sep = map(val1, 0, 1023, 0, maxSep);
    if(mode) fR = fL + sep;
    else fR = fL;

    mode = digitalRead(8);
  }


  //output fL in left channel, and fR in right channel

  //toggle pin 12 at fL Hz
  //toggle pin 13 at 0.5fL Hz for octave down
  if(micros() - t2 > 500000/fL){//0.5E6 factor comes from 1/2 cycle * E-6 microseconds
    t2 = micros();
    if(tog1) PORTB ^= B00010000;
    else PORTB ^= B00110000;
    tog1 = !tog1;
  }

  //toggle pin 4 at fR Hz, pin 7 at 0.5fR
  if(micros() - t3 > 500000/fR){
    t3 = micros();
    if(tog2) PORTD ^= B00010000;
    else PORTD ^= B10010000;
    tog2 = !tog2;
  }




  if(mode){
    //fade LEDs on pins 3,5,6,9,10,11 up and down out of sync
    //note filter LED's also connected to pins 3 and 9
    if(micros() - t4 > 166666/sep){ //500,000 * 2/6 (6 steps of brightness)
      t4 = micros();
      analogWrite(3, brightness[i]);
      analogWrite(5, brightness[i+6]);
      analogWrite(6, brightness[i+12]);
      analogWrite(9, brightness[i+18]);
      analogWrite(10, brightness[i+24]);
      analogWrite(11, brightness[i+30]);
      i++;
      if(i > 5) i=0;
    }
  }

  else{
    //fade LEDs up and down in sync
    if(micros() - t4 > 166666/sep){ //500,000 * 2/6 (6 steps of brightness)
      t4 = micros();
      analogWrite(3, brightness[i]);
      analogWrite(5, brightness[i]);
      analogWrite(6, brightness[i]);
      analogWrite(9, brightness[i]);
      analogWrite(10, brightness[i]);
      analogWrite(11, brightness[i]);
      i++;
      if(i > 5) i=0;
    }
  }
}
