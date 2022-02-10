



const int kPinButton1 = D3;
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
}

  
