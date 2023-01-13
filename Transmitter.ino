#include <SoftwareSerial.h>


#define RX 10  // Arduino pin for RX, Module pin for TX
#define TX 11  // Arduino pin for TX, Module pin for RX

SoftwareSerial loraSerial(RX, TX);


#define M0 7   //Arduino pin for M0 as well as module.
#define M1 8   //Arduino pin for M1 as well as module.




void setup() {


 Serial.begin(9600);


 pinMode(M0, OUTPUT);
 pinMode(M1, OUTPUT);

 digitalWrite(M0, HIGH);  //For parameter configuration M0 is High.
 digitalWrite(M1, HIGH);  //For parameter configuration M1 is High.

 loraSerial.begin(9600);
 while (loraSerial.available() && loraSerial.read());

 //Send configuration commands to the module
 uint8_t config_struct[6]; //Edit thins array for your respective module and configuration.
 config_struct[0] = 0xAF; //Parameter configuration command for reading RSSI of the current data signal directly.
 config_struct[1] = 0xAF; //Parameter configuration command for reading RSSI of the current data signal directly.
 config_struct[2] = 0x73; //Parameter configuration command for reading RSSI of the current data signal directly.
 config_struct[3] = 0x00; //Parameter configuration command for reading RSSI of the current data signal directly.
 config_struct[4] = 0xAF; //Parameter configuration command for reading RSSI of the current data signal directly,
 config_struct[5] = 0xF3; //Parameter configuration command for reading RSSI of the current data signal directly.

 loraSerial.write(config_struct,6);
 delay(2000);

 Serial.println("Config Complete");
 digitalWrite(M0, LOW);  //For genaral mode M0 is LOW.
 digitalWrite(M1, LOW);  //For genaral mode M1 is LOW.
 loraSerial.begin(57600);

}

void loop() {
   

  loraSerial.print("Water Level:  "); //Input data for transmitting.
  loraSerial.println(sensorValue);   //Input data for transmitting.
  
 
  delay(1000);
    

}
