


#define led1 2
#define led2 3
#define pot A2
#define hightimes 10 //time to keep led on in cycle
int logy = 5;
float freq = 250;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pot, INPUT);
  
}
void loop() {
  freq = analogRead(pot);  //between 4-32Hz blinks, 4 is 250ms, 32 is 31ms
  freq = map(freq, 100, 1024, 31, 250);
  freq = constrain(freq, 31,250);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);   
  delay(hightimes); 
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(freq-hightimes);
}
