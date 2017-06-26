//
// --------- TTone, a "Trinket" tone generator --------------
//
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
/*************************************************
  Note Pitch Constants
*************************************************/
#define B0 31
#define C1 33
#define CS1 35
#define D1 37
#define DS1 39
#define E1 41
#define F1 44
#define FS1 46
#define G1 49
#define GS1 52
#define A1 55
#define AS1 58
#define B1 62
#define C2 65
#define CS2 69
#define D2 73
#define DS2 78
#define E2 82
#define F2 87
#define FS2 93
#define G2 98
#define GS2 104
#define A2 110
#define AS2 117
#define B2 123
#define C3 131
#define CS3 139
#define D3 147
#define DS3 156
#define E3 165
#define F3 175
#define FS3 185
#define G3 196
#define GS3 208
#define A3 220
#define AS3 233
#define B3 247
#define C4 262
#define CS4 277
#define D4 294
#define DS4 311
#define E4 330
#define F4 349
#define FS4 370
#define G4 392
#define GS4 415
#define A4 440
#define AS4 466
#define B4 494
#define C5 523
#define CS5 554
#define D5 587
#define DS5 622
#define E5 659
#define F5 698
#define FS5 740
#define G5 784
#define GS5 831
#define A5 880
#define AS5 932
#define B5 988
#define C6 1047
#define CS6 1109
#define D6 1175
#define DS6 1245
#define E6 1319
#define F6 1397
#define FS6 1480
#define G6 1568
#define GS6 1661
#define A6 1760
#define AS6 1865
#define B6 1976
#define C7 2093
#define CS7 2217
#define D7 2349
#define DS7 2489
#define E7 2637
#define F7 2794
#define FS7 2960
#define G7 3136
#define GS7 3322
#define A7 3520
#define AS7 3729
#define B7 3951
#define C8 4186
#define CS8 4435
#define D8 4699
#define DS8 4978
/*************************************************
  Note Duration Constants (not used in this app)
*************************************************/
#define FN 1 // 64th note
#define TN 2 // 32nd note
#define DTN 3 // dotted 32nd note
#define SN 4 // 16th note
#define DSN 6 // dotted 16th note
#define EN 8 // 8th note
#define DEN 12 // dotted 8th note
#define QN 16 // quarter note
#define DQN 24 // dotted quarter note
#define HN 32 // half note
#define DHN 48 // dotted half note
#define WN 64 // whole note
#define DWN 96 // dotted whole note

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

int constant = 0;
float angle = 0.05;
int scalar = 99;
float speed = 6.5;
float weevy;

unsigned long previousMillis = 0;        // will store last time LED was updated
int interval = 33;
int ledPin = 4;
bool ledState=0;

void setup()
{
  pinMode(1, OUTPUT); // enable OUTPUT (PB1, #1)
  pinMode(ledPin, OUTPUT); //
}

void sine(int dail_i) {
  weevy = sin(angle) * scalar;
  TrinketTone(dail_i + weevy, 0); //C4 and CS4
  //angle = angle + speed;
}

void loop()
{
  int dail = analogRead(3);
  //scalar = random(3);
  unsigned long currentMillis = millis();

  TrinketTone(dail, 0); //C4 and CS4
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }

  /*
     #define FS3 185
    #define G3 196
    #define GS3 208

    #define GS3 208
    #define A3 220
    #define AS3 233
    #define B3 247
    #define C4 262
    #define CS4 277
    #define D4 294
    #define DS4 311
  */
  /*
    //TrinketTone(C3, 2000); //C4 and CS4
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
  */
}
