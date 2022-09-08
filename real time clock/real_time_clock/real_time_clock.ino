
#include <virtuabotixRTC.h> 
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
virtuabotixRTC myRTC(6, 7, 8);

void setup() {
 Serial.begin(9600);
 lcd.begin (16,2);
 lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
 lcd.setBacklight(HIGH);
 lcd.home ();
 myRTC.setDS1302Time(15, 54, 11, 5, 4, 6, 2022); //Here you write your actual time/date as shown above 
}

void loop() {
 lcd.clear(); 
 myRTC.updateTime();
 lcd.setCursor(0,0);
 
 lcd.print("Date:");
 lcd.print(myRTC.dayofmonth);
 lcd.print("/");
 lcd.print(myRTC.month);
 lcd.print("/");
 lcd.print(myRTC.year);
 lcd.setCursor(0,1);
 
 lcd.print("Time:");
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.print(myRTC.seconds);
 delay(1000);
}
