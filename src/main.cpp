#include <Arduino.h>
#define GPIO_BUILTIN 2
void setup() {
  Serial.begin(115200);
    delay(1000); // Даем время монитору открыться
  Serial.println("--- Проверка памяти ESP32-WROVER ---");
  Serial.printf("Свободно SRAM: %d байт\n", ESP.getFreeHeap());
  if (psramInit()) {
    Serial.println("PSRAM: Найдена и работает!");
    Serial.printf("Всего PSRAM:   %d байт\n", ESP.getPsramSize());
    Serial.printf("Свободно PSRAM: %d байт\n", ESP.getFreePsram());
  } else {
    Serial.println("PSRAM: НЕ НАЙДЕНА (проверь флаги в platformio.ini)");
  }
  Serial.println("------------------------------------");
  pinMode(GPIO_BUILTIN, OUTPUT);
}

void loop() {
  Serial.println("Hello, World!");
  digitalWrite(GPIO_BUILTIN, HIGH);
  delay(1000);  
  digitalWrite(GPIO_BUILTIN, LOW);
  delay(1000);
}
