![](images/ucl-logo.svg)
# Task 2 - Connecting the edge device to the internet

## 2.1 - Create a secret file to store your wifi network name and password

> [!NOTE]
> Sensitive information (WiFi passwords, API keys, AWS certificates, private keys) should never be stored directly in source code. Keeping these "secrets" in separate, non-tracked files prevents them from being accidentally committed to GitHub, shared publicly, or leaked to others. It also makes the project safer to distribute, easier to reuse across different environments, and simpler to rotate or update credentials without modifying the code itself.

1. In `firmware/include/`, create a `secret.h` file.
2. In this new file, add the following (replacing the placeholders):

    ```c++
    #define WIFI_SSID "your_wifi_name"
    #define WIFI_PASSWORD "your_wifi_password"
    ```
3. Save the file.

## 2.2 - Update the firmware to connect to your WiFi router

> [!TIP]
> Use the [documentation](https://docs.arduino.cc/libraries/wifinina/) of the WiFiNINA librairy to find out how to implement the following items.

1. In `firmware/platformio.ini`, make sure that `WiFiNINA` is in the (list of dependencies)[https://docs.platformio.org/en/latest/librarymanager/dependencies.html#declaring-dependencies].
2. In `firmware/src/main.cpp`'s header, import `secret.h`.
3. In  `firmware/src/main.cpp`'s `setup()` function, use `Wifi.begin()` and `Wifi.status()` to connect to your wifi network and print in the serial when connection has been established (examples in the documentation).
4. Build the code and fix any errors that may arrise.
5. Upload the code to the Arduino and open the Serial monitor to check that it connects to the Wifi.


## 2.3 – Upload the firmware and test Internet connectivity

At this stage, your board connects to your WiFi router.

That **does not automatically mean** it has Internet access.
It only means it joined the local network.

Now we verify that the device can reach an external server on the Internet (`httpbin`) by using [`client.connect()`](https://docs.arduino.cc/libraries/wifinina/#Client%20Class)

1. In `firmware/src/main.cpp`: 
    - Create a `WiFiClient` object named `wifiClient` in the header.
    - Implement ` handShakeProtocol()` so that if the client sucessfully connects to `httpbin.org`, blink the LED 3 times, stop the client. It if doesn't connect, blink the LED 9 times. Finally, set `resetReceived` to 0, and set the LED to HIGH.
4. Build the code and fix any errors that may arrise.
5. Upload the code to the Arduino and open the Serial monitor to check that it connects to the Wifi, then press the button and check that it sucessfully connects to `httpbin`.


## Solutions for task 2


`firmware/include/platformio.ini`
```ini
; PlatformIO Project Configuration File
;
;   Build options: build flags, source filter
;   Upload options: custom upload port, speed and extra flags
;   Library options: dependencies, extra library storages
;   Advanced options: extra scripting
;
; Please visit documentation for the other options and examples
; https://docs.platformio.org/page/projectconf.html

[env:mkrwifi1010]
platform = atmelsam
board = mkrwifi1010
framework = arduino
monitor_speed = 9600
lib_deps = 
    WiFiNINA
    ArduinoHttpClient
```

`firmware/src/main.cpp`
```c++
#include <Arduino.h>
#include <WiFiNINA.h>
#include "secrets.h"

WiFiClient client;


// Pin definitions
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  3;      // the number of the LED pin

// Status variables
int buttonState = 0;         // variable for reading the pushbutton status
int resetReceived = 0;       // variable for reading the reset status


// Function prototypes
void ledBlinkPatern(int pattern);
void handShakeProtocol();


// The setup function runs once when you press reset or power the board
void setup() {
    // initialize serial communication.
    Serial.begin(9600);
    // initialize the LED pin as an output.
    pinMode(ledPin, OUTPUT);
    // initialize the pushbutton pin as an input.
    pinMode(buttonPin, INPUT);
    // make sure the LED is on at the start
    digitalWrite(ledPin, HIGH); 
    
    delay(5000); // Wait for 5 second to ensure the LED is on before connecting to WiFi
    Serial.println("Connecting to WiFi...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    Serial.println("WiFi connected");

}

// The loop function runs over and over again forever
void loop() {

    buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH && resetReceived == 0) {
        Serial.println("Button pressed, waiting for reset...");
        resetReceived = 1;
        digitalWrite(ledPin, LOW);
    }

    if (resetReceived == 1) {
        handShakeProtocol();
        delay(1000); // Add a delay to prevent the loop from running too fast after the handshake protocol is complete
    }


}



void ledBlinkPatern(int pattern) {
    /*************************************************************
    * This function is used to show the status of the LED. 
    * 
    * The pattern indicates how many times the LED will blink. 
    * For example, if the pattern is 3, the LED will blink 3 times.
    **************************************************************/
    Serial.print("Status received:");
    Serial.println(pattern);
    for (int i = 0; i < pattern; i++) {
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
    }
}

void handShakeProtocol() {
    /*************************************************************
    * This function is used to implement the handshake protocol between pressing the button and the reset of the LED. 
    * 
    * When the button is pressed, the LED will turn on and stay on until the reset is received. 
    * Once the reset is received, the LED will turn off and the system will be ready for the next button press.
    * In task 1, the reset is triggered by waiting for an integer pattern to be sent through the serial monitor.
    * In task 2, the reset is triggered by connecting to an external server to check that the device is connected to the internet.
    * In task 3, the reset is triggered by waiting for an MQTT message that aknowledges that the device is connected to the MQTT broker.
    * In task 4, the reset is triggered by waiting for an MQTT message that sends a specific command to the device based on administrative rules defined in the cloud.
    **************************************************************/

    // TODO: YOUR CODE HERE
    Serial.println("Testing Internet connection...");

    if (client.connect("httpbin.org", 80)) {
        Serial.println("Internet connection successful.");
        ledBlinkPatern(3); // Blink the LED 3 times to indicate success
        client.stop(); // Close the connection after testing
    } else {
        Serial.println("Internet connection failed.");
        ledBlinkPatern(9); // Blink the LED 9 times to indicate failure
    }
    digitalWrite(ledPin, HIGH); // Turn the LED back on after the handshake protocol is complete
    resetReceived = 0; // Reset the handshake protocol for the next button press
}
```
