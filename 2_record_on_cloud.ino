2. record on cloud(thing speak)

#include<DHT.h>
#include<ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#define DHTPIN D7
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
const char*ssid="OPPO F21s Pro 5G";
const char*password="12345678";
WiFiClient client;
unsigned long myChannelNumber =2731305;
const char*myWriteAPIKey="ZW7MNZKXCRKSAGCK";
uint8_t temperature,humidity; 

void setup()
{
Serial.begin(115200);
dht.begin();
delay(10);

Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFiconnected");

Serial.println(WiFi.localIP());
ThingSpeak.begin(client);
}
void loop()
{
static boolean data_state = false;
temperature=dht.readTemperature();
humidity= dht.readHumidity();
Serial.print("Temperature Value is :");
Serial.print(temperature);
Serial.println("0C");
Serial.print("Humidity Value is :");
Serial.print(humidity);
Serial.println("%");

if( data_state )
{
ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
data_state = false;
}
else
{
ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);
data_state = true;
}
delay(30000);
}



















/* Search library from sketch > include library > manage library   
1. thing speak by MathWorks 
2. DHT sensor library by Adafruit
3. ESP8266 by Adafruit

Connections:
DHT11 Sensor:
1. VCC pin of the sensor to 3.3V on ESP8266
2. GND pin of the sensor to GND on ESP8266
3. Data pin of the sensor to D7 (GPIO 13) on ESP8266

ESP8266:
1. VCC pin of ESP8266 to 3.3V power supply
2. GND pin of ESP8266 to GND
3. TX pin of ESP8266 to RX of Serial Adapter
4. RX pin of ESP8266 to TX of Serial Adapter
5. GPIO0 of ESP8266 to GND (for programming mode)
6. CH_PD/EN of ESP8266 to 3.3V (enable the module)
7. RST of ESP8266 to GND (to reset the module) */