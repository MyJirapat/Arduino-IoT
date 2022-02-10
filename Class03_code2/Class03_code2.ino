
const int kPinButton1 = D3;
const int kPinButton2 = D2;
const int kPinLed = D4;

void setup ()
{
  pinMode (kPinButton1, INPUT);
  pinMode (kPinButton2, INPUT);
  pinMode (kPinLed, OUTPUT);
  digitalWrite(kPinButton1, HIGH);
  digitalWrite(kPinButton2, HIGH); 
  Serial.begin(9600) ;
}

int ledBrightness = 128;
void loop(){
  if (digitalRead(kPinButton1) == LOW){
    ledBrightness--;
    Serial.println (ledBrightness);
  }

  else if (digitalRead(kPinButton2) == LOW){
    ledBrightness++;
    Serial.println (ledBrightness);
  }
   ledBrightness = constrain(ledBrightness, 0, 255);
   analogWrite(kPinLed, ledBrightness);
   delay(20);

}


/*const int kPinButton1 = D3;
const int kPinLed = D4;

void setup ()
{
  pinMode (kPinButton1, INPUT);
  digitalWrite(kPinButton1, HIGH);
  pinMode(kPinLed, OUTPUT);
  
}

void loop(){
  if (digitalRead(kPinButton1) == LOW){
    digitalWrite(kPinLed, HIGH);
    
  }
  else
  {
    digitalWrite(kPinLed, LOW);
    
    }
}*/

  
