#include <Arduino.h>

int pressure = 0;
void setup() {
    // write your initialization code here
    Serial.begin(9600);
    pinMode(A0, OUTPUT);
}

void loop() {
    // write your code here
    pressure = analogRead(A0);

    Serial.println(pressure);

    delay(1000);
}