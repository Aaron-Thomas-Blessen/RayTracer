#include <Servo.h>

Servo myServo;

int eastSensorPin = A0;  // Analog pin for the east-facing light sensor
int westSensorPin = A1;  // Analog pin for the west-facing light sensor

int eastIntensity = 0;  // Variable to store the east sensor light intensity value
int westIntensity = 0;  // Variable to store the west sensor light intensity value

int currentPosition = 90;  // Start the servo at 90 degrees

void setup() {
  myServo.attach(9);  // Attach the servo to digital pin 9
  myServo.write(currentPosition);  // Initialize the servo at 90 degrees
  Serial.begin(9600);  // Start serial communication for debugging
}

void loop() {
  eastIntensity = analogRead(eastSensorPin);  // Read light intensity from the east sensor
  westIntensity = analogRead(westSensorPin);  // Read light intensity from the west sensor

  int error = eastIntensity - westIntensity;  // Calculate the difference in light intensity

  // Map the error to a servo position
  // Assuming error ranges from -1023 to 1023 and we want to map this to 0 to 180 degrees
  int targetPosition = map(error, -1023, 1023, 0, 180);

  // Ensure the target position is within the valid range for the servo
  targetPosition = constrain(targetPosition, 0, 180);

  // Move the servo slowly to the target position
  if (targetPosition != currentPosition) {
    if (targetPosition > currentPosition) {
      for (int pos = currentPosition; pos <= targetPosition; pos++) {
        myServo.write(pos);
        delay(10);  // Adjust this delay to control the speed of the servo movement
      }
    } else {
      for (int pos = currentPosition; pos >= targetPosition; pos--) {
        myServo.write(pos);
        delay(10);  // Adjust this delay to control the speed of the servo movement
      }
    }
    currentPosition = targetPosition;  // Update the current position of the servo
  }

  // Print the values to the Serial Monitor for debugging
  Serial.print("East Intensity: ");
  Serial.print(eastIntensity);
  Serial.print(" | West Intensity: ");
  Serial.print(westIntensity);
  Serial.print(" | Error: ");
  Serial.print(error);
  Serial.print(" | Target Position: ");
  Serial.println(targetPosition);

  delay(500);  // Wait before the next loop iteration
}
