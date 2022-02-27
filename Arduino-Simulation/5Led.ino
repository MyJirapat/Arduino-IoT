

const int ledPin4 = 1;
const int ledPin6 = 4;
const int ledPin7 = 3;
const int ledPin8 = 5;
const int buzzPin = 2;

// Variables will change:
int ledState = LOW;
int ledState2 = LOW;
int ledState3 = LOW;
int ledState4 = LOW;
int ledState5 = LOW;
int ledState6 = LOW;
int ledState7 = LOW;
int ledState8 = LOW;
int buzzState = LOW;// ledState used to set the LED
long previousMillis = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;
long previousMillis4 = 0;
long previousMillis5 = 0;
long previousMillis6 = 0;
long previousMillis7 = 0;
long previousMillis8 = 0;
long previousBuzzMillis = 0;// will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 10000;
long interval2 = 9000;
long interval3 = 8000;
long interval4 = 7000;
long interval5 = 6000;
long interval6 = 5000;
long interval7 = 4000;
long interval8 = 3000;
long intervalBuzz = 150;// interval at which to blink (milliseconds)

void setup() {
  pinMode(ledPin4, OUTPUT); 
  //pinMode(ledPin5, OUTPUT); 
  //pinMode(ledPin6, OUTPUT); 
  pinMode(ledPin7, OUTPUT); 
  pinMode(ledPin8, OUTPUT); 
  pinMode(buzzPin, OUTPUT);

}

void loop()
{
  
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > random(200, interval)) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
   // digitalWrite(ledPin, ledState);
  }

  unsigned long currentMillis4 = millis();
  if(currentMillis4 - previousMillis4 > random(200, interval4)) {
    // save the last time you blinked the LED 
    previousMillis4 = currentMillis4;   

    // if the LED is off turn it on and vice-versa:
    if (ledState4 == LOW)
      ledState4 = HIGH;
    else
      ledState4 = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin4, ledState4);
  }

  unsigned long currentMillis5 = millis();
  if(currentMillis5 - previousMillis5 > random(200, interval5)) {
    // save the last time you blinked the LED 
    previousMillis5 = currentMillis5;   

    // if the LED is off turn it on and vice-versa:
    if (ledState5 == LOW)
      ledState5 = HIGH;
    else
      ledState5 = LOW;

    // set the LED with the ledState of the variable:
    //digitalWrite(ledPin5, ledState5);
  }



  unsigned long currentMillis6 = millis();
  if(currentMillis6 - previousMillis6 > random(200, interval6)) {
    // save the last time you blinked the LED 
    previousMillis6 = currentMillis6;   

    // if the LED is off turn it on and vice-versa:
    if (ledState6 == LOW)
      ledState6 = HIGH;
    else
      ledState6 = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin6, ledState6);
  }



  unsigned long currentMillis7 = millis();
  if(currentMillis7 - previousMillis7 > random(200, interval7)) {
    // save the last time you blinked the LED 
    previousMillis7 = currentMillis7;   

    // if the LED is off turn it on and vice-versa:
    if (ledState7 == LOW)
      ledState7 = HIGH;
    else
      ledState7 = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin7, ledState7);
  }


  unsigned long currentBuzzMillis = millis(); 
  if(currentBuzzMillis - previousBuzzMillis > intervalBuzz) {
    // save the last time you blinked the LED 
    previousBuzzMillis = currentBuzzMillis;   

    // if the LED is off turn it on and vice-versa:
    if (buzzState == LOW) {
      buzzState = HIGH;
      intervalBuzz = 10000;
    }
    else {
      buzzState = LOW;
      intervalBuzz = 150;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(buzzPin, buzzState);
  }

}