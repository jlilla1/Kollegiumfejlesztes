/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int rbuttonPin = 3;     // the number of the pushbutton pin
const int rledPin =  12;      // the number of the LED pin
const int gbuttonPin = 2;     // the number of the pushbutton pin
const int gledPin =  13;
const int bbuttonPin = 4;     // the number of the pushbutton pin
const int bledPin =  11;
const int ybuttonPin = 5;     // the number of the pushbutton pin
const int yledPin =  10;
// variables will change:
int buttonState = 0;   
// variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(rledPin, OUTPUT);
  pinMode(gledPin, OUTPUT);
  pinMode(bledPin, OUTPUT);
  pinMode(yledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(rbuttonPin, INPUT);
  pinMode(gbuttonPin, INPUT);
  pinMode(bbuttonPin, INPUT);
  pinMode(bbuttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(rbuttonPin); 
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(rledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(rledPin, LOW);
  }
  
  buttonState = digitalRead(gbuttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(gledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(gledPin, LOW);
  }
  
  buttonState = digitalRead(bbuttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(bledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(bledPin, LOW);
  }

  buttonState = digitalRead(ybuttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(yledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(yledPin, LOW);
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  
}
