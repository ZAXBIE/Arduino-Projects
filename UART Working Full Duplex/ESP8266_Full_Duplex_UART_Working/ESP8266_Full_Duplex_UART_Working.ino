//ESP8266 CODE
bool flag=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
if (flag==0)
{
  Serial.write("hellouno");
}
//Serial.write("Message from ESP8266");
String s1 = Serial.readString();// s1 is String type variable.
 Serial.setTimeout(100);
    //Serial.print("Received Data => ");
    Serial.println(s1);//display same received Data back in serial monitor.
    if (s1.indexOf("hello")>=0)//(s1=="hello")
    {
      flag=1;
      Serial.println("DONE ESP8266");
      delay(100);
    }
    else flag=0;
    
    delay(500);
}
