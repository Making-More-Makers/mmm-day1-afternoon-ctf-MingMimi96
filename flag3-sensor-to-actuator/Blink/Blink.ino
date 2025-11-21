//Project - DJ Station
int pitchPin = A0; // Potentiometer 1 - analog pin A0
int beatPin = A1;  // Potentiometer 2 - analog pin A1
int piezo = 8;     // Piezo buzzer - digital pin 8
 
void setup() {
  Serial.begin(9600); // Initialize the serial port at 9600 baud
}
 
void loop() {
  int pitchVal = analogRead(pitchPin); 
// Read value from pitch potentiometer
  int beatVal = analogRead(beatPin);   
// Read value from beat potentiometer
 
  int frequency = map(pitchVal, 0, 1023, 0, 5000);  
// Map pitch value to frequency range 0-5000 Hz
  int duration = map(beatVal, 0, 1023, 100, 5000);  
// Map beat value to duration range 100-5000 ms
  
  // Print frequency and duration to the serial port
  Serial.print("Frequency: ");
  Serial.print(frequency);
  Serial.print(" Hz, Duration: ");
  Serial.print(duration);
  Serial.println(" ms");
 
  tone(piezo, frequency, duration); 
// Play the tone on the piezo buzzer
  int pauseBetweenNotes = duration * 1.30; 
// Calculate pause between notes
  delay(pauseBetweenNotes); // Wait for the pause duration
  noTone(piezo); // Stop the tone
}