
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

void recieveStructure(byte *structurePointer, int structureLength)
{
  if(SerialPort.available() < sizeof(myData)) return;
  SerialPort.readBytes(structurePointer, structureLength);
//    Serial.readBytes(structurePointer, structureLength);
//    Serial.println("Received");
}
float countSend;

// char macStr[18];
//// Copies the sender mac address to a string  
//  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
//           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
//  Serial.print(macStr);


void setup()
{
  Serial.begin(115200);
  SerialPort.begin(115200);
//  SerialPort.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);   // Setup Serial Monitor
  delay(10);
   
  recieveStructure((byte*)&myData, sizeof(myData));
  
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

//  myData.LG   += 1;
//  myData.PG   += 1;
//  myData.LP   += 1;
//  myData.PP   += 1;
//  myData.STOP += 1;
//  myData.ZX   += 1;
//  myData.FOG  += 1;
//  myData.BATT += 1;
  countSend = millis();
  }

  
}
