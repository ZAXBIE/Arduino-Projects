/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
*/

#include <Arduino.h>
#ifdef ESP32
  #include <WiFi.h>
  #define RF_RECEIVER 13
  #define RELAY_PIN_1 16
  #define RELAY_PIN_2 17
#else
  #include <ESP8266WiFi.h>
  #define RF_RECEIVER 5
  #define RELAY_PIN_1 4
  #define RELAY_PIN_2 14
#endif
#include "fauxmoESP.h"

#include <RCSwitch.h>

#define SERIAL_BAUDRATE 115200

#define WIFI_SSID "ACT42463031"
#define WIFI_PASS "destiny42463031"

#define LAMP_1 "AC 1"
#define LAMP_2 "AC 2"
//#define LAMP_3 "lamp three"
//#define LAMP_4 "lamp four"
//#define LAMP_5 "lamp five"
//#define LAMP_6 "lamp six"
//#define LAMP_7 "lamp seven"
//#define LAMP_8 "lamp eight"
//#define LAMP_9 "lamp nine"
//#define LAMP_10 "lamp ten"
//#define LAMP_11 "lamp eleven"
//#define LAMP_12 "lamp twelve"
//#define LAMP_13 "lamp thirteen"
//#define LAMP_14 "lamp twelve"
//#define LAMP_15 "lamp a"
//#define LAMP_16 "lamp b"
//#define LAMP_17 "lamp c"
//#define LAMP_18 "lamp d"
//#define LAMP_19 "lamp e"
//#define LAMP_20 "lamp f"
//#define LAMP_21 "lamp g"
//#define LAMP_22 "lamp h"
//#define LAMP_23 "lamp i"
//#define LAMP_24 "lamp j"
//#define LAMP_25 "lamp k"
//#define LAMP_26 "lamp l"
//#define LAMP_27 "lamp m"
//#define LAMP_28 "lamp n"
//#define LAMP_29 "lamp o"
//#define LAMP_30 "lamp p"
//#define LAMP_31 "lamp q"
//#define LAMP_32 "lamp r"
//#define LAMP_33 "lamp s"
//#define LAMP_34 "lamp t"
//#define LAMP_35 "lamp u"
//#define LAMP_36 "lamp v"
//#define LAMP_37 "lamp w"
//#define LAMP_38 "lamp x"
//#define LAMP_39 "lamp y"
//#define LAMP_40 "lamp z"
//#define LAMP_41 "lamp za"

fauxmoESP fauxmo;

RCSwitch mySwitch = RCSwitch();

// Wi-Fi Connection
void wifiSetup() {
  // Set WIFI module to STA mode
  WiFi.mode(WIFI_STA);

  // Connect
  Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // Wait
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  // Connected!
  Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}

void setup() {
  // Init serial port and clean garbage
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println();

  // Wi-Fi connection
  wifiSetup();

  // LED
  pinMode(RELAY_PIN_1, OUTPUT);
  digitalWrite(RELAY_PIN_1, LOW);

  pinMode(RELAY_PIN_2, OUTPUT);
  digitalWrite(RELAY_PIN_2, LOW);
  
  mySwitch.enableReceive(RF_RECEIVER);  // Receiver on interrupt 0 => that is pin #2

  // By default, fauxmoESP creates it's own webserver on the defined port
  // The TCP port must be 80 for gen3 devices (default is 1901)
  // This has to be done before the call to enable()
  fauxmo.createServer(true); // not needed, this is the default value
  fauxmo.setPort(80); // This is required for gen3 devices

  // You have to call enable(true) once you have a WiFi connection
  // You can enable or disable the library at any moment
  // Disabling it will prevent the devices from being discovered and switched
  fauxmo.enable(true);
  // You can use different ways to invoke alexa to modify the devices state:
  // "Alexa, turn lamp two on"

  // Add virtual devices
  fauxmo.addDevice(LAMP_1);
  fauxmo.addDevice(LAMP_2);
//  fauxmo.addDevice(LAMP_3);
//  fauxmo.addDevice(LAMP_4);
//  fauxmo.addDevice(LAMP_5);
//  fauxmo.addDevice(LAMP_6);
//  fauxmo.addDevice(LAMP_7);
//  fauxmo.addDevice(LAMP_8);
//  fauxmo.addDevice(LAMP_9);
//  fauxmo.addDevice(LAMP_10);
//  fauxmo.addDevice(LAMP_11);
//  fauxmo.addDevice(LAMP_12);
//  fauxmo.addDevice(LAMP_13);
//  fauxmo.addDevice(LAMP_14);
//  fauxmo.addDevice(LAMP_15);
//  fauxmo.addDevice(LAMP_16);
//  fauxmo.addDevice(LAMP_17);
//  fauxmo.addDevice(LAMP_18);
//  fauxmo.addDevice(LAMP_19);
//  fauxmo.addDevice(LAMP_20);
//  fauxmo.addDevice(LAMP_21);//works till 21 Devices
//  fauxmo.addDevice(LAMP_22);
//  fauxmo.addDevice(LAMP_23);
//  fauxmo.addDevice(LAMP_24);
//  fauxmo.addDevice(LAMP_25);
//  fauxmo.addDevice(LAMP_26);
//  fauxmo.addDevice(LAMP_27);
//  fauxmo.addDevice(LAMP_28);
//  fauxmo.addDevice(LAMP_29);
//  fauxmo.addDevice(LAMP_30);
//  fauxmo.addDevice(LAMP_31);
//  fauxmo.addDevice(LAMP_32);
//  fauxmo.addDevice(LAMP_33);
//  fauxmo.addDevice(LAMP_34);
//  fauxmo.addDevice(LAMP_35);
//  fauxmo.addDevice(LAMP_36);
//  fauxmo.addDevice(LAMP_37);
//  fauxmo.addDevice(LAMP_38);
//  fauxmo.addDevice(LAMP_39);
//  fauxmo.addDevice(LAMP_40);
//  fauxmo.addDevice(LAMP_41);

  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
    // Callback when a command from Alexa is received. 
    // You can use device_id or device_name to choose the element to perform an action onto (relay, LED,...)
    // State is a boolean (ON/OFF) and value a number from 0 to 255 (if you say "set kitchen light to 50%" you will receive a 128 here).
    // Just remember not to delay too much here, this is a callback, exit as soon as possible.
    // If you have to do something more involved here set a flag and process it in your main loop.
        
    Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);
    if ( (strcmp(device_name, LAMP_1) == 0) ) {
      // this just sets a variable that the main loop() does something about
      Serial.println("RELAY 1 switched by Alexa");
      //digitalWrite(RELAY_PIN_1, !digitalRead(RELAY_PIN_1));
      if (state) {
        digitalWrite(RELAY_PIN_1, HIGH);
      } else {
        digitalWrite(RELAY_PIN_1, LOW);
      }
    }
    if ( (strcmp(device_name, LAMP_2) == 0) ) {
      // this just sets a variable that the main loop() does something about
      Serial.println("RELAY 2 switched by Alexa");
      if (state) {
        digitalWrite(RELAY_PIN_2, HIGH);
      } else {
        digitalWrite(RELAY_PIN_2, LOW);
      }
    }
  });

}

void loop() {
  // fauxmoESP uses an async TCP server but a sync UDP server
  // Therefore, we have to manually poll for UDP packets
  fauxmo.handle();

  static unsigned long last = millis();
  if (millis() - last > 5000) {
    last = millis();
    Serial.printf("[MAIN] Free heap: %d bytes\n", ESP.getFreeHeap());
  }
    
  if (mySwitch.available()) {    
  /*Serial.print("Received ");
    Serial.print( mySwitch.getReceivedValue() );
    Serial.print(" / ");
    Serial.print( mySwitch.getReceivedBitlength() );
    Serial.print("bit ");
    Serial.print("Protocol: ");
    Serial.println( mySwitch.getReceivedProtocol() );*/
    if (mySwitch.getReceivedValue()==6819768) {
      digitalWrite(RELAY_PIN_1, !digitalRead(RELAY_PIN_1));
    }
    if (mySwitch.getReceivedValue()==9463928) {
      digitalWrite(RELAY_PIN_2, !digitalRead(RELAY_PIN_2));     
    }
    delay(600);
    mySwitch.resetAvailable();
  }
}
