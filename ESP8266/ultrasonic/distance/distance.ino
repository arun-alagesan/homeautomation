
#define TRIGGER 2 //D4
#define ECHO    0 //D3

long duration;
int distance;
void setup() {
  pinMode(TRIGGER, OUTPUT); // Sets the trigPin as an Output
pinMode(ECHO, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  // Clears the trigPin
digitalWrite(TRIGGER, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(TRIGGER, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(ECHO, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(2000);
}
