/*
Note1: some code from the adafriut gemma simple thermain example.
Note2: The Arduino tone library does not work for the ATTiny85 on the
Trinket and Gemma.  The beep function below is similar.  The beep code
is adapted from Dr. Leah Buechley at
http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
 */

#define SPEAKER_left   0    // Speaker on GPIO #0
#define SPEAKER_right  1    // Speaker on GPIO #1
#define SCALE     2.0  // You can change this to change the tone scale

#define led1 2
#define led2 1
#define pot A3
#define hightimes 10 //time to keep led on in cycle

int logy = 5;

void setup() {
  pinMode(SPEAKER_left,OUTPUT);
  pinMode(SPEAKER_right,OUTPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pot, INPUT);
  
}
void loop() {
  
  int input = analogRead(pot);  //between 4-32Hz blinks, 4 is 250ms, 32 is 31ms
  int freqLight = map(input, 100, 1024, 31, 250);
  freqLight = constrain(freqLight, 31,250);

  int freqAudio=220+(int)(input*SCALE); // change the voltage read to a frequency
                             // you can change the values to scale
                             // your frequency range  
  beep(SPEAKER_left,freqAudio,400);    // output the tone to digital pin 0
  //beep(SPEAKER_right,freqAudio,400);    // output the tone to digital pin 1
                             // you can change 400 to different times}

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);   
  delay(hightimes); 
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(freqLight-hightimes);
}

 
// the sound producing function
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{   // http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
          int x;   
          long delayAmount = (long)(1000000/frequencyInHertz);
          long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
          for (x=0;x<loopTime;x++)   
          {  
              digitalWrite(speakerPin,HIGH);
              delayMicroseconds(delayAmount);
              digitalWrite(speakerPin,LOW);
              delayMicroseconds(delayAmount);
          }  
}
