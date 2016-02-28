/*
 * https://github.com/5shekel/eegfckr
  Note1: some code from the adafriut gemma simple thermain example.
  Note2: The Arduino tone library does not work for the ATTiny85 on the
  Trinket and Gemma.  The beep function below is similar.  The beep code
  is adapted from Dr. Leah Buechley at
  http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
*/

//#define speaker_pin   0    // speaker_pin on GPIO #0
//#define SCALE     2.0  // You can change this to change the tone scale

#define led1 2
#define led2 3
#define pot A2
#define hightimes 10 //time to keep led on in cycle

int logy = 5;

void setup() {
  //pinMode(speaker_pin, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pot, INPUT);

}
void loop() {

  int input = analogRead(pot);  //between 4-32Hz blinks, 4 is 250ms, 32 is 31ms
  int freqLight = map(input, 100, 1024, 31, 250);
  freqLight = constrain(freqLight, 31, 250);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(hightimes);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(freqLight - hightimes);

  /*
    int freqAudio=220+(int)(input*SCALE); // change the voltage read to a frequency
                             // you can change the values to scale
                             // your frequency range
    beep(speaker_pin,freqAudio,600);    // output the tone to digital pin 0
                             // you can change 400 to different times}
  */
}

/*
// the sound producing function
void beep (unsigned char speaker_pinPin, int frequencyInHertz, long timeInMilliseconds)
{ // http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
  int x;
  long delayAmount = (long)(1000000 / frequencyInHertz);
  long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
  for (x = 0; x < loopTime; x++)
  {
    digitalWrite(speaker_pinPin, HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(speaker_pinPin, LOW);
    delayMicroseconds(delayAmount);
  }
}

void scale (char note)
{
  if (note == 'C')
    beep(speaker_pin, 2093, 500); //C: play the note C (C7 from the chart linked to above) for 500ms
  if (note == 'D')
    beep(speaker_pin, 2349, 500); //D
  if (note == 'E')
    beep(speaker_pin, 2637, 500); //E
  if (note == 'F')
    beep(speaker_pin, 2793, 500); //F
  if (note == 'G')
    beep(speaker_pin, 3136, 500); //G
  if (note == 'A')
    beep(speaker_pin, 3520, 500); //A
  if (note == 'B')
    beep(speaker_pin, 3951, 500); //B
  if (note == 'H')
    beep(speaker_pin, 4186, 500); //C
}
*/
