
#include "DHT.h"
#define DHTTYPE DHT11
#define dht_dpin D3
DHT dht(dht_dpin, DHTTYPE);

void setup(void) {
    dht.begin();
    Serial.begin(9600);
    Serial.println("Humidity and temperature\n\n");
    delay(700);
}
