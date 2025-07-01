#include <EEPROM.h>

int values[] = {23, 254, 255, 256, 257, 450, 800};
int addr = 0;
int arraySize = sizeof(values) / sizeof(values[0]);

void setup() {
  Serial.begin(9600);

  Serial.println("");
  Serial.println("");

  // EEPROM size is 1024 bytes on the ATmega328P
  Serial.print("Arduino EEPROM length: ");
  Serial.println(EEPROM.length());

  // Each EEPROM element is 1 byte
  Serial.print("Array length to write and read: ");
  Serial.println(arraySize);

  for (int index = 0; index < arraySize; index++) {
    EEPROM.write(addr, values[index] / 256);
    delay(10);
    addr++;

    Serial.print("Writing ");
    Serial.print(values[index]);
    Serial.print(" in address ");
    Serial.println(addr);
    EEPROM.write(addr, values[index] % 256);

    addr++;
  }

  EEPROM.write(addr, '\0');
  EEPROM.read(addr);

  Serial.println("");
  Serial.println("Begin reading back the array");

  int currentAddr = 0;
  int readInt;
  int parte1;
  int parte2;

  while (currentAddr < arraySize * 2) {
    Serial.print("Reading ");
    // readInt = EEPROM.read(currentAddr);
    parte1 = EEPROM.read(currentAddr);
    parte2 = EEPROM.read(currentAddr + 1);
    readInt = parte1 * 256 + parte2;
  
    Serial.print(readInt);
    Serial.print(" in address ");
    Serial.println(currentAddr);

    currentAddr = currentAddr + 2;
  }
}

void loop() {
}
