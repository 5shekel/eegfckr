//
// --------- TTone, a "Trinket" tone generator --------------
// http://w8bh.net/avr/TrinketTone.pdf
// Author: Bruce E. Hall <bhall66@gmail.com>
// Date: 29 Dec 2013
// Hardware: Trinket, using AVR ATtiny85
// Software: Arduino 1.0.5
// Size: 2352 bytes
//
// This small application uses Timer1 on the ATtiny85
// to implement a tone generator & play some music.
//
// Connect a piezo buzzer between PB1 (#1) and ground.
//
// The software is loosely based on the Arduino Tone Library,
// but has been simplified for use in this small application.
//
// The tune is "Prelude in C", from the Well-Tempered Clavier,
// Book One, by J. S. Bach
//
#include "tones.h"
#include "song.h"
/************************************************
  Music Content is stored in the following array.
  PROGMEM is needed because of the large data size.
  "Prelude in C" Well-Tempered Clavier, J.S.Bach
*************************************************/


volatile uint32_t toggle_count;
// TrinketTone:
// Generate a square wave on a given frequency & duration
// Call with frequency (in hertz) and duration (in milliseconds).
// Uses Timer1 in CTC mode. Assumes PB1 already in OUPUT mode.
// Generated tone is non-blocking, so routine immediately
// returns while tone is playing.
void TrinketTone(uint16_t frequency, uint32_t duration)
{
  // scan through prescalars to find the best fit
  uint32_t ocr = F_CPU / frequency / 2;
  uint8_t prescalarBits = 1;
  while (ocr > 255)
  {
    prescalarBits++;
    ocr /= 2;
  }
  // CTC mode; toggle OC1A pin; set prescalar
  TCCR1 = 0x90 | prescalarBits;

  // Calculate note duration in terms of toggle count
  // Duration will be tracked by timer1 ISR
  toggle_count = frequency * duration / 500;
  OCR1C = ocr - 1; // Set the OCR
  bitWrite(TIMSK, OCIE1A, 1); // enable interrupt
}
// Timer1 Interrupt Service Routine:
// Keeps track of note duration via toggle counter
// When correct time has elapsed, counter is disabled
ISR(TIMER1_COMPA_vect)
{
  if (toggle_count != 0) // done yet?
    toggle_count--; // no, keep counting
  else // yes,
    TCCR1 = 0x90; // stop the counter
}
// PlayBach:
// Plays "Prelude in C", which is held in noteArray
// Uses PROGMEM to store array, due to large size
void PlayBach()
{
  int len = 150; // modify for speed
  int dly = 190; // modify for articulation
  for (int count = 0; count < NOTECOUNT; count++)
  {
    TrinketTone( pgm_read_word( &noteArray[count] ), len);
    delay(dly);
    if ((count > 512) and (count < 540)) // slow down (rit.) at end.
    {
      len += 3;
      dly += 5;
    }
  }
  TrinketTone(C4, 1500); // final note
  delay(1500);
}
void setup()
{
  pinMode(1, OUTPUT); // enable OUTPUT (PB1, #1)
  PlayBach(); // Music!
  pinMode(1, INPUT); // disable OUTPUT
}
void loop()
{
  // once is enough. Really.
}
