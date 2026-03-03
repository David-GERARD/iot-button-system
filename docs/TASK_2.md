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
2. In `firmware/src/main.cpp`'s header:
    - Import `secret.h`.
    - Create a `WiFiClient` object named `wifiClient`.
3. In  `firmware/src/main.cpp`'s `setup()` function, use `Wifi.begin()` and `Wifi.status()` to connect to your wifi network and print in the serial when connection has been established (examples in the documentation).
4. Build the code and fix any errors that may arrise.
5. Upload the code to the Arduino and open the Serial monitor to check that it connects to the Wifi.


## 2.3 – Upload the firmware and test Internet connectivity

At this stage, your board connects to your WiFi router.

That **does not automatically mean** it has Internet access.
It only means it joined the local network.

Now we verify that the device can reach an external server on the Internet by performing a simple HTTP request to [httpbin.org](https://httpbin.org/).

1. In `firmware/platformio.ini`, make sure that `ArduinoHttpClient` is in the (list of dependencies)[https://docs.platformio.org/en/latest/librarymanager/dependencies.html#declaring-dependencies].
2. In `firmware/src/main.cpp`'s header:
    - Import `ArduinoHttpClient.h`.
    - Create a `WiFiClient` object named `wifiClient`.

TODO: finish

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

`firmware/src/main.cpp` [header]
```c++
#include <Arduino.h>
#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>
#include "secrets.h"

WiFiClient wifiClient;
```

`firmware/src/main.cpp` [setup()]
```c++
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


    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    Serial.println("WiFi connected");
}
```