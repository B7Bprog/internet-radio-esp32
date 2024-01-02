#include <WiFi.h>
#include "secrets.h"
#define LED_BUILTIN 2

const char* ssid = ACTUAL_SSID;
const char* password = ACTUAL_PASSWORD;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT); 


  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(WiFi.status());
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts > 20) {
      Serial.println("Connection failed. Check your credentials or network.");
      break;
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    digitalWrite(LED_BUILTIN, HIGH); 
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void loop() {
  // Your code here
}
