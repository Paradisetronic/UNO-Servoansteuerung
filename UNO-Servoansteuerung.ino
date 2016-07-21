// UNO-Servoansteuerung
// Copyright (c) 2016 Paradisetronic.com, Thilo Geismar

// Einbinden der Servobibliothek
#include <Servo.h>

// Erstellen eines Servo-Objekts
Servo servo;

void setup() {
  // Einrichten der seriellen Schnittstelle
  Serial.begin(9600);
  // unser Servo ist an Pin 9 angeschlossen
  servo.attach(9);
}
void loop() {}

// wird aufgerufen, sobald Daten verfügbar sind
void serialEvent() {
    // Einlesen des übergebenen Sollwertes und parsen zu Integer
    int soll = Serial.parseInt();
    // Ausgabe des Wertes zur Kontrolle
    Serial.print(soll);
    // Fahren auf gewünschte Position
    servo.write(soll);
    // Einlesen der Servoposition
    int ist = servo.read();
    // Ausgabe des Wertes
    Serial.print(" Servoposition: ");
    Serial.println(ist, DEC);
}

