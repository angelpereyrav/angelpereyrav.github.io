/*
The assembly for this program has a button for pedestrians who wish to cross the street. 
When the button is kept pressed when the car traffic light is about to turn from green to yellow, the traffic light changes to yellow, then to red, just as the pedestrian light turns green - just like in real life.
*/

// Variables used for the car traffic light
int green_led = 10; // Green Car Traffic Light on pin 10.
int yellow_led = 11; // Yellow Car Traffic Light on pin 11.
int red_led = 12; // Red Car Traffic Light on pin 12.

// Variables used for the pedestrian light
int ped_green_led = 8; // Green Pedestrian Light on pin 8.
int ped_red_led = 9; // Red Pedestrian Light on pin 9.

// Variables for the action button
const int buttonPin = 2;      // the number of the push button pin

// setup variables
void setup() {
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(ped_green_led, OUTPUT);
  pinMode(ped_red_led, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// infinite loop
void loop() {
    digitalWrite(green_led, HIGH);     // We initialize with the Green Car Traffic Light "on".
    digitalWrite(ped_red_led, HIGH);   // We initialize with Red Pedestrian Light "on".
    delay(3000); // 3 seconds delay.
    
    // Condition check if the button on Pin 2 is pushed.
  if (digitalRead(buttonPin) == HIGH) {
    // if TRUE
    digitalWrite(green_led, LOW); // We turn "off" the green car traffic light.
    digitalWrite(yellow_led, HIGH); // We turn "on" the yellow car traffic light.
    delay(1000); // 1 second delay.
    digitalWrite(yellow_led, LOW); // We turn "off" the yellow car traffic light.
    digitalWrite(red_led, HIGH); // We turn "on" the red car traffic light.
    digitalWrite(ped_red_led, LOW); // We turn "off" the red pedestrian light.
    digitalWrite(ped_green_led, HIGH); // We turn "on" the green pedestrian light.
    delay(5000); // 5 seconds delay.
    digitalWrite(ped_green_led, LOW); // We turn "off" the green pedestrian light.
    digitalWrite(red_led, LOW); // We turn "on" the red car traffic light.
  }
    //if FALSE
  else {
    digitalWrite(green_led, LOW); // We turn "off" the green car traffic light.
    digitalWrite(yellow_led, HIGH); // We turn "on" the yellow car traffic light.
    delay(1000); // 1 second delay.
    digitalWrite(yellow_led, LOW); // We turn "off" the yellow car traffic light.
    digitalWrite(red_led, HIGH); // We turn "on" the red car traffic light.
    delay(3000); // 3 seconds delay.
    digitalWrite(red_led, LOW); // We turn "off" the red car traffic light.
  }
}
