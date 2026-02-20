#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Temperature and Humidity Monitoring using DHT11
 * @author YOUR_NAME
 * @date YYYY-MM-DD
 *
 * @details
 * This program reads environmental data from the DHT11 sensor
 * and displays temperature and humidity values on Serial Monitor.
 * Students must complete the TODO sections.
 */

#if defined(__has_include)
  #if __has_include(<DHT.h>)
    #include <DHT.h>
  #else
    // Minimal stub so the sketch compiles when the DHT library isn't available.
    #ifndef DHT_H_STUB
    #define DHT_H_STUB
    #ifndef DHT11
    #define DHT11 11
    #endif
    class DHT {
    public:
      DHT(uint8_t /*pin*/, uint8_t /*type*/) {}
      void begin() {}
      float readHumidity() { return NAN; }
      float readTemperature() { return NAN; }
    };
    #endif
  #endif
#else
  #include <DHT.h>
#endif

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 sensor initialization complete.");
}

void loop() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");

    delay(2000);
}
