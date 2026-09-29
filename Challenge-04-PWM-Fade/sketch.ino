const int potPin = 34;
const int ledPin = 25;

void setup() {
  Serial.begin(115200);

  ledcAttach(ledPin, 5000, 8);
}

void loop() {
  int potValue = analogRead(potPin);

  int brightness = map(potValue, 0, 4095, 0, 255);

  ledcWrite(ledPin, brightness);

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Brightness: ");
  Serial.println(brightness);

  delay(10);
}
