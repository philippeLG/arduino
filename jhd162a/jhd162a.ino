/********************************/
/* LCD JHD 162A                 */
/* 1.  LCD GND                  */ 
/* 2.  LCD VCC +5v              */ 
/* 3.  Contrast ajustement (GND)*/
/* 4.  RS Register Select       */
/* 5.  RW Read/Write            */
/* 6.  Enable (Clock)           */
/* 7.  Data 0                   */ 
/* 8.  Data 1                   */
/* 9.  Data 2                   */ 
/* 10. Data 3                   */
/* 11. Data 4                   */ 
/* 12. Data 5                   */
/* 13. Data 6                   */
/* 14. Data 7                   */
/* 15. Backlight +              */
/* 16. Backlight GND            */
/********************************/


/* LiquidCrystal lcd(rs, enable, d4, d5, d6, d7) // mode 4 bits - RW non connectée (le plus simple!)  */
/* LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7) // mode 4 bits - RW utilisée                     */
/* LiquidCrystal lcd(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) // mode 8 bits - RW non connectée    */
/* LiquidCrystal lcd(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) //mode 8 bits - RW utilisée      */


#include <LiquidCrystal.h>
# define rs     10 
# define rw     11 
# define enable 12 
# define d4     4 
# define d5     5 
# define d6     6 
# define d7     7 

LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7);
//LiquidCrystal lcd(13, 11, 12, 7, 6, 5, 4); // déclare une variable LiquidCrystal appelée lcd 
// mode 4 bits et RW pas utilisé

void setup()
{
 Serial.begin(9600);
 lcd.print("hello, world!"); // affiche le désormais célèbre texte "Hello World!" 
 Serial.print("hello") ;
}

void loop() {
lcd.clear();
delay(2000);
lcd.print("hello, world!");
Serial.print("12");
delay(2000);
}
