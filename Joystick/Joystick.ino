

#include <FastIO.h>
#include <I2CIO.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_SR2W.h>
#include <LiquidCrystal_SR3W.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

int xPin1 = A1;
int yPin1 = A0;
int xPin2 = A3;
int yPin2 = A2;

int xPosition1 = 0;  
int yPosition1 = 0;
int xPosition2 = 0;
int yPosition2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
 lcd.backlight();
  pinMode(xPin1, INPUT);
  pinMode(yPin1, INPUT);
  pinMode(xPin2, INPUT);
  pinMode(yPin2, INPUT);
  lcd.setCursor(0,0);
  lcd.print("Iniciando....");
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  
  xPosition1 = analogRead(xPin1);  
  yPosition1 = analogRead(yPin1);
  xPosition2 = analogRead(xPin2);
  yPosition2 = analogRead(yPin2);
  lcd.setCursor(0,0);
  lcd.print("X1: ");
  lcd.print(xPosition1);
  lcd.setCursor(7,0);
  lcd.print("  Y1:");
  lcd.print(yPosition1);
  lcd.setCursor(0,1);
  lcd.print("X2: ");
  lcd.print(xPosition2);
  lcd.setCursor(7,1);
  lcd.print("  Y2:");
  lcd.print(yPosition2);
  
  Serial.print("X1: ");
  Serial.print(xPosition1);
  Serial.print("   X2: ");
  Serial.print(xPosition2);
  Serial.print(" | Y1: ");
  Serial.print(yPosition1);
  Serial.print(" | Y2: ");
  Serial.println(yPosition2);
  
 
  delay(100);
}
