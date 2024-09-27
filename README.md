# Solar Tracking System

### A precise and efficient solar tracking system that automatically adjusts the angle of a solar panel to follow the sun’s movement throughout the day. Built using Arduino, two LDRs (Light Dependent Resistors), and a 9g servo motor, this hardware project improves energy harvesting by aligning solar panels with sunlight.

## Features
- **Real-time solar tracking**: The system continuously monitors sunlight using two LDR sensors and adjusts the servo motor accordingly to maintain optimal solar panel positioning.
- **Energy efficiency**: By keeping the solar panel aligned with the sun, the system maximizes energy absorption.
- **Arduino-powered**: The project is built with Arduino, providing easy customization and expandability.

## Project Components
- **Arduino UNO** (or compatible microcontroller)
- **Two LDRs** (Light Dependent Resistors)
- **9g Servo Motor** (to rotate the panel based on LDR readings)
- **Resistors** (for LDRs)
- **Solar Panel** (optional, for real-world application)
- **Jumper Wires** and **Breadboard**

## How It Works
- The system uses two LDRs to detect the intensity of sunlight on either side of the panel.
- The Arduino processes the analog signals from the LDRs and calculates the difference in light intensity.
- Based on the difference, the servo motor adjusts the position of the panel to ensure it is always facing the sun.

## Circuit Diagram
Here is a simple breakdown of the connections:
1. **LDR 1**: Connect one leg to `A0` (Analog Pin 0), the other leg to GND, and a pull-down resistor to 5V.
2. **LDR 2**: Connect one leg to `A1` (Analog Pin 1), the other leg to GND, and a pull-down resistor to 5V.
3. **Servo Motor**: Connect the signal wire to digital pin `9`, the power wire to 5V, and the ground wire to GND.
4. **Arduino Power**: Power the Arduino via USB or external power supply.

## Installation and Setup

### Hardware Setup
1. Connect the two LDRs to analog pins `A0` and `A1` on the Arduino.
2. Attach the servo motor to digital pin `9`.
3. Set up the power and ground connections for all components.

### Software Setup
1. Download the [Arduino IDE](https://www.arduino.cc/en/software) if you haven't already.
2. Install the **Servo** library (comes pre-installed with Arduino IDE):
   ```cpp
   #include <Servo.h>
   ```
3. Write or upload the following code to the Arduino:

### Arduino Code

```cpp
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
```

## Usage
1. After assembling the circuit and uploading the code, power the Arduino.
2. Place the solar panel (or a small model) attached to the servo motor in a sunny location.
3. The system will automatically adjust the panel's orientation throughout the day to align with the sunlight.
4. Open the Arduino IDE Serial Monitor to view real-time data from the LDRs and the movement of the servo motor.

## Applications
- **Solar energy optimization**: Improves the efficiency of solar panels by constantly aligning them with the sun.
- **Educational tool**: Teaches the basics of solar tracking, sensor input, and motor control using Arduino.
- **DIY projects**: Ideal for home-based solar energy systems or hobbyist electronics projects.

## Future Improvements
- Adding a second axis for vertical tracking.
- Integrating real-time clock (RTC) for time-based tracking when sunlight is low or unavailable.
- Incorporating a larger servo or stepper motor for larger solar panels.
- Using a battery to store energy generated by the solar panel to power the Arduino.

## License
This project is open-source and licensed under the [MIT License](https://opensource.org/licenses/MIT).
