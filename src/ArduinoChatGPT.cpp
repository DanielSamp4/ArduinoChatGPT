#include "ArduinoChatGPT.h"

// Constructor that initializes the API key
ChatGPT::ChatGPT(const char* apiKey, const char* model= "gpt-3.5-turbo")
: _apiKey(apiKey), _model(model) {}

// Method that sends a message to the GPT-3 API and returns a response
String ChatGPT::sendMessage(String message) {
  return getResponse(message);
}

// Method that connects to WiFi using SSID and password
bool ChatGPT::begin(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  int retries = 0;
  Serial.println("Connecting to WiFi: " + String(ssid));
  
  // Retry connecting to WiFi up to 5 times
  while (WiFi.status() != WL_CONNECTED && retries < 5) {
    delay(500);
    Serial.println("Connecting to WiFi...");
    retries++;
  }
  
  // If successfully connected to WiFi, print message and return true
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Wifi Connected");
    return true;
  } 
  // If not connected to WiFi, print message and return false
  else {
    Serial.println("Wifi not connected");
    return false;
  }
}

// Private method that sends a message to the GPT-3 API and returns the response
String ChatGPT::getResponse(String message) {
  String response;
  
  // Begin HTTPClient and set headers
  _http.begin("_https://api.openai.com/v1/chat/completions");
  _http.addHeader("Content-Type", "application/json");
  _http.addHeader("Authorization", "Bearer " + String(_apiKey));
  
  // Send a POST request to the GPT-3 API with a JSON payload containing the message and model name
  int httpCode = _http.POST("{\"model\": \"" + String(_model) + "\", \"messages\": [{\"role\": \"user\", \"content\": \""+ message +"\"}] }");
  
  // If the response is OK (HTTP 200), parse the JSON response and extract the first message's content
  if (httpCode == 200) {
    DynamicJsonDocument doc(8192);
    deserializeJson(doc, _http.getString());
    response = doc["choices"][0]["message"]["content"].as<String>();
  }
  
  // End the HTTPClient and return the response
  _http.end();
  return response;
}
