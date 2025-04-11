        IoT-Based Energy Usage Tracker for Appliances

Objective
To monitor and log the power consumption (voltage, current, power, energy usage) of home or industrial appliances in real-time, and display it on a dashboard/app using ESP32 and a current/voltage sensor.
________________________________________
 Components Required
Component	Purpose
ESP32 / ESP8266	Wi-Fi-enabled microcontroller
PZEM-004T OR INA219	Voltage & current monitoring
AC Load (Bulb, Fan)	Appliance to be monitored
Blynk / Firebase / ThingSpeak	IoT dashboard
Relay Module (optional)	For remote ON/OFF control
________________________________________
 Recommended Sensor: PZEM-004T
It can measure:
•	Voltage (AC)
•	Current
•	Power (W)
•	Energy Consumption (kWh)
•	Frequency
 It communicates via UART (TX/RX) with ESP32.
________________________________________
 Circuit Connections (PZEM-004T + ESP32)
PZEM-004T	ESP32
VCC	5V
GND	GND
TX	GPIO16 (RX2)
RX	GPIO17 (TX2)
Use a 220V bulb or fan as a load connected via PZEM’s CT clamp and voltage input.
________________________________________
Dashboard Setup
•	Use Blynk or ThingSpeak
•	Display:
o	Voltage (V1)
o	Current (V2)
o	Power (V3)
o	Energy Used (V4)
o	Optional: Power switch (V5)

