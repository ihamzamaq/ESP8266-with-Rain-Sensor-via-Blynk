#define BLYNK_TEMPLATE_ID "TMPLgrzkvHG-"
#define BLYNK_DEVICE_NAME "Rain Sensor"
#define BLYNK_AUTH_TOKEN "" //Enter your Auth token

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";//Enter your WIFI name
char pass[] = "";//Enter your WIFI password

BlynkTimer timer;
bool eventTrigger = false;

void moisture() {
  int rainSensor = analogRead(A0);
  rainSensor = map(rainSensor, 0, 1023, 0, 100);
  Blynk.virtualWrite(V0, rainSensor);
  Serial.println(rainSensor);

  //if (rainSensor > 30 &&
     // eventTrigger == false)
  //{
   // eventTrigger = true;
    
  //  Blynk.logEvent("Tank is Full", "Gauge is greater than 30");
 // }
 // else
  //{
  //  eventTrigger = false;
  //}
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, moisture);

}
void loop() 
{
  Blynk.run();
  timer.run();
}
