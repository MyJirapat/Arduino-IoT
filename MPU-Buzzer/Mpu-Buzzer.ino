#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
MPU6050 mpu; //ประกาศตัวแปร mpu
int16_t ax, ay, az;
int16_t gx, gy, gz;

long time1;
long previous = 0;
long current;
const int buzzerPin = D3;
void setup()
{
  Wire.begin();
  Serial.begin(38400);
  pinMode(buzzerPin, OUTPUT);
  Serial.println("Initialize MPU");
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  // แปลงค่าแกนให้เป็นมุม 0-180 องศา
  ax = map(ax, -18000, 18000, 0, 180);
  ay = map(ay, -18000, 18000, 0, 180);
  az = map(az, -18000, 18000, 0, 180);
  gx = map(gx, -18000, 18000, 0, 180);
  gy = map(gy, -18000, 18000, 0, 180);
  gz = map(gz, -18000, 18000, 0, 180);
  current = millis()/1000 - previous;
  Serial.print("Time : ");
  Serial.println(current);
  if (current > 40) {
    previous = millis()/1000;
    tone(buzzerPin, 500);
    delay(1000);
  }
  noTone(buzzerPin);
  delay(1000);
  Serial.print("Axyz \t");
  Serial.print(ax); Serial.print("\t");
  //Serial.print(ay); Serial.print("AAAAA\t");
  Serial.print(az); Serial.print("\t");
  Serial.print("Gxyz \t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);

  delay(50);
}