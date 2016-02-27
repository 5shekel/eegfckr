// code for sound and led output on an ATtiny85
// Cleand up code from Kobakant
// using leah buechley’s sound code, taken from: http://web.media.mit.edu/~leah/LilyPad/07_sound.html
// adding noDelay for dual tone, http://tami.org.il/index.php/Brain

int speakerPin_0 = 0;
int speakerPin_1 = 1;

void setup()
{
  pinMode(speakerPin_0, OUTPUT);
  pinMode(speakerPin_1, OUTPUT);
}

void loop() {
  scale('E', speakerPin_0); //plays note C for half a second
  
  scale('F', speakerPin_1); //plays note C for half a second
  /*
  scale('C', speakerPin_0); //plays note C for half a second
  scale('G', speakerPin_0); //plays note C for half a second
  scale('A', speakerPin_0 ); //plays note C for half a second
  */
}

void scale (char note, int pin)
{
  if (note == 'C')
    beep(pin, 2093, 500); //C: play the note C (C7 from the chart linked to above) for 500ms
  if (note == 'D')
    beep(pin, 2349, 500); //D
  if (note == 'E')
    beep(pin, 2637, 500); //E
  if (note == 'F')
    beep(pin, 2793, 500); //F
  if (note == 'G')
    beep(pin, 3136, 500); //G
  if (note == 'A')
    beep(pin, 3520, 500); //A
  if (note == 'B')
    beep(pin, 3951, 500); //B
  if (note == 'H')
    beep(pin, 4186, 500); //C
}

void beepNoDelay (int pin, int frequencyInHertz, long timeInMilliseconds) // the sound producing function
{
  int x;
  long delayAmount = (long)(1000000 / frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
  for (x = 0; x < loopTime; x++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(pin, LOW);
    delayMicroseconds(delayAmount);
    //break;
  }

}

void beep (int pin, int frequencyInHertz, long timeInMilliseconds) // the sound producing function
{
  int x;
  long delayAmount = (long)(1000000 / frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
  for (x = 0; x < loopTime; x++) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(pin, LOW);
    delayMicroseconds(delayAmount);
    //break;
  }

}

