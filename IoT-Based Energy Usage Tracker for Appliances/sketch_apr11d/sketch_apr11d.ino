#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <PZEM004Tv30.h>

char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";

// PZEM TX/RX pins (ESP32)
#define RXD2 16
#define TXD2 17

PZEM004Tv30 pzem(&Serial2); // Create instance using Serial2

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Blynk.begin(auth, ssid, pass);

  Serial.println("Energy Tracker Initialized...");
}

void loop() {
  Blynk.run();

  float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();
  float energy = pzem.energy();

  // Print values to Serial Monitor
  Serial.print("V: "); Serial.print(voltage); Serial.print(" V | ");
  Serial.print("I: "); Serial.print(current); Serial.print(" A | ");
  Serial.print("P: "); Serial.print(power); Serial.print(" W | ");
  Serial.print("E: "); Serial.println(energy); Serial.print(" kWh");

  // Send to Blynk dashboard
  Blynk.virtualWrite(V1, voltage);
  Blynk.virtualWrite(V2, current);
  Blynk.virtualWrite(V3, power);
  Blynk.virtualWrite(V4, energy);

  delay(2000);
}
