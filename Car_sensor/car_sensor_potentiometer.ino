 // Note : This code is based on the exempelary library of the Arduino Sensor Ping.
const int trigPin = 7; //variable for trig pin of the HC-SRO4 Sensor
const int echoPin = 8; //variable for echo pin of the HC-SRO4 Sensor
const int ledPin_1 = 3; //variable for led pin 1
const int ledPin_2 = 6; //variable for led pin 2
const int ledPin_3 = 10; //variable for led pin 3
const int ledPin_4 = 5; //variable for led pin 4
const int ledPin_5 = 11; //variable for led pin 5
const int buzzer = 12; //variable for buzzer
int pot_value; //variable for brightness control

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); //tirg pin is set as output
  pinMode(echoPin, INPUT); //echo pin is set as input
  pinMode(buzzer, OUTPUT); //buzzer pin is set as output
  pinMode(A0, INPUT); //A0 is connected with potentiometer to give brightness control
  
}

void loop() {
  pot_value = analogRead(A0); // this reads and stores the A0 value in the variable
  int voltage = map(pot_value, 0, 1023, 0, 255); // this maps and stores the value in new variable voltage
   
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long duration, inches, cm;

  // The HC-SRO4 is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // The echo pin is used to read the signal from the HC-SRO4 a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration); // just as a ref. for serial monitor
  cm = microsecondsToCentimeters(duration); // this is used to set the if else statements and is also to be used as a ref. in serial monitor
  if(cm< 5){
    analogWrite(ledPin_1, voltage); //if the distance < 5cm then the led 1 will light up 
                                    // analogWrite is used instead of digitalWrite for brightness control
  }
  else{
    digitalWrite(ledPin_1, LOW); // if distance > 5cm led 1 will turn off.
  }
  if(cm< 10){
     analogWrite(ledPin_2, voltage);//if the distance < 10cm then the led 2 will light up 
                                    // analogWrite is used instead of digitalWrite for brightness control

  }
  else{
    digitalWrite(ledPin_2, LOW); // if distance > 10cm led 2 will turn off.
  }
  if(cm< 15){
    analogWrite(ledPin_3, voltage);//if the distance < 15cm then the led 3 will light up 
                                    // analogWrite is used instead of digitalWrite for brightness control

  }
  else{
    digitalWrite(ledPin_3, LOW); // if distance > 15cm led 3 will turn off.
  }
    if(cm< 20){
    analogWrite(ledPin_4, voltage);//if the distance < 20cm then the led 4 will light up 
                                    // analogWrite is used instead of digitalWrite for brightness control
  }
  else{
    digitalWrite(ledPin_4, LOW);// if distance > 20cm led 4 will turn off.
  
  }
   if(cm< 25){
  analogWrite(ledPin_5, voltage);;//if the distance < 25cm then the led 5 will light up 
                                    // analogWrite is used instead of digitalWrite for brightness control
  }
  else{
    digitalWrite(ledPin_5, LOW);// if distance > 25cm led 5 will turn off.
  }
  if(cm< 5){ // the buzzer will produce sound with led 1 indicating that the distance between the sensor and the wall is only 5 cm or less i.e when the car should be parked.
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);

  }
  else{
    digitalWrite(buzzer, LOW);
  }


  Serial.print(inches); // allows the serial monitor to display the defined variable.
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}
// HC-SRO4 is used instead of PING however the respective code can be adjusted for PING also.
long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
