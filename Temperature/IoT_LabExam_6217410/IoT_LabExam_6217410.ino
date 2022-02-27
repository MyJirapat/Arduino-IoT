#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#define DHTTYPE DHT11
#define dht_dpin D3

DHT dht(dht_dpin, DHTTYPE);
LiquidCrystal_I2C lcd(0x3F, 16, 2);

float humidity = 0;
float temperature = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  Serial.println("Humidity and Temperature\n\n");
  delay(700);

  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();

  String hum =  "Humi: " + String(humidity);
  String temp = "Temp: " + String(temperature);

  lcd.setCursor(0, 0);
  lcd.print(hum);
  lcd.setCursor(0, 1);      
  lcd.print(temp);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  String hum =  "Light: " + String(humidity);
  String temp = "Intensity: " + String(temperature);
  lcd.setCursor(0, 0);
  lcd.print(hum);
  lcd.setCursor(0, 1);      
  lcd.print(temp);
 
  Serial.print("Current humidity = ");
  Serial.print(humidity);
  Serial.print("% ");
  Serial.print("temperature = ");
  Serial.print(temperature);
  Serial.println("c");
  delay(800);
}
