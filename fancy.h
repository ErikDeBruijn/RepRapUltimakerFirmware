/* This is where some of the fancy stuff can go that is not directly useful.
 * Think: RGB-LED control, sound, etc. Still, this can be used
 * as useful feedback on temperature, printer status, etc. 
 *
*/
#ifndef FANCY_H
#define FANCY_H
#ifdef FANCY // set this in your configuration.h

#define RGB_LEDS 1

// preferably PWM pins (Mega: 1-14)
#define RGB_R_PIN 5
#define RGB_G_PIN 6
#define RGB_B_PIN 7

int heater_alternate = true;
int fancy_iterator = 0;
int bedTemp = 0; // for showing this on the display
int targetTemp = 0; // for showing this on the display
void fancy_init();
void setRGB(byte r, byte g, byte b);
void set_RGB_R(byte r);
void set_RGB_G(byte g);
void set_RGB_B(byte b);
//void lcd
#endif
#endif
