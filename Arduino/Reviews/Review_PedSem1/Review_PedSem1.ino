// traffic lights:
int grLED = 10; /*green light*/
int yelLED = 11; /*yellow light*/
int redLED = 12; /*red light*/
// pedestrian lights:
int predLED = 9; /*red light*/
int pgrLED = 8; /*green light*/
// button:
int but = 2; /*button*/

void setup() {
// pin working mode:
// traffic lights:
pinMode (grLED, OUTPUT);
pinMode (yelLED, OUTPUT);
pinMode (redLED, OUTPUT);
// pedestrian lights:
pinMode (predLED, OUTPUT);
pinMode (pgrLED, OUTPUT);
// button:
pinMode (but, INPUT);

}

void loop() {
int buttonState = 0;

//pedestrian lights:

digitalWrite (grLED, HIGH); /*green light blinks*/
digitalWrite (predLED, HIGH); /*pedestrian red light blinks*/
delay(3000); /*delay for 3 seconds*/
buttonState = digitalRead(but); /*read the button state*/
if (buttonState == HIGH){ /*if the button pressed*/
// traffic lights:
digitalWrite (grLED, LOW);
digitalWrite (yelLED, HIGH);
delay(1000);
// green pedestrian light blinks for 5 seconds:
digitalWrite (predLED, LOW); /*pedestrian red light switched off*/
digitalWrite (yelLED, LOW); /*yellow light switched off*/
digitalWrite (pgrLED, HIGH); /*pedestrian green light switched on*/
digitalWrite (redLED, HIGH); /*red light switched on*/
delay(5000); /*for 5 seconds*/
digitalWrite (pgrLED, LOW); /*pedestrian green light switched off*/
digitalWrite (redLED, LOW); /*red light switched off*/
}
else {
// If the button didn't press, traffic ligts blink as usual:
digitalWrite (grLED, LOW);
// Yellow LED blinks for 1 second:
digitalWrite (yelLED, HIGH);
delay(1000);
digitalWrite (yelLED, LOW);
// Red LED blinks for 3 sec:
digitalWrite (redLED, HIGH);
delay(3000);
digitalWrite (redLED, LOW);
}
}
