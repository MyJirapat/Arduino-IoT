#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#define BLYNK_TEMPLATE_ID           "TMPLwDtgMC_F"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "RSSzrfbuNRvwc4MeUeaDRYxPJWGKbBP_"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iPhone";
char pass[] = "Jirapatmy";

const int MPU_addr=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
 
int minVal=265;
int maxVal=402;
 
double x;
double y;
double z;

MPU6050 mpu; //ประกาศตัวแปร mpu
int16_t ax, ay, az;
int16_t gx, gy, gz;

long time1;
long previous = 0;
long current;
const int buzzerPin = D0;
void setup()
{
  Wire.begin();
  Serial.begin(38400);
  Blynk.begin(auth, ssid, pass);
  pinMode(buzzerPin, OUTPUT);
  Serial.println("Initialize MPU");
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
}

void loop(){
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  //แปลงค่ามุม 180 
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
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print("Gxyz \t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);

  Blynk.virtualWrite(V2, x);
  Blynk.virtualWrite(V3, y);
  Blynk.virtualWrite(V4, z);

  delay(50);
}
