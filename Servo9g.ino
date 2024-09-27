#include <Servo.h>  // Include the Servo library

Servo myServo;      // Create a Servo object to control the servo motor

const int servoPin = 9;  // Pin where the servo is connected (digital pin 9)

void setup() {
  // Attach the servo to the pin
  myServo.attach(servoPin);

  // Initialize serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Move the servo to 0 degrees
  myServo.write(0);
  Serial.println("Servo at 0 degrees");
  delay(1000);  // Wait for 1 second

  // Move the servo to 90 degrees
  myServo.write(90);
  Serial.println("Servo at 90 degrees");
  delay(1000);  // Wait for 1 second

  // Move the servo to 180 degrees
  myServo.write(180);
  Serial.println("Servo at 180 degrees");
  delay(1000);  // Wait for 1 second
}
