/* This is where some of the fancy stuff can go that is not directly useful.
 * Think: RGB-LED control, sound, etc. Still, this can be used
 * as useful feedback on temperature, printer status, etc. 
 *
*/
#include "fancy.h"
#include "pins.h"
#ifdef FANCY_LCD
#include <LiquidCrystal.h>

LiquidCrystal lcd(LCD_PINS1,LCD_PINS2,LCD_PINS3,LCD_PINS4,LCD_PINS5,LCD_PINS6);  //RS,Enable,D4,D5,D6,D7 //deze is voor onze pcb
#endif

#ifdef FANCY

void fancy_init()
{
#ifdef RGB_LEDS
  pinMode(RGB_R_PIN,OUTPUT);
  pinMode(RGB_G_PIN,OUTPUT);
  pinMode(RGB_B_PIN,OUTPUT);
  for(byte i=0;i<255;i++)
  {
    setRGB(i*.75,i*.75,i);
    delay(4);
  }
#endif
#ifdef FANCY_LCD
// set up the LCD's number of rows and columns:
byte Degree[8] =
{
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000
};
byte Thermometer[8] =
{
  B00100,
  B01010,
  B01010,
  B01010,
  B01010,
  B10001,
  B10001,
  B01110
};

lcd.createChar(0,Degree);
lcd.createChar(1,Thermometer);
lcd.begin(16, 2);   //opgeven wat voor lcd
// Print a message to the LCD.
lcd.print("Ultimaker  v1.0!");
lcd.setCursor(0, 1);    //begin van de regel (0) en op de 2de rij (1)
//         1234567890123456
lcd.print("Ready to connect");

#endif
}
void setRGB(byte r, byte g, byte b)
{
  analogWrite(RGB_R_PIN,r);
  analogWrite(RGB_G_PIN,g);
  analogWrite(RGB_B_PIN,b);
}
void set_RGB_R(byte r)
{
  analogWrite(RGB_R_PIN,r);
}
void set_RGB_G(byte g)
{
  analogWrite(RGB_R_PIN,g);
}
void set_RGB_B(byte b)
{
  analogWrite(RGB_R_PIN,b);
}

#endif
#ifdef FANCY_LCD
/*  int i;
void loop()
{
  i++;
lcd.setCursor(0, 1);    //begin van de regel (0) en op de 2de rij (1)
lcd.print(i);
delay(500);  
}
*/
#endif
