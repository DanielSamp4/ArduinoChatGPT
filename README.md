# ArduinoChatGPT

Library for Arduino that allows users to chat with the GPT model from OpenAI.

## Description

`ArduinoChatGPT` is a library that enables Arduino users to communicate with OpenAI's GPT natural language model. The library uses OpenAI's API to send messages and receive responses from the GPT model.

## Installation

1. Download the ArduinoChatGPT repository.

2. Extract the .zip file to your Arduino libraries folder (usually located at `C:\Users\<your user>\Documents\Arduino\libraries` on Windows, or `~/Documents/Arduino/libraries` on macOS and Linux).

3. Open the Arduino IDE and go to **Sketch > Include Library > ArduinoChatGPT**. This will add the library to your project.

## Usage

1. In your Arduino sketch, include the `ArduinoChatGPT.h` header file:

   ```cpp
   #include <ArduinoChatGPT.h>
2. Create an instance of the ArduinoChatGPT class, passing in your OpenAI API key:
  ArduinoChatGPT chat("YOUR_OPENAI_API_KEY");

3. Send a message to the GPT model using the sendMessage() method:
  String response = chat.sendMessage("Hello, how are you?");


4. Use the response variable to retrieve the response from the GPT model.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Contributing
