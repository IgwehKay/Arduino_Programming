/*
Project: Traffic Light Simulation
File Name: TrafficLightCode.ino

Programming Language:
C++ (Arduino Framework)

Simulation Link:
 https://www.tinkercad.com/things/5v56fLbzdJk/editel?sharecode=JlhfrvMiHM9mBp0TYKD7Kpra5NxuEfRPEh_fADBrclM

Description:
This program simulates a basic traffic light system using three LEDs connected to an Arduino board.

Traffic Light Sequence:

1. Red ON (Stop) – 2 seconds
2. Yellow ON, Red OFF (Prepare to move) – 2 seconds
3. Green ON, Yellow OFF (Go) – 2 seconds
4. Yellow ON, Green OFF (Prepare to stop) – 2 seconds
5. Yellow OFF → Loop restarts

Hardware Connections:
Red LED    → Pin 7
Yellow LED → Pin 6
Green LED  → Pin 5
*/

int redPin = 7;        // Pin connected to Red LED
int yellowPin = 6;     // Pin connected to Yellow LED
int greenPin = 5;      // Pin connected to Green LED

void setup() {
  // Configure the LED pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Turn on Red LED (Stop)
  digitalWrite(redPin, HIGH);
  delay(2000);  // Wait 2 seconds

  // Turn on Yellow LED (Prepare to move), turn off Red LED
  digitalWrite(yellowPin, HIGH);
  digitalWrite(redPin, LOW);
  delay(2000);  // Wait 2 seconds

  // Turn on Green LED (Go), turn off Yellow LED
  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowPin, LOW);
  delay(2000);  // Wait 2 seconds

  // Turn on Yellow LED (Prepare to stop), turn off Green LED
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(2000);  // Wait 2 seconds

  // Turn off Yellow LED, loop will restart
  digitalWrite(yellowPin, LOW);
}
