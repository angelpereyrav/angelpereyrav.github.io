/*
Fari es puto y se la come
*/
int green_led = 4;
int yellow_led = 3;
int red_led = 2;

void setup() {
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
}

// loop infinito, pd: fari se la seguirá comiendo infinitamente
void loop() {
  digitalWrite(green_led, HIGH);
  delay(2000);
  digitalWrite(green_led, LOW);
  delay(2000);

  
  digitalWrite(yellow_led, HIGH);
  delay(2000);
  digitalWrite(yellow_led, LOW);
  delay(2000);

  
  digitalWrite(red_led, HIGH);
  delay(2000);
  digitalWrite(red_led, LOW);
  delay(2000);
}
