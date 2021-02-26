/*
    Serial.readString() program to device control from serial command "on" / "off".
    Author: Nilesh Chaurasia
    http://elextutorial.com
*/
#include <string.h>
#define switch1 A0
#define switch2 A1
#define switch3 A2
#define switch4 A3
#define switch5 A4
#define switch6 A5
#define switch7 7
#define switch8 6
#define switch9 5
#define switch10 4
#define powersense 3
#define resetpin 2

bool light1=0,light2=0,light3=0,light4=0,light5=0,light6=0,light7=0,light8=0,light9=0,light10=0;
bool enablewrite=1;
int dummy=0,abc=0;
int timer1_counter;

//TIMER INTERRUPT START FROM HERE
ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  TCNT1 = timer1_counter;   // preload timer
 
 

 

}


void setup() 
{

  
noInterrupts();           // disable all interrupts
  

  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 65500;//65500;   // preload timer 65536-16MHz/256/50Hz
  timer1_counter = 64530;   // preload timer 65536-16MHz/256/2Hz
  
  //TCNT1 = timer1_counter;   // preload timer
  //TCCR1B |= (1 << CS12);    // 256 prescaler 
  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
  
    Serial.begin(115200); // Set the baud rate to 9600
    pinMode(13,OUTPUT);//OUTPUTS
    pinMode(12,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(switch1,INPUT); //INPUTS
    pinMode(switch2,INPUT);
    pinMode(switch3,INPUT);
    pinMode(switch4,INPUT);
    pinMode(switch5,INPUT);
    pinMode(switch6,INPUT);
    pinMode(switch7,INPUT);
    pinMode(switch8,INPUT);
    pinMode(switch9,INPUT);
    pinMode(switch10,INPUT);
    pinMode(powersense,INPUT);
    pinMode(resetpin,INPUT);
    digitalWrite(13,LOW);
    digitalWrite(switch1,LOW);
    
}
void loop() 
{

 
 String s1 = Serial.readString();// s1 is String type variable.
 Serial.setTimeout(100);
    Serial.print("Received Data => ");
    Serial.println(s1);//display same received Data back in serial monitor.
    
   
   if(s1.indexOf("relay1on")>=0)
    {  enablewrite=0;
      digitalWrite(13,HIGH);
     }
    else if((s1.indexOf("relay1off")>=0)&&(digitalRead(13)==HIGH))
 
   {
     enablewrite=0;
     digitalWrite(13,LOW);
     
   }
   else enablewrite=1;
    if(s1.indexOf("relay2on")>=0)
    {
        digitalWrite(12,HIGH);
    }
    if(s1.indexOf("relay2off")>=0){
        digitalWrite(12,LOW);
    }

    if(s1.indexOf("relay3on")>=0)
    {
        digitalWrite(11,HIGH);
    }
    if(s1.indexOf("relay3off")>=0){
        digitalWrite(11,LOW);
    }

    if(s1.indexOf("relay4on")>=0)
    {
        digitalWrite(10,HIGH);
    }
    if(s1.indexOf("relay4off")>=0){
        digitalWrite(10,LOW);
    }

    if(s1.indexOf("relay5on")>=0)
    {
        digitalWrite(9,HIGH);
    }
    if(s1.indexOf("relay5off")>=0){
        digitalWrite(9,LOW);
    }

    if(s1.indexOf("relay6on")>=0)
    {
        digitalWrite(8,HIGH);
    }
    if(s1.indexOf("relay6off")>=0){
        digitalWrite(8,LOW);
    }


   
// if(digitalRead(switch2)==HIGH){
//  digitalWrite(12,HIGH);
//  }
// else if(digitalRead(switch2)==LOW){
//  digitalWrite(12,LOW);
//  }
 // delay(100);



 
if ((digitalRead(switch1)==HIGH)&&(digitalRead(13)==LOW)&&(dummy==0))
    {   
        //s1="relay1on";
        
        dummy=1;
        digitalWrite(13,HIGH);
        if(enablewrite==1)
        Serial.write("light1on");
        delay(100);
    }
    

if ((digitalRead(switch1)==HIGH)&&(digitalRead(13)==HIGH))
    {    
        //s1="relay1off";
        dummy=0;
       // strcpy (s1,"relay1off");
        digitalWrite(13,LOW);
        if(enablewrite==1)
        Serial.write("light1off");
        delay(100);
    } 
     

    
   
}   
