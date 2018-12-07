//Setting up traffic light LED pin constants

const int green = 10;
const int orange = 11;
const int red = 12;

//Setting up pedestrian light pin constants

const int greenPed = 8;
const int redPed = 9;

//Setting up button pin constant
const int buttonPin = 2;

void setup(){

//Setting all LED pins to outputs and turn them off (which is redundant as they default to that, but just in case)
for(int i = 8; i <= 12; i++){
pinMode(i, OUTPUT);
digitalWrite(i, LOW);
}

//Setting button pin to input
pinMode(buttonPin, INPUT);
}

void loop(){
//initially the light is green for 3 seconds and the pedestrian light is red
digitalWrite(green, HIGH);
digitalWrite(redPed, HIGH);
delay(3000);

//Then the light turns orange and the green light turns off
digitalWrite(green, LOW);
digitalWrite(orange, HIGH);

//if the button was being pressed, stay orange for 1 second
if(digitalRead(buttonPin) == HIGH){
delay(1000);

//then turn red and make the pedestrian light green for 5 seconds
digitalWrite(orange, LOW);
digitalWrite(redPed, LOW);
digitalWrite(red, HIGH);
digitalWrite(greenPed, HIGH);
delay(5000);
//Then turn off the green pedestrian light, setting the red light off and the green on happens after the else statement
digitalWrite(greenPed, LOW);
}

//if the button wasn't being pressed, stay orange for 1 second
else{
delay(1000);

//then turn the light red and wait 3 seconds
digitalWrite(orange, LOW);
digitalWrite(red, HIGH);
delay(3000);
}

//in both cases turn the red light off afterwards
digitalWrite(red, LOW);

}
