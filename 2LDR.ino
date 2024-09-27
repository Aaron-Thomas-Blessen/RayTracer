// Define LDR pins
const int ldr1Pin = A0;  // LDR 1 connected to analog pin A0
const int ldr2Pin = A1;  // LDR 2 connected to analog pin A1

void setup() {
  // Initialize serial communication for output
  Serial.begin(9600);
}

void loop() {
  // Read the intensity values from both LDRs
  int ldr1Value = analogRead(ldr1Pin);
  int ldr2Value = analogRead(ldr2Pin);

  // Print the intensity values to the Serial Monitor
  Serial.print("LDR 1 Intensity: ");
  Serial.print(ldr1Value);
  Serial.print("   LDR 2 Intensity: ");
  Serial.println(ldr2Value);

  // Add a delay to avoid flooding the serial monitor
  delay(1000);
}
