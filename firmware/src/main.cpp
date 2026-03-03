#include <Arduino.h>

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
}

// The loop function runs over and over again forever
void loop(){
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    
    if (buttonState == HIGH && resetReceived == 0) {
        // if the pushbutton is pressed and the reset has been received (or we are in the first loop), turn on the LED and wait for the reset.
        Serial.println("Button pressed, waiting for reset...");
        resetReceived = 1;
        digitalWrite(ledPin, LOW);
    } else if (resetReceived == 1){
        // if the reset has been not been received, run the handshake protocol to wait for the reset.
        handShakeProtocol();
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
    * In task 2, the reset is triggered by waiting for an API call to check that the device is connected to the internet.
    * In task 3, the reset is triggered by waiting for an MQTT message that aknowledges that the device is connected to the MQTT broker.
    * In task 4, the reset is triggered by waiting for an MQTT message that sends a specific command to the device based on administrative rules defined in the cloud.
    **************************************************************/

    // TODO: YOUR CODE HERE

}