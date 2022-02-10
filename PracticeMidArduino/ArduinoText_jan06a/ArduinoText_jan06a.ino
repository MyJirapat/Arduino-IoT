
//Text Hello 

/*
 * cs = d4
Clk = d5
Din = d7
Gnd = G
Vcc = 3v
*/
#include <SPI.h>
#include "LedMatrix.h"

#define NUMBER_OF_DEVICES 1
#define CS_PIN 2
LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CS_PIN);

void setup(){
  ledMatrix.init();
  ledMatrix.setIntensity(1); // Brightness adjustment 0-15
  ledMatrix.setText("Hello World!!");
}

void loop() {
  ledMatrix.clear();
  ledMatrix.scrollTextLeft();
  ledMatrix.drawText();
  ledMatrix.commit();
  delay(200);
}


/* 1 switch
 const int kPinLed= D2;

void setup() {
  pinMode(kPinLed, OUTPUT);
  
 }
 
 void loop() {
  digitalWrite(kPinLed, HIGH);
  delay(500);
  digitalWrite(kPinLed, LOW);
  delay(500);
 }
 */


//2 switch 
//kPinLed = D0;
//kPinButton1 = D3 and G
//kPinButton2 = D4 and G
//Diod = G


/*const int kPinLed = D0;
const int kPinButton1 = D3;
const int kPinButton2 = D4;

void setup() {
  pinMode(kPinButton1, INPUT); 
  pinMode(kPinButton2, INPUT); 
  pinMode(kPinLed, OUTPUT); 
  digitalWrite(kPinButton1, HIGH); // turn on pull-up
  digitalWrite(kPinButton2, HIGH);
  Serial.begin(9600);

 }

 int ledBrightness = 0;

 void loop() {
  if (digitalRead(kPinButton1) == LOW) {
//    ledBrightness--;
      ledBrightness = 0;
    Serial.println(ledBrightness);
    
  } else if (digitalRead(kPinButton2) == LOW) {
//    ledBrightness++;
      ledBrightness = 255;
    Serial.println(ledBrightness);
  }

  ledBrightness = constrain(ledBrightness,0 ,255);
  analogWrite(kPinLed, ledBrightness);  
 }*/





// 2 switch
/*const int kPinLed = D0;
const int kPinButton1 = D3;
const int kPinButton2 = D4;

void setup() {
  pinMode(kPinButton1, INPUT); 
  pinMode(kPinButton2, INPUT); 
  pinMode(kPinLed, OUTPUT); 
  digitalWrite(kPinButton1, HIGH); // turn on pull-up
  digitalWrite(kPinButton2, HIGH);
  Serial.begin(9600);

 }

 int ledBrightness = 0;

 void loop() {
  if (digitalRead(kPinButton1) == LOW) {
//    ledBrightness--;
      ledBrightness = 0;
    Serial.println(ledBrightness);
    
  } else if (digitalRead(kPinButton2) == LOW) {
//    ledBrightness++;
      ledBrightness = 255;
    Serial.println(ledBrightness);
  }

  ledBrightness = constrain(ledBrightness,0 ,255);
  analogWrite(kPinLed, ledBrightness);  
 }*/



 /*
  * Ultrasonic
  - vcc= vv
  -Gnd=G
  -trig=D5
  -echo=D6
  * 
  * 
  * 
  // ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

//#define echoPin D2 // attach pin D2 Arduino to pin Echo of HC-SR04
//#define trigPin D3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPin D6
#define trigPin D5

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
  */



  /*
   * #define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
const int buzzer =  D6;
void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
       
}
void loop(){
  tone(buzzer, NOTE_C4, 500);
  delay(500);
  tone(buzzer, NOTE_D4, 500);
  delay(500);
  tone(buzzer, NOTE_E4, 500);
  delay(500);
  tone(buzzer, NOTE_F4, 500);
  delay(500);
  tone(buzzer, NOTE_G4, 500);
  delay(500);
  tone(buzzer, NOTE_A4, 500);
  delay(500);
  tone(buzzer, NOTE_B4, 500);
  delay(500);
  tone(buzzer, NOTE_C5, 500);
  delay(500);
}
  */
