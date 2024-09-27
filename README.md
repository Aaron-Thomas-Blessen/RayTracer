# **RayTracer**

RayTracer is a precise and efficient solar tracking system that automatically adjusts the angle of a solar panel to follow the sun’s movement throughout the day. Built using Arduino, two LDRs (Light Dependent Resistors), and a 9g servo motor, this hardware project improves energy harvesting by aligning solar panels with sunlight.



## **🌟 Introduction**

RayTracer is designed to increase solar energy efficiency by dynamically adjusting the solar panel's position. This README provides an overview of the features, components, and instructions for assembling and programming the system.



## **🚀 Features**

1. **Real-time Solar Tracking**: The system continuously monitors sunlight using two LDR sensors and adjusts the servo motor accordingly to maintain optimal solar panel positioning.
2. **Energy Efficiency**: Maximizes energy absorption by ensuring the panel is aligned with the sun.
3. **Arduino-powered**: Built using the versatile Arduino platform, offering easy customization and expandability.



## **🛠️ Project Components**

- **Arduino UNO** (or compatible microcontroller)
- **Two LDRs** (Light Dependent Resistors)
- **9g Servo Motor** (to rotate the panel based on LDR readings)
- **Resistors** (for LDRs)
- **Solar Panel** (optional, for real-world application)
- **Jumper Wires** and **Breadboard**



## **📋 How It Works**

RayTracer uses two LDRs to detect sunlight intensity on both sides of the solar panel. The Arduino processes the input from the LDRs and calculates the difference in light intensity. It then adjusts the servo motor to ensure that the solar panel is always optimally positioned.

- **LDR 1** measures light from one side (east-facing).
- **LDR 2** measures light from the opposite side (west-facing).
- **Servo Motor** adjusts the solar panel based on the difference in light intensity between the two LDRs.



## **🔧 Circuit Diagram**

1. **LDR 1**: Connect to analog pin `A0` and ground, with a pull-down resistor to 5V.
2. **LDR 2**: Connect to analog pin `A1` and ground, with a pull-down resistor to 5V.
3. **Servo Motor**: Signal wire to digital pin `9`, power to 5V, and ground to GND.
4. **Arduino Power**: Use USB or an external power supply.



## **🛠 Installation and Setup**

### **Hardware Setup**
1. Assemble the circuit as shown in the diagram.
2. Mount the solar panel on the servo motor.

### **Software Setup**
1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the **Servo** library using the following code:
   ```cpp
   #include <Servo.h>
   ```
3. Upload the provided Arduino code to control the servo motor based on LDR readings.

## **💻 Arduino Code**

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

  // Map the error to a servo position (0 to 180 degrees)
  int targetPosition = map(error, -1023, 1023, 0, 180);
  targetPosition = constrain(targetPosition, 0, 180);

  if (targetPosition != currentPosition) {
    myServo.write(targetPosition);  // Move the servo to the target position
    currentPosition = targetPosition;  // Update current position
  }

  delay(500);  // Wait before the next loop iteration
}
```



## **📋 Usage**

1. **Power On**: After assembling the hardware and uploading the code, power the Arduino.
2. **Sunlight Tracking**: Place the system in a sunny location, and the servo motor will automatically adjust the panel's orientation based on sunlight.
3. **Monitor**: Use the Arduino IDE Serial Monitor to track real-time data from the LDRs and servo movements.


## **🛠 Applications**

- **Solar Energy Optimization**: Improves solar panel efficiency by ensuring proper alignment with the sun.
- **Educational Tool**: Teaches key concepts in solar tracking, light sensing, and motor control using Arduino.
- **DIY Projects**: Ideal for hobbyists or students interested in renewable energy systems.



## **🔮 Future Improvements**

- **Dual-Axis Tracking**: Add a second axis for vertical sun tracking.
- **Time-based Tracking**: Integrate a real-time clock (RTC) for cloudy days or nighttime.
- **Larger Panels**: Upgrade to a stepper motor for heavier solar panels.
- **Battery Integration**: Store energy to power the system during nighttime or low sunlight.



## **🛠️ Developers**

This project was developed by:
- **[Aaron Thomas Blessen](https://www.linkedin.com/in/aaron-thomas-blessen-390200214/)**
- **[AnandhaKrishnan J](https://github.com/Anandhu20)**
- **[Akshay Gopan](https://github.com/akshay-gopan)**
- **[Abin Sabu Philip](https://github.com/sree-234)**



## **💬 Feedback**

We value your feedback to help improve **RayTracer**. If you have any suggestions or face any issues, feel free to contact us!



## **📧 Contact Us**

For inquiries, please reach out to [aaronthomas232200@gmail.com](mailto:aaronthomas232200@gmail.com) or connect with me on [LinkedIn](https://www.linkedin.com/in/aaron-thomas-blessen-390200214/) or [Twitter](https://twitter.com/aaron_blessen).



Feel free to replace the placeholders with actual images for better visuals in your README!
