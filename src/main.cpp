/**
 * @file main.cpp
 * @brief MG995 Servo Motor Control with Ultrasonic Distance Sensor
 *
 * This program controls a MG995 servo motor based on distance measurements from
 * an HC-SR04 ultrasonic sensor. When the detected distance is 15 cm or less,
 * the servo rotates to 180 degrees. Otherwise, it rotates to 0 degrees.
 * Distance readings are continuously printed to the serial monitor.
 *
 * @author Alan C
 * @date 2026-02-18
 *
 * @details
 * Hardware Connections:
 * - Pin 8: Ultrasonic sensor trigger pin
 * - Pin 10: Ultrasonic sensor echo pin
 * - Pin 5: MG995 servo control pin
 * - Serial: 9600 baud for distance output
 */

#include <Arduino.h>
#include<Servo.h>

Servo myservo;

int trg_pin = 8;
int ech_pin = 10;

/**
 * @brief Initialize hardware pins and serial communication
 *
 * Sets up the pin modes for the ultrasonic sensor (trigger and echo),
 * attaches the servo motor to its control pin, and initializes serial
 * communication at 9600 baud for debugging and distance output.
 *
 * @return void
 */
void setup() {
    pinMode(trg_pin,OUTPUT);
    pinMode(ech_pin,INPUT);
    myservo.attach(5);
    Serial.begin(9600);
}

/**
 * @brief Main control loop for distance measurement and servo control
 *
 * Continuously measures the distance using the HC-SR04 ultrasonic sensor,
 * controls the MG995 servo motor based on the measured distance, and outputs
 * the distance reading to the serial monitor. The servo rotates to 180 degrees
 * if distance <= 15 cm, otherwise to 0 degrees.
 *
 * @details
 * The measurement cycle:
 * 1. Sends a 10 microsecond pulse to the trigger pin
 * 2. Measures the echo pulse duration from the echo pin
 * 3. Calculates distance in centimeters (duration * 0.0343 / 2)
 * 4. Adjusts servo position based on distance threshold
 * 5. Prints distance to serial monitor
 * 6. Waits 100ms before next cycle
 *
 * @return void
 */
void loop() {
    digitalWrite(trg_pin,HIGH);
    delayMicroseconds(2);
    digitalWrite(trg_pin,LOW);
    delayMicroseconds(10);
    digitalWrite(trg_pin,HIGH);
    long duration = pulseIn(ech_pin,HIGH);
    float distance = duration*(0.0343/2);
    if(distance<=15){
        myservo.write(180);

    }else{
        myservo.write(0);
    }
    Serial.print("Distance");
    Serial.print(distance);
    Serial.println("CM");
    delay(100);
}