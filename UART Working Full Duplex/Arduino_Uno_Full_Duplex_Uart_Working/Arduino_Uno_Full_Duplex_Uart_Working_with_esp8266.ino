//ARDUINO UNO CODE
bool flag=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
if (flag==0)
{
Serial.write("hello");
}
//Serial.println();
//Serial.println("RAKESH");
//Serial.write("Message from Arduino UNO");

String s1 = Serial.readString();// s1 is String type variable.
 Serial.setTimeout(100);
    //Serial.println("Received Data => ");
    Serial.println(s1);//display same received Data back in serial monitor.
    if (s1.indexOf("hellouno")>=0)
    {
      flag=1;
      Serial.println("DONE UNO");
      delay(100);
    }
else flag=0;

delay(500);

}
