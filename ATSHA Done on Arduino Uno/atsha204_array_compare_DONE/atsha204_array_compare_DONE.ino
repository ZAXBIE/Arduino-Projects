/* ATSHA204 Library Simple Example
   by: Jim Lindblom
   SparkFun Electronics
   date: November 8, 2012
   
   This code shows how to wake up and verify that an SHA204 is
   connected and operational. And how to obtain an SHA204's unique serial
   number, and send it a MAC challenge.
   
   The ATSHA204's SDA pin can be connected to any of the Arduino's digital pins.
   When constructing your atsha204Class, pass the constructor the pin you want to use.
   In this example we'll attach SDA to pin 7.
   
   The ATSHA204 can be powered between 3.3V and 5V.
*/
#include <sha204_library.h>
#include<EEPROM.h>
#include<string.h>
int checking=0;

const int sha204Pin = 7;

int flag=0,m=0;

atsha204Class sha204(sha204Pin);


byte wakeupExample()
{
  uint8_t response[SHA204_RSP_SIZE_MIN];
  byte returnValue;
  
  returnValue = sha204.sha204c_wakeup(&response[0]);
  for (int i=0; i<SHA204_RSP_SIZE_MIN; i++)
  {
    Serial.print(response[i],HEX);
    Serial.print(" ");
  }
  Serial.println();

  if((response[0]==4)&&(response[1]==17)&&(response[2]==51)&&(response[3]==67)){
    Serial.println("wake ok");
    m=3;
    }
    else Serial.println("chip not presant"),m=4;

  
  
  return returnValue;
}

byte serialNumberExample()
{
  uint8_t serialNumber[9];
  byte returnValue;
  uint8_t checkserial[9];
 
  returnValue = sha204.getSerialNumber(serialNumber);
  Serial.println("SHA SERIAL NO");
  for (int i=0; i<9; i++)
  {
    Serial.print(serialNumber[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  Serial.println("EPROM DATA ");
   for (int i=0; i<9; i++)
  {
  checkserial[i]= EEPROM.read(i);
  delay(20);
  Serial.print(checkserial[i], HEX);
  Serial.print(" ");
    }
    
  
  Serial.println();
  for (int i=0; i<9; i++)
  {
  if(checkserial[i]!=serialNumber[i])
   checking=1;
  }

  if(checking==1){
  Serial.println("BOOT FAIL");
  Serial.println();
    m=5;
    }
    else { Serial.println("BOOT OK");
           Serial.println();
           m=3;
           }
  
  
  return returnValue;
}


byte serialNumberwrite()
{
  uint8_t serialNumber[9];
  byte returnValue;
  uint8_t checkserial[9];
  int checking=0;
  
  
  returnValue = sha204.getSerialNumber(serialNumber);
  for (int i=0; i<9; i++)
  {
    Serial.print(serialNumber[i],HEX);
    Serial.print(" ");
  }
  Serial.println();

 //rakesh1
 
  if(flag==1)
  {
    for (int i=0; i<9; i++)
  {
  EEPROM.write(i,serialNumber[i]);
  delay(20);
  }
 Serial.println("Write OK");

 }
   else{Serial.println("Cannot Write Again");
           Serial.println();}
   
   for (int i=0; i<9; i++)
  {
  checkserial[i]= EEPROM.read(i);
  delay(20);
  Serial.print(checkserial[i],HEX);
  Serial.print(" ");
  }
  Serial.println();
  for (int i=0; i<9; i++)
  {
  if(checkserial[i]!=serialNumber[i])
   checking=1;
  }

  if(checking==1){
  Serial.println("BOOT FAIL");
    Serial.println(); }
    else { Serial.println("BOOT OK");
           Serial.println();}
  
  
  return returnValue;
}


byte macChallengeExample()
{
  uint8_t command[MAC_COUNT_LONG];
  uint8_t response[MAC_RSP_SIZE];

  const uint8_t challenge[MAC_CHALLENGE_SIZE] = {
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF,
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
  };

  uint8_t ret_code = sha204.sha204m_execute(SHA204_MAC, 0, 0, MAC_CHALLENGE_SIZE, 
    (uint8_t *) challenge, 0, NULL, 0, NULL, sizeof(command), &command[0], 
    sizeof(response), &response[0]);

  for (int i=0; i<SHA204_RSP_SIZE_MAX; i++)
  {
    Serial.print(response[i], HEX);
    Serial.print(' ');
  }
  Serial.println();
  
  return ret_code;
}


void setup()
{

  pinMode(A0, INPUT);    // sets the digital pin 7 as input
  //digitalWrite(A0, LOW);
  Serial.begin(9600);
  
  Serial.println("Sending a Wakup Command. Response should be:\r\n4 11 33 43:");
  Serial.println("Response is:");
  wakeupExample();
  Serial.println();
  Serial.println("Asking the SHA204's serial number. Response should be:");
  Serial.println("1 23 x x x x x x x EE");
  Serial.println("Response is:");
  serialNumberExample();
  Serial.println();
  Serial.println("Sending a MAC Challenge. Response should be:");
  Serial.println("23 6 67 0 4F 28 4D 6E 98 62 4 F4 60 A3 E8 75 8A 59 85 A6 79 96 C4 8A 88 46 43 4E B3 DB 58 A4 FB E5 73");
  Serial.println("Response is:");
  macChallengeExample();
}

void loop()
{

  if (digitalRead(A0)==HIGH)
  {
    flag=1;
    Serial.println("BUTTON HIGH");
    delay(100);
    wakeupExample();
    serialNumberwrite();
    }
    else flag=0;
  /*
  switch (m)
  {
case 0:

break;
  
case 1:
break;

    case 2:
break;

  case 3:
  
Serial.println("BOOT *OK* DO YOUR STUFF");
delay(100);
  
  
  break;
  case 4:
Serial.println("CHIP NOT PRESANT or DEAD");
delay(100);
    

    
 // break;
  
  case 5:
  
    Serial.println("BOOT FAIL");
    delay(100);
    
 if (digitalRead(A0)==HIGH)
  {
    flag=1;
    Serial.println("BUTTON HIGH");
    delay(100);
    wakeupExample();
    serialNumberwrite();
    }
    else flag=0;

    
  break;
  }*/
}
