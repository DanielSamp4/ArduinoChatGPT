#ifndef ARDUINO_CHAT_GPT_H
#define ARDUINO_CHAT_GPT_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

class ChatGPT {
  public:
    // Constructor that takes an API key as input
    ChatGPT(const char* apiKey, const char* model= "gpt-3.5-turbo");
    
    // Method that sends a message to the GPT-3 API and returns a response
    String sendMessage(String message);
    
    // Method that connects to WiFi using SSID and password
    bool begin(const char* ssid, const char* password);
    
  private:
    // Private member variable that stores the API key
    const char* _apiKey;
    // Private member variable that stores the model 
    const char* _model;
    
    // Private member variable for HTTPClient instance
    HTTPClient _http;
    
    // Private method that sends a message to the GPT-3 API and returns the response
    String getResponse( String message);
};

#endif
