/*
 * Author: Labib
 * Date 29.09.20
 * Contact: nefaurrahmanlabib147@gmail.com
 */
#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 10

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");

  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  
  delay(2000);
}
