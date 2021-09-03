//receive input from transciever
//power motor for a gantry cycle

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
const int motorPin = 2;
int MotorSpeed = 40;


void setup() {
  // put your setup code here, to run once:
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (radio.available())
  {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.print(text);
    if (text == "STOP")
    {
      //motor set to speed of 0
      //analogWrite(motorPin,0);
      Serial.print("stop it");
      
    }

    if (text == "MOVE")
    {
      //MOVE MOTOR
      //analogWrite(motorPin, MotorSpeed);
      Serial.print("gogogo");
      //2.5 min
      delay(125000);
      //analogWrite(motorPin,-MotorSpeed);//negative to go other way
      //2.5 min
      delay(125000);
      //stop motor
      //analogWrite(motorPin,0);
    }
    
  }

}
