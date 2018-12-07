/*
Leo's traffic light sketch.
*/

// Why not use enumerations for arduino pin's?

enum MyArduinoPins {
Button= 2, // <- 2
PedGreen= 8, // <- 8
PedRed, // <- 9
TrafficGreen, // <- 10 
TrafficOrange, // <- 11 
TrafficRed, // <- 12
};

int traffic_mode = 0; // 4 States. green orange red orange.

int traffic_delays[] = {
3000, // Green wave duration 
1000, // Orange wave duration 
3000, // Red wave duration
1000 // Orange wave duration after Red wave
};

/*
These Macros help us establishing the traffic mode cycle.
TRAFFIC <- convert traffic mode to traffic light pin offset.
TRAFFICPIN <- convert traffic mode to Arduino traffic pin number, using pin neighbour offset l.
*/

#define TRAFFIC(p) (p>2 ? p-2 : p) //
#define TRAFFICPIN(t, l) (TrafficGreen+(TRAFFIC(t) + l)%3)

/*
The setup routine.
*/

void setup() {
pinMode(Button, INPUT);
pinMode(PedGreen, OUTPUT);
pinMode(PedRed, OUTPUT);
pinMode(TrafficGreen, OUTPUT);
pinMode(TrafficOrange, OUTPUT);
pinMode(TrafficRed, OUTPUT);
}

/*
The loop routine
*/

void loop() {

if (digitalRead(Button)==HIGH && traffic_mode <= 1 ) {
/*
To get correct Arduino pin according to traffic_mode, we use Macro TRAFFICPIN(traffic_mode,0). In this case, we have Green traffic light and the Button pushed. 
First, we simulate orange wave.
*/
digitalWrite (TrafficGreen, LOW);
digitalWrite (TrafficOrange, HIGH);
digitalWrite (TrafficRed, LOW);
delay(1000);

/*
Second, Traffic gets Red light. And pedastrians get green light.
*/
digitalWrite (TrafficGreen, LOW);
digitalWrite (TrafficOrange, LOW);
digitalWrite (TrafficRed, HIGH);

digitalWrite( PedGreen, HIGH);
digitalWrite( PedRed, LOW);
delay(5000);

/*
Green wave for pedastrians over. We start pedastrian Red wave.Traffic gets Orange wave. 
*/ 
digitalWrite( PedGreen, LOW);
digitalWrite( PedRed, HIGH);

traffic_mode = 3; // 3 means Orange wave
delay(traffic_delays[traffic_mode]);
} 
else {
/*
This is the traffic mode cycle. 
The traffic mode cycle builds upon the idea of a traffic mode (variable traffic_mode). 
Valid values for traffic_mode could be ...
0 - Green wave
1 - Orange wave
2 - Red wave
3 - Orange wave after Red wave

traffic_mode cycles from 0 to 3. After 3, traffic_mode continues with 0.

At the beginning of the cycle: Red wave for pedestrians.
*/

digitalWrite( PedGreen, LOW);
digitalWrite( PedRed, HIGH);

/*
We use macro TRAFFICPIN to light up LED, mathing traffic_mode. Macro TRAFFICPIN uses modulo operator '%' to achieve it.
*/
digitalWrite( TRAFFICPIN(traffic_mode, 0), HIGH);
digitalWrite( TRAFFICPIN(traffic_mode, 1), LOW);
digitalWrite( TRAFFICPIN(traffic_mode, 2), LOW);

/*
Wait for next wave. Duration of wave determined by array traffic_delays.
*/
delay(traffic_delays[traffic_mode]);

/*
Finally, we make a step in the traffic_mode's cycle.
*/
traffic_mode = (traffic_mode + 1)%4;
}
}
