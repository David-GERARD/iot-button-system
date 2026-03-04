#include <Arduino.h>

// Pin definitions
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  3;      // the number of the LED pin
// TODO: Add any additional pin definitions you need to implement the tasks

// Status variables
int buttonState = 0;         // variable for reading the pushbutton status
int resetReceived = 0;       // variable for reading the reset status
// TODO: Add any additional variables you need to implement the tasks

// Function prototypes 
void ledBlinkPatern(int pattern);
void handShakeProtocol();
// TODO: Add function prototypes for the functions you will implement to complete the tasks

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

    // TODO: YOUR CODE HERE (depends on the specific task you are working on)

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
    * When the button is pressed, the LED will turn off and stay off until the reset is received. 
    * Once the reset is received, the LED will blink based on a specific pattern, then turn on, and the system will be ready for the next button press.
    * In task 1, the reset is triggered by waiting for an integer pattern to be sent through the serial monitor.
    * In task 2, the reset is triggered by waiting to see if the device is connected to the internet.
    * In task 3, the reset is triggered by waiting to see if the device is connected to the MQTT broker, and posting a message to a specific topic to aknowledge that the device is connected.
    * In task 4, the reset is triggered by waiting for an MQTT message that returns the time in a specific timezone, to be used as the input for the LED blink pattern.
    **************************************************************/

    // TODO: YOUR CODE HERE

}

