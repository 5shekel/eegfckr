


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);   
  delay(1000);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(1000);
}
