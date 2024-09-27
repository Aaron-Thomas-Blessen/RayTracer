// Define LDR pin
const int ldrPin = A0;  // LDR connected to analog pin A0

void setup() {
  // Initialize serial communication for output
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the LDR
  int ldrValue = analogRead(ldrPin);

  // Map the analog value (0-1023) to a range (0-100%) for intensity
  int intensity = map(ldrValue, 0, 1023, 0, 100);

  // Print the raw LDR value and the intensity percentage to the Serial Monitor
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print("   Light Intensity: ");
  Serial.print(intensity);
  Serial.println("%");

  // Add a delay to avoid flooding the serial monitor
  delay(1000);
}
