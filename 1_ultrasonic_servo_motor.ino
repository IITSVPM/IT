#include <Servo.h> 
 

const int TRIG_PIN  = 6;  
const int ECHO_PIN  = 7;  
const int SERVO_PIN = 9; 
const int DISTANCE_THRESHOLD = 50; 
 
Servo servo; 
 
                   
float duration_us, distance_cm; 
 
void setup() { 
  Serial.begin (9600);       
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);  
  servo.attach(SERVO_PIN);   
  servo.write(0); 
} 
void loop() { 
                
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIG_PIN, LOW); 
                                                
  duration_us = pulseIn(ECHO_PIN, HIGH); 
                    
  distance_cm = 0.017 * duration_us; 
 
  if(distance_cm < DISTANCE_THRESHOLD) 
servo.write(90);     

else 
servo.write(0);               
Serial.print("distance: "); 
Serial.print(distance_cm); 
Serial.println(" cm"); 
delay(500); 
}

















/* Sketch > Include Library > Manage Libraries
1. Servo by Michael Margolis

Connections:
Ultrasonic Sensor (HC-SR04):
1. TRIG pin of the sensor to Digital Pin 6 on the Arduino.
2. ECHO pin of the sensor to Digital Pin 7 on the Arduino.
3. VCC pin of the sensor to the 5V pin on the Arduino.
4. GND pin of the sensor to the GND pin on the Arduino.

Servo Motor:
1. Signal pin(brown) of the servo to Digital Pin 9 on the Arduino.
2. Power pin of the servo to the 5V pin on the Arduino.
3. Ground pin(orange) of the servo to the GND pin on the Arduino. */