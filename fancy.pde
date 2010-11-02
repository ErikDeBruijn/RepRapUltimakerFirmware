/* This is where some of the fancy stuff can go that is not directly useful.
 * Think: RGB-LED control, sound, etc. Still, this can be used
 * as useful feedback on temperature, printer status, etc. 
 *
*/
#include "fancy.h"

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
