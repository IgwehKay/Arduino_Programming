/*
Project: Automatic Rotation Controller
File: AutoRotationController.ino
Language: C++ (Arduino Framework)
Link: https://www.tinkercad.com/things/kXNV4MsyIiN-automatic-rotation-controller/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=sIASZc8dt2Y5o4w1RAFIRMjni1Ng2Paf_vU0WEzvfuE

Description:
- Automatically alternates between clockwise (CW) and anticlockwise (ACW) LEDs.
- Flash LED blinks visibly while system runs.
- Single STOP button stops all LEDs immediately.
*/

// Pin definitions
int stopButton = 10;    // STOP button (active LOW)
int led_flash = 7;      // Flash LED to show system is running
int cw = 11;            // Clockwise rotation LED
int acw = 12;           // Anticlockwise rotation LED

void setup() {
  // Configure STOP button as input with internal pull-up resistor
  pinMode(stopButton, INPUT_PULLUP);

  // Configure LEDs as outputs
  pinMode(led_flash, OUTPUT);
  pinMode(cw, OUTPUT);
  pinMode(acw, OUTPUT);
}

void loop() {

  // --------- Check STOP button ----------
  if (digitalRead(stopButton) == LOW) {
    digitalWrite(cw, LOW);        // Turn off CW LED
    digitalWrite(acw, LOW);       // Turn off ACW LED
    digitalWrite(led_flash, LOW); // Turn off Flash LED
    while(true);                  // Halt system indefinitely
  }

  // --------- Clockwise rotation ----------
  digitalWrite(cw, HIGH);   // Turn ON CW LED
  digitalWrite(acw, LOW);   // Ensure ACW LED is OFF

  // Flash LED while CW LED is ON for 2 seconds
  for (int i = 0; i < 4; i++) {       // 4 cycles * 500ms = 2 seconds
    digitalWrite(led_flash, HIGH);    // Turn Flash LED ON
    delay(250);                        // LED ON for 0.25 sec
    digitalWrite(led_flash, LOW);     // Turn Flash LED OFF
    delay(250);                        // LED OFF for 0.25 sec

    // Check STOP button between flashes
    if (digitalRead(stopButton) == LOW) {
      digitalWrite(cw, LOW);
      digitalWrite(acw, LOW);
      digitalWrite(led_flash, LOW);
      while(true); // Stop system immediately
    }
  }

  // --------- Anticlockwise rotation ----------
  digitalWrite(cw, LOW);    // Turn OFF CW LED
  digitalWrite(acw, HIGH);  // Turn ON ACW LED

  // Flash LED while ACW LED is ON for 2 seconds
  for (int i = 0; i < 4; i++) {       // 4 cycles * 500ms = 2 seconds
    digitalWrite(led_flash, HIGH);    // Turn Flash LED ON
    delay(250);                        // LED ON for 0.25 sec
    digitalWrite(led_flash, LOW);     // Turn Flash LED OFF
    delay(250);                        // LED OFF for 0.25 sec

    // Check STOP button between flashes
    if (digitalRead(stopButton) == LOW) {
      digitalWrite(cw, LOW);
      digitalWrite(acw, LOW);
      digitalWrite(led_flash, LOW);
      while(true); // Stop system immediately
    }
  }
}
