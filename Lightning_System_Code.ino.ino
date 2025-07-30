#include <WiFi.h>
#include <WebServer.h>


const char* ssid = "Denis";
const char* password = "Denis1641";

// Define LED pins
#define LED1 22
#define LED2 21
#define LED3 19

WebServer server(80);

// HTML content for dashboard
String htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>Rubangakene Denis Systems - Smart Lighting</title>
  <style>
    body { font-family: Arial; text-align: center; padding: 20px; background: #f4f4f4; }
    h2 { color: #333; }
    button { padding: 15px 30px; font-size: 16px; margin: 10px; }
    footer { margin-top: 30px; font-size: 14px; color: gray; }
  </style>
</head>
<body>
  <h2>Welcome to Rubangakene Denis Systems - Smart Light Control</h2>
  <div>
    <p>Control LED 1:</p>
    <a href="/on1"><button>ON</button></a>
    <a href="/off1"><button>OFF</button></a>
  </div>
  <div>
    <p>Control LED 2:</p>
    <a href="/on2"><button>ON</button></a>
    <a href="/off2"><button>OFF</button></a>
  </div>
  <div>
    <p>Control LED 3:</p>
    <a href="/on3"><button>ON</button></a>
    <a href="/off3"><button>OFF</button></a>
  </div>
  <footer>
    &copy; 2025 Rubangakene Denis Systems |
  </footer>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/html", htmlPage);
  });

  server.on("/on1", []() {
    digitalWrite(LED1, HIGH);
    server.send(200, "text/html", htmlPage);
  });
  server.on("/off1", []() {
    digitalWrite(LED1, LOW);
    server.send(200, "text/html", htmlPage);
  });

  server.on("/on2", []() {
    digitalWrite(LED2, HIGH);
    server.send(200, "text/html", htmlPage);
  });
  server.on("/off2", []() {
    digitalWrite(LED2, LOW);
    server.send(200, "text/html", htmlPage);
  });

  server.on("/on3", []() {
    digitalWrite(LED3, HIGH);
    server.send(200, "text/html", htmlPage);
  });
  server.on("/off3", []() {
    digitalWrite(LED3, LOW);
    server.send(200, "text/html", htmlPage);
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
