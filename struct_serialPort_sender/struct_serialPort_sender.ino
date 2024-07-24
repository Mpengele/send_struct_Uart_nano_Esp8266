
#include <HardwareSerial.h>
#include <SoftwareSerial.h>
#define RX_PIN A3
#define TX_PIN A4
SoftwareSerial SerialPort(RX_PIN, TX_PIN); // SoftwareSerial(rxPin, txPin)

typedef struct struct_Data
{
  float LG;    // Переменная для хранения значения параметра LG
  float PG;    // Переменная для хранения значения параметра PG
  float LP;    // Переменная для хранения значения параметра LP
  float PP;    // Переменная для хранения значения параметра PP
  float STOP;  // Переменная для хранения значения параметра STOP
  float ZX;    // Переменная для хранения значения параметра ZX
  float FOG;   // Переменная для хранения значения параметра FOG
  float BATT;
} struct_Data;

struct_Data myData;

void sendStructure(byte *structurePointer, int structureLength)
{
      SerialPort.write(structurePointer, structureLength);
//  Serial.write(structurePointer, structureLength);
}


float countSend;
void setup()
{
  Serial.begin(115200);
  SerialPort.begin(115200); // GPS---> arduino at 9600 baud
  countSend = millis();


  myData.LG   = 1;
  myData.PG   = 2;
  myData.LP   = 3;
  myData.PP   = 4;
  myData.STOP = 5;
  myData.ZX   = 6;
  myData.FOG  = 7;
  myData.BATT = 8;
  
  delay(100);

}

void loop()
{

  if ((millis() - countSend) / 1000 > 5) {
    sendStructure((byte*)&myData, sizeof(myData));
    delay(500);
    countSend = millis();

    myData.LG   += 1;
    myData.PG   += 1;
    myData.LP   += 1;
    myData.PP   += 1;
    myData.STOP += 1;
    myData.ZX   += 1;
    myData.FOG  += 1;
    myData.BATT += 1;
  }




  delay(1000);
}
