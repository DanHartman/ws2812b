#include <HCSR04.h>

byte triggerPin = 12;
byte echoPin = 13;
byte relayPin = 2;
double readings[25];
int idx = 0;
int length = sizeof(readings)/sizeof(readings[0]);    
double sum = 0;
double avg = 0;
int proximity_threshold_cm = 50;

void setup () {
  digitalWrite(relayPin, HIGH);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  HCSR04.begin(triggerPin, echoPin);
}

void loop () {
  double* distances = HCSR04.measureDistanceCm();
  readings[idx] = distances[0];
  idx += 1;
  if (idx == (length + 1)) {
    idx = 0;
    for (int i = 0; i < length; i++) {     
      sum = sum + readings[i];
    }
    avg = sum / length;
    sum = 0;
    if (avg < proximity_threshold_cm) {
      digitalWrite(relayPin, LOW);
      Serial.println("proximity threshold crossed");
      Serial.print(avg);
      Serial.print(" is less than threshold: ");
      Serial.print(proximity_threshold_cm);
      Serial.println(" cm");
      Serial.println("---");
    } else {
      digitalWrite(relayPin, HIGH);
      Serial.println("---");
    }
  }
  delay(10);
}