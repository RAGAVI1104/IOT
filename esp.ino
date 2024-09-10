#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#define LED D0

const char *ssid = "****"; // replace with your wifi ssid and wpa2 key
const char *pass = "****";
const char *server = "api.thingspeak.com";

WiFiClient client;
unsigned long myChannelNumber = 2593104; //Your Channel Number (Without Brackets)
const char* myWriteAPIKey = "CWAAJUWQ8UV1LL1S"; //Your Write

int A, B;


void setup() {
  Serial.begin(9600);

pinMode(LED, OUTPUT); // LED pin as output.
WiFi.begin(ssid, pass);

while (WiFi.status() != WL_CONNECTED) {

 digitalWrite(LED, 1); // turn the LED on (HIGH is the voltage level) delay(500);

delay(500);// wait for a second

digitalWrite(LED, 0); // turn the LED off by making the voltage LOW delay(500);
delay(500);
}

ThingSpeak.begin(client);
}
void loop()

{
ThingSpeak.setField(1, A);

ThingSpeak.setField(2, B);

ThingSpeak.writeFields (myChannelNumber, myWriteAPIKey);

delay(15000);

A++;

B++;

}
