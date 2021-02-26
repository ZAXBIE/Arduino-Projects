/*
    Serial.readString() program to device control from serial command "on" / "off".
    Author: Nilesh Chaurasia
    http://elextutorial.com
*/
void setup() 
{
    Serial.begin(115200); // Set the baud rate to 9600
    pinMode(13,OUTPUT);
}
void loop() 
{
    String s1 = Serial.readString();// s1 is String type variable.
    Serial.print("Received Data => ");
    Serial.println(s1);//display same received Data back in serial monitor.
    
    if(s1.indexOf("relay1on")>=0)
    {
        digitalWrite(13,HIGH);
    }
    if(s1.indexOf("relay1off")>=0){
        digitalWrite(13,LOW);
    }
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

    if(s1.indexOf("relay7on")>=0)
    {
        digitalWrite(7,HIGH);
    }
    if(s1.indexOf("relay7off")>=0){
        digitalWrite(7,LOW);
    }

    if(s1.indexOf("relay8on")>=0)
    {
        digitalWrite(6,HIGH);
    }
    if(s1.indexOf("relay8off")>=0){
        digitalWrite(6,LOW);
    }

    if(s1.indexOf("relay9on")>=0)
    {
        digitalWrite(5,HIGH);
    }
    if(s1.indexOf("relay9off")>=0){
        digitalWrite(5,LOW);
    }

    if(s1.indexOf("relay10on")>=0)
    {
        digitalWrite(4,HIGH);
    }
    if(s1.indexOf("relay10off")>=0){
        digitalWrite(4,LOW);
    }
    delay(100);
}   
