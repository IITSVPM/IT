#define BLYNK_TEMPLATE_ID "TMPL3lfdgSvgG"
#define BLYNK_TEMPLATE_NAME "GPS tracker"
#define BLYNK_AUTH_TOKEN "ehYB70EzNmJZRntizvM-P6Pl8TitJ1wg"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "OPPO F21s Pro 5G"; 
char pass[] = "12345678"; 

BlynkTimer timer;
bool Relay = 0;
int ledpin = D4;


#define sensor A0
#define waterPump D3

void setup() {
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT);
  pinMode(ledpin, OUTPUT);
  
  digitalWrite(waterPump, HIGH); 
  
  
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  
  
  timer.setInterval(100L, soilMoistureSensor);
}

BLYNK_WRITE(V1) {
  if (Relay == 1) {
    digitalWrite(waterPump, HIGH);  
  } else {
    digitalWrite(waterPump, LOW);  
  }
}

void soilMoistureSensor() {
  int value = analogRead(sensor);
  
  Serial.println(value);
  
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1; 
  
  Blynk.virtualWrite(V0, value);
}

void loop() {
  Blynk.run();  
  timer.run();  
}


















/* Sketch > Include Library > Manage Libraries
1. ESP8266 by ESP8266
2. Blynk by Volodymyr

Circuit Connections:
LED:
1. Positive of the LED to D4 (Digital Pin 4 on ESP8266)
2. Negative of the LED to GND through a resistor

Moisture Sensor:
1. VCC pin of the sensor to 3.3V on ESP8266
2. GND pin of the sensor to GND on ESP8266
3. Data pin of the sensor to A0 (Analog Pin 0 on ESP8266) 

ESP8266 Power:
1. VCC pin of ESP8266 to 3.3V power supply
2. GND pin of ESP8266 to GND*/