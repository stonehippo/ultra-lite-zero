#include <Arduino.h>
#include "main.h"

int rollBtnPin = 3;
bool rollFlag = false;

void setup() {
  // Use an analog pin as a random seed for the PRNG
  randomSeed(analogRead(0));
  pinMode(rollBtnPin, INPUT_PULLUP);
  attachInterrupt(rollBtnPin, rollSignal, RISING);
  Serial.begin(9600);
}

void loop() {
  if (rollFlag) {
    Serial.print("Rolled the dice: ");
    Serial.println(rollDice(3));
    rollFlag = false;
  }
}

void rollSignal() {
  rollFlag = true;
}

// Roll a certain number of six-sided dice
int rollDice(int count) {
  int sum = 0;
  int rolls = 0;
  while (rolls != count) {
    sum = sum + random(1, 6);
    rolls++;
  }
  return sum;
}
