#include <Servo.h> 

int servoPin = 3;

Servo Servo1;

char incomingBit;    // for incoming serial data

void setup() {

// We need to attach the servo to the used pin number 

// Servo1.attach(servoPin);

pinMode(servoPin, OUTPUT);      // sets the digital pin as output

Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps

}

void loop() {

if (Serial.available() > 0) {       // Serial.available(), which detects if serial port

 //  Serial.read() will read the incoming character and store it in 

    incomingBit = Serial.read();

    Serial.print("I received:  ");

    //if the value of incomingBit is ‘Y’, we need to turn the LED ‘on’, else we turn it ‘off’. So, 

    //in a nutshell,if detecting faces from a given image was successful, this will turn on the LED

            if(incomingBit == 'Y' || incomingBit == 'y') {

             // Make servo go to 0 degrees 

  Servo1.write(0); 

  delay(1000); 

 // Make servo go to 90 degrees 

   Servo1.write(90); 

 delay(1000); 

 // Make servo go to 180 degrees 

 Servo1.write(180); 

 delay(1000); 

 //exit(0);

            }

            else {

              digitalWrite(servoPin, LOW); 

            }

  }

}



