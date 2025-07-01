#include <EEPROM.h>

int x[] = {0,2,4,6,8,10};
int addr = 0;
int arraySize = sizeof(x) / sizeof(x[0]);

void setup() {
  Serial.begin(115200);

  Serial.println("");
  Serial.println("");

  // EEPROM size is 1024 bytes on the ATmega328P
  Serial.print("Arduino EEPROM length: ");
  Serial.println(EEPROM.length());

  // Each EEPROM element is 1 byte
  Serial.print("Array length to write and read: ");
  Serial.println(arraySize);

  for (int index = 0; index < arraySize; index++) {
    int y = pow(values[index], 2) +5;

    EEPROM.write(addr, y);
    delay(10);

    Serial.print("Writing ");
    Serial.print(y);
    Serial.print(" in address ");
    Serial.println(addr);

    addr++;

   
  }
   EEPROM.write(addr, '\0');

  Serial.println("");
  Serial.println("Begin reading back the array: ");
  int currentAddr = 0;
  int readInt;

  while (currentAddr < arraySize) {
    Serial.print("Reading ");
    readInt = EEPROM.read(currentAddr);

    Serial.print(readInt);
    Serial.print(" in address ");
    Serial.println(currentAddr);

    currentAddr++;
  }
}

void loop() {}
