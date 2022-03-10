
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
MPU6050 mpu; //ประกาศตัวแปร mpu
int16_t ax, ay, az;
int16_t gx, gy, gz;

long time1;
long previous = 0;
long current;
long axis;
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
//
  axis = (ax + ay + az)/3;
  Serial.print("Axis : " + axis);

  if (axis > 100) {
    current = millis()/1000 - previous;
    if (current > 20) {
      previous = millis()/1000;
      tone(buzzerPin, 500);
      delay(1000);
    }
  } else {
    previous = millis()/1000;
  }
  delay(50);
//  current = millis()/1000 - previous;
//  Serial.print("Time : ");
//  Serial.println(current);
//  if (current > 40) {
//    previous = millis()/1000;
//    tone(buzzerPin, 500);
//    delay(1000);
//  }
//  noTone(buzzerPin);
//  delay(1000);
//  Serial.print("Axyz \t");
//  Serial.print(ax); Serial.print("\t");
//  Serial.print(ay); Serial.print("\t");
//  Serial.print(az); Serial.print("\t");
//  Serial.print("Gxyz \t");
//  Serial.print(gx); Serial.print("\t");
//  Serial.print(gy); Serial.print("\t");
//  Serial.println(gz);
//
//  delay(50);
  
}




































//
//long time1;
//long previous = 0;
//long current;
//const int buzzerPin = D3;
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  pinMode(buzzerPin, OUTPUT);
//}
//void loop() {
//  current = millis()/1000 - previous;
//  Serial.print("Time : ");
//  Serial.println(current);
//  if (current > 40) {
//    previous = millis()/1000;
//    tone(buzzerPin, 500);
//    delay(1000);
//  }
//  noTone(buzzerPin);
//  delay(1000);
//}
//

/*#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"
MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;
int valx , valy , valz;
char rd;
int prevVal;
//int ledR = 16 ;
//ledG = 14 ;
//int ledY = 12 ;
int pin11 = 1 , pin10 = 2 ;
int val1 , val2 ;
int valgy1 = 0 , valgy2 = 0;
void setup(){
  //pinMode(ledR, OUTPUT) ;
  //pinMode(ledG, OUTPUT) ;
  //pinMode(ledY, OUTPUT) ;
  Wire.begin();
  Serial.begin(38400);
  Serial.println("Initialize MPU");
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  valx = map(ax, -17000, 17000, 0, 179);
  valy = map(ay, -17000, 17000, 0, 179);
  valz = map(az, -17000, 17000, 0, 179);
  Serial.print("axis x = ") ;
  Serial.print(valx) ;
  Serial.print(" axis y = ") ;
  Serial.print(valy) ;
  Serial.print(" axis z = ") ;
  Serial.println(valz) ;
}*/


/*#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"
MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;
int valx , valy , valz;
char rd;
int prevVal;
//int ledR = 16 ;
//ledG = 14 ;
//int ledY = 12 ;
int pin11 = 1 , pin10 = 2 ;
int val1 , val2 ;
int valgy1 = 0 , valgy2 = 0;
void setup(){
  //pinMode(ledR, OUTPUT) ;
  //pinMode(ledG, OUTPUT) ;
  //pinMode(ledY, OUTPUT) ;
  Wire.begin();
  Serial.begin(38400);
  Serial.println("Initialize MPU");
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  /*valx = map(ax, -17000, 17000, 0, 179);
  valy = map(ay, -17000, 17000, 0, 179);
  valz = map(az, -17000, 17000, 0, 179);
  Serial.print("axis x = ") ;
  Serial.print(ax) ;
  Serial.print(" axis y = ") ;
  Serial.print(ay) ;
  Serial.print(" axis z = ") ;
  Serial.println(az) ;
}*/







/*#include "Wire.h"
 
const int MPU_addr=0x68; // I2C address of the MPU-6050
 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
 
void setup() {
Wire.begin();
Serial.begin(115200);
 
check_I2c(MPU_addr); // Check that there is an MPU
 
Wire.beginTransmission(MPU_addr);
Wire.write(0x6B); // PWR_MGMT_1 register
Wire.write(0); // set to zero (wakes up the MPU-6050)
Wire.endTransmission(true);
}
 
void loop() {
 
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true); // request a total of 14 registers
AcX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
AcY=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
AcZ=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
Tmp=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
GyX=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
GyY=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
GyZ=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
Serial.print("AcX = "); Serial.print(AcX);
Serial.print(" | AcY = "); Serial.print(AcY);
Serial.print(" | AcZ = "); Serial.print(AcZ);
Serial.print(" | Tmp = "); Serial.print(Tmp);
Serial.print(" | GyX = "); Serial.print(GyX);
Serial.print(" | GyY = "); Serial.print(GyY);
Serial.print(" | GyZ = "); Serial.println(GyZ);
 
delay(500); // Wait 0.5 seconds and scan again
}
 
byte check_I2c(byte addr){
// We are using the return value of
// the Write.endTransmisstion to see if
// a device did acknowledge to the address.
byte error;
Wire.beginTransmission(addr);
error = Wire.endTransmission();
 
if (error == 0)
{
Serial.print(" Device Found at 0x");
Serial.println(addr,HEX);
}
else
{
Serial.print(" No Device Found at 0x");
Serial.println(addr,HEX);
}
return error;
}*/



/*#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"
MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int valx , valy , valz;
char rd;
int prevVal;
int ledR = 16 ;
int ledG = 14 ;
int ledY = 12 ;
int pin11 = 5 , pin10 = 4 ;
int val1 , val2 ;
int valgy1 = 0 , valgy2 = 0;
void setup()
{
 pinMode(ledR, OUTPUT) ;
 pinMode(ledG, OUTPUT) ;
 pinMode(ledY, OUTPUT) ;
 Wire.begin();
 Serial.begin(38400);
 Serial.println("Initialize MPU");
 mpu.initialize();
 Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
}
void loop()
{
 mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 valx = map(ax, -17000, 17000, 0, 179);
 valy = map(ay, -17000, 17000, 0, 179);
 valz = map(az, -17000, 17000, 0, 179);
 Serial.print("axis x = ") ;
 Serial.print(valx) ;
 Serial.print(" axis y = ") ;
 Serial.print(valy) ;
 Serial.print(" axis z = ") ;
 Serial.println(valz) ;
 if ( valy > 150) {
   digitalWrite(ledR, HIGH);
   digitalWrite(ledG, LOW);
   digitalWrite(ledY, LOW);
 }
 if (valy  < 50) {
   digitalWrite(ledR, LOW);
   digitalWrite(ledG, HIGH);
   digitalWrite(ledY, LOW);
 }
 if (valx < 50) {
   digitalWrite(ledR, LOW);
   digitalWrite(ledG, LOW);
   digitalWrite(ledY, HIGH);
 }
 if (valz > 150) {
   digitalWrite(ledR, LOW);
   digitalWrite(ledG, LOW);
   digitalWrite(ledY, LOW);
 }

 delay(100);
}*/


/*//#include "Wire.h"
//#include "I2Cdev.h"
//#include "MPU6050.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
Adafruit_MPU6050 mpu; //ประกาศตัวแปร mpu
int16_t ax, ay, az;
int16_t gx, gy, gz;
void setup()
{
Wire.begin();
Serial.begin(38400); Serial.println("Initialize MPU");
//mpu.initialize();
//Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
}void loop()
{
mpu.getEvent(&ax, &ay, &az, &gx, &gy, &gz);
// แปลงค่าแกนให้เป็นมุม 0-180 องศา
ax = map(ax, -18000, 18000, 0, 180);
ay = map(ay, -18000, 18000, 0, 180);
az = map(az, -18000, 18000, 0, 180);
gx = map(gx, -18000, 18000, 0, 180);
gy = map(gy, -18000, 18000, 0, 180);
gz = map(gz, -18000, 18000, 0, 180);
Serial.print("Axyz \t");
Serial.print(ax); Serial.print("\t");
Serial.print(ay); Serial.print("\t");
Serial.print(az); Serial.print("\t");
Serial.print("Gxyz \t");
Serial.print(gx); Serial.print("\t");
Serial.print(gy); Serial.print("\t");
Serial.println(gz); delay(50);
}*/



// Basic OLED demo for accelerometer readings from Adafruit MPU6050

// ESP32 Guide: https://RandomNerdTutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/
// ESP8266 Guide: https://RandomNerdTutorials.com/esp8266-nodemcu-mpu-6050-accelerometer-gyroscope-arduino/
// Arduino Guide: https://RandomNerdTutorials.com/arduino-mpu-6050-accelerometer-gyroscope/
//
//#include <Adafruit_MPU6050.h>
//#include <Adafruit_SSD1306.h>
//#include <Adafruit_Sensor.h>
//
//Adafruit_MPU6050 mpu;
//Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);
//
//void setup() {
//  Serial.begin(38400);
//  // while (!Serial);
//  Serial.println("MPU6050 OLED demo");
//
//  if (!mpu.begin()) {
//    Serial.println("Sensor init failed");
//    while (1)
//      yield();
//  }
//  Serial.println("Found a MPU-6050 sensor");
//
//  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
//  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
//    Serial.println(F("SSD1306 allocation failed"));
//    for (;;)
//      ; // Don't proceed, loop forever
//  }
//  display.display();
//  delay(500); // Pause for 2 seconds
//  display.setTextSize(1);
//  display.setTextColor(WHITE);
//  display.setRotation(0);
//}
//
//void loop() {
//  sensors_event_t a, g, temp;
//  mpu.getEvent(&a, &g, &temp);
//
//  display.clearDisplay();
//  display.setCursor(0, 0);
//
//  Serial.print("Accelerometer ");
//  Serial.print("X: ");
//  Serial.print(a.acceleration.x, 1);
//  Serial.print(" m/s^2, ");
//  Serial.print("Y: ");
//  Serial.print(a.acceleration.y, 1);
//  Serial.print(" m/s^2, ");
//  Serial.print("Z: ");
//  Serial.print(a.acceleration.z, 1);
//  Serial.println(" m/s^2");
//
//  display.println("Accelerometer - m/s^2");
//  display.print(a.acceleration.x, 1);
//  display.print(", ");
//  display.print(a.acceleration.y, 1);
//  display.print(", ");
//  display.print(a.acceleration.z, 1);
//  display.println("");
//
//  Serial.print("Gyroscope ");
//  Serial.print("X: ");
//  Serial.print(g.gyro.x, 1);
//  Serial.print(" rps, ");
//  Serial.print("Y: ");
//  Serial.print(g.gyro.y, 1);
//  Serial.print(" rps, ");
//  Serial.print("Z: ");
//  Serial.print(g.gyro.z, 1);
//  Serial.println(" rps");
//
//  display.println("Gyroscope - rps");
//  display.print(g.gyro.x, 1);
//  display.print(", ");
//  display.print(g.gyro.y, 1);
//  display.print(", ");
//  display.print(g.gyro.z, 1);
//  display.println("");
//
//  display.display();
//  delay(100);
//}
