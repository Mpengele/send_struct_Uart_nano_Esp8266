
#include <HardwareSerial.h>
//HardwareSerial SerialPort(1); // use UART1
#include <SoftwareSerial.h>
//uint8_t RX_PIN = 13; //D7
//uint8_t TX_PIN = 15; //D8
int RX_PIN = 13;
int TX_PIN = 15;
SoftwareSerial SerialPort(13,15); // SoftwareSerial(rxPin, txPin)




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
}struct_Data;
 
struct_Data myData;
struct_Data myDataSent;

typedef struct struct_In
{
 uint8_t count;
 uint8_t res;
}struct_In;

struct_In inData;

void sendStructure(byte *structurePointer, int structureLength)
{
      SerialPort.write(structurePointer, structureLength);
}
void recieveStructure(byte *structurePointer, int structureLength)
{
  if(SerialPort.available() < sizeof(myData)) return;
  SerialPort.readBytes(structurePointer, structureLength);
}
float countSend;

void setup()
{
  Serial.begin(115200);
  SerialPort.begin(115200);
  delay(10);
   
  countSend = millis();
  delay(100);
}

void loop() 
{
  recieveStructure((byte*)&myData, sizeof(myData));
  if((millis()-countSend)/1000 > 3){
  Serial.print (myData.LG);
  Serial.print(" ");
  Serial.print (myData.PG);
  Serial.print(" ");
  Serial.print (myData.LP);
  Serial.print(" ");
  Serial.print (myData.PP);
  Serial.print(" ");
  Serial.print (myData.STOP);
  Serial.print(" ");
  Serial.print (myData.ZX);
  Serial.print(" ");
  Serial.print (myData.FOG);
  Serial.print(" ");
  Serial.println (myData.BATT);

//  SerialPort.print (myData.LG);
//  SerialPort.print(" ");
//  SerialPort.print (myData.PG);
//  SerialPort.print(" ");
//  SerialPort.print (myData.LP);
//  SerialPort.print(" ");
//  SerialPort.print (myData.PP);
//  SerialPort.print(" ");
//  SerialPort.print (myData.STOP);
//  SerialPort.print(" ");
//  SerialPort.print (myData.ZX);
//  SerialPort.print(" ");
//  SerialPort.print (myData.FOG);
//  SerialPort.print(" ");
//  SerialPort.println (myData.BATT);



//void *memcpy(void *to, const void *from, size_t numBytes);  // definition of  memcpy func
//  memcpy(&myDataSent, &myData, sizeof(myDataSent));
//  
//  myDataSent.LG   += 1;
//  myDataSent.PG   += 1;
//  myDataSent.LP   += 1;
//  myDataSent.PP   += 1;
//  myDataSent.STOP += 1;
//  myDataSent.ZX   += 1;
//  myDataSent.FOG  += 1;
//  myDataSent.BATT += 1;

  inData.count = 5;
  inData.res = 20;
  sendStructure((byte*)&inData, sizeof(inData));
  Serial.print ("sizeof(inData) : ");
  Serial.println (sizeof(inData));
  
  countSend = millis();
  }

}
