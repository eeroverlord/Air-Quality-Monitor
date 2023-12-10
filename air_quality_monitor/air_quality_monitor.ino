#include <DHT.h>; // library version 1.4.6

// Setting up the DHT sensor
#define DHTPIN 7 // DHT22 data pin number
#define DHTTYPE DHT22 // DHT version
DHT dht(DHTPIN, DHTTYPE);

int buzzerPin = 8; // Buzzer pin number

void setup() {
  Serial.begin(9600); // startup
  pinMode(buzzerPin, OUTPUT);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  // Print values
  Serial.print(temp);
  Serial.print(" *C"); 
  Serial.print(",");
  Serial.print(hum);
  Serial.println(" %");
  // Alarm
  if (temp > 30 || temp < 15 || hum > 45 || hum < 30) {
    tone(buzzerPin, 500); // On
    delay(1000); // Sound for 1000ms
    noTone(buzzerPin); // Off
  }
  delay(5000); // clock of 5000ms
}