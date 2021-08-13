#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;
const int DOOR_SENSOR_PIN = 3;  // Arduino pin connected to door sensor's pin

int currentDoorState; // current state of door sensor
int lastDoorState;    // previous state of door sensor

void setup() {
  tmrpcm.speakerPin = 8;
  Serial.begin(9600);
  pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP); 
  currentDoorState = digitalRead(DOOR_SENSOR_PIN); // read state
  Serial.println(currentDoorState);
}

void loop() {
  lastDoorState = currentDoorState;              // save the last state
  currentDoorState  = digitalRead(DOOR_SENSOR_PIN); // read new state

  if (lastDoorState == LOW && currentDoorState == HIGH) { 
    Serial.println("change");
    tone(8,262);
    delay(500);
    noTone(8);
  }
  else
  if (lastDoorState == HIGH && currentDoorState == LOW) { 
    Serial.println("change");
    tone(8,294);
    delay(500);
    noTone(8);
  }
}
