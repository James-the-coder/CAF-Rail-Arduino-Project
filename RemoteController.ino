//button one controls on/off
//button two controls when the gantry starts moving
//button three controls the emergency stop
#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <LiquidCrystal_I2C.h>
#include <RF24_config.h>
#include <Wire.h>

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2);

RF24 radio(9, 10); // CE, CSN         
const byte address[6] = "00001";
const int button1Pin = 3;
const int button2Pin = 4;
const int button3Pin = 5;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  //setting up the pins to take input/output
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  pinMode(button1Pin, INPUT); //initiate the buttons
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  radio.stopListening();
  lcd.init();             
  lcd.backlight();

}

void loop() {
  //reading the state of the buttons (whether they are pressed or not pressed)
  buttonState1 = digitalRead(button1Pin);
  buttonState2 = digitalRead(button2Pin);
  buttonState3 = digitalRead(button3Pin);

  if (buttonState1 == HIGH)
  {
    //Turn Remote OFF SO NOTHING NEEDS TO HAPPEN HERE
    Serial.print("button 1");
    Serial.print("\n");
  }
  if (buttonState3 == HIGH)
  {
    //use wireless module to communicate to gantry to tell it to do an emergency stop
    Serial.print("button 3");
    Serial.print("\n");
    char text[] = "STOP";
    radio.write(&text, sizeof(text)); //Sending the message to receiver
    lcd.setCursor(0, 0);         // move cursor to   (0, 0)
    lcd.print("Emergency");        // print message at (0, 0)
    delay(1000);
    lcd.clear();
  }
  if (buttonState2 == HIGH)
  {
    //use wireless module to communicate to gantry to tell it to move
    Serial.print("Button 2");
    Serial.print("\n");
    char text[] = "MOVE";
    radio.write(&text, sizeof(text)); //Sending the message to receiver
    lcd.setCursor(0, 0);         // move cursor to   (0, 0)
    lcd.print("Moving");        // print message at (0, 0)
    delay(300000);
    lcd.clear();
  }
  
}
  



  
