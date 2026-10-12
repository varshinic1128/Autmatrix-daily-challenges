#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Initialize web server on port 80
WiFiServer server(80);

// Pin definitions
const int trigPin = 5;
const int echoPin = 18;

// Sound speed in cm/microsecond
#define SOUND_SPEED 0.034

long duration;
float distanceCm;

void setup() {
  Serial.begin(115200);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println(WiFi.localIP());
  
  server.begin();
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;

  // Listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if (c == '\n') {
          if (currentLine.length() == 0) {
            // HTTP headers start with a response code (200 OK) and content type
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // Self-refresh page every 1 second
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta http-equiv='refresh' content='1'>");
            client.println("<title>ESP32 HC-SR04 Dashboard</title>");
            client.println("<style>body{font-family:Arial;text-align:center;background:#f4f4f9;margin-top:50px;}");
            client.println("h1{color:#333;} .card{background:white;padding:20px;border-radius:10px;display:inline-block;box-shadow:0px 4px 8px rgba(0,0,0,0.1);}</style>");
            client.println("</head><body>");
            client.println("<div class='card'>");
            client.println("<h1>ESP32 Live Distance Dashboard</h1>");
            client.println("<p>Sensor: <strong>HC-SR04</strong></p>");
            client.println("<h2>Distance: <span style='color:#007BFF;'>" + String(distanceCm) + " cm</span></h2>");
            client.println("</div></body></html>");
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    client.stop();
  }
  delay(500);
}
