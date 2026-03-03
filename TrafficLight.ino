// Traffic Light Simulation using Arduino LEDs (written in C++)

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
