// Mesure profondeur cuve 
// 
// capteur ultrason : HC-SR04 
// VCC to arduino 5v GND to arduino GND
// Echo to Arduino pin 13 Trig to Arduino pin 12
// 
// afficheur LCD jhd-162a 
// 1.  LCD GND                   
// 2.  LCD VCC +5v               
// 3.  Contrast ajustement (GND)
// 4.  RS Register Select      
// 5.  RW Read/Write            
// 6.  Enable (Clock)          
// 7.  Data 0                  
// 8.  Data 1                 
// 9.  Data 2                 
// 10. Data 3                
// 11. Data 4               
// 12. Data 5              
// 13. Data 6             
// 14. Data 7            
// 15. Backlight +       
// 16. Backlight GND     
// LiquidCrystal lcd(rs, enable, d4, d5, d6, d7) // mode 4 bits - RW non connectée (le plus simple!)  
// LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7) // mode 4 bits - RW utilisée                     
// LiquidCrystal lcd(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) // mode 8 bits - RW non connectée    
// LiquidCrystal lcd(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) //mode 8 bits - RW utilisée      

// mesure haute : 34 cm 

// HCSR04
#define trigPin 12
#define echoPin 13

// JHD162A
#include <LiquidCrystal.h>
#define rs     10
#define rw     11
#define enable 12
#define d4     4
#define d5     5
#define d6     6
#define d7     7

LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.clear();
}

void loop() {
  lcd.clear();
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    lcd.print("Out of range");
  }
  else {
    Serial.print(distance);
    lcd.print(distance);
    Serial.println(" cm");
    lcd.print("cm");
  }
  delay(2000);
}
