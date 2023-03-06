#include <ArduinoChatGPT.h>

const char* apiKey = "YOUR_API_KEY";
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

ChatGPT chat(apiKey);

void setup() {
  Serial.begin(115200);
  chat.begin(ssid, password);
}

void loop() {
  String message = "Hello, how are you?";
  String response = chat.sendMessage(message);
  Serial.println(response);
}