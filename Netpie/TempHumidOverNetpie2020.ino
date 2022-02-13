#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"        

#define DHTTYPE DHT11   
#define dht_dpin D3

DHT dht(dht_dpin, DHTTYPE); 

const char* ssid = "Lenovo YB1-X90L";
const char* password = "numb2515";
const char* mqtt_server = "broker.netpie.io";
const int mqtt_port = 1883;
const char* mqtt_Client = "20643b25-196b-49bf-9153-aaa9d44c9fa6"; //from device in NetPie
const char* mqtt_username = "aWoMfJY4Q6y52jTjMgxx6scGqEeepRXD";
const char* mqtt_password = "t*z*UHum$Rugai_Z3aQl45IUANJ-Xocl";

char msg[100];
WiFiClient espClient;
PubSubClient client(espClient);

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting NETPIE2020 connection…");
    if (client.connect(mqtt_Client, mqtt_username, mqtt_password)) {
      Serial.println("NETPIE2020 connected");
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  dht.begin();
  Serial.begin(115200);
  Serial.println("Starting...");
  if (WiFi.begin(ssid, password)) {
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.print(".");
    }
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();         
  Serial.print("Current humidity = ");
  Serial.print(humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(temperature); 
  Serial.println("C  ");
  String place = "ABAC BANGNA";

  String data = "{\"data\": {\"temperature\":" + String(temperature) + ", \"humidity\":" + String(humidity) + ", \"place\": \"" +  String(place) + "\"}}";
  Serial.println(data);
  data.toCharArray(msg, (data.length() + 1));
  client.publish("@shadow/data/update", msg);
  delay(2000);
}
