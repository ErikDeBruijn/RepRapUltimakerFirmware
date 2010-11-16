#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/*
 *  This is the configuration file for the RepRap Motherboard microcontroller.
 *  Set values in it to match your RepRap machine.
 *  
 *  Lines in here with a 
 *
 *        // *RO
 *
 *  Comment at the end (read-only) should probably only be changed if you really
 *  know what you are doing...
 */

// Here are the Motherboard codes; set MOTHERBOARD to the right one
// A standard Mendel is MOTHERBOARD 2

// (Arduino: 0 - no longer in use)
// Sanguino or RepRap Motherboard with direct drive extruders: 1
// RepRap Motherboard with RS485 extruders: 2
// Arduino Mega: 3
// Ultimaker users: This should be 3 if your system uses an Arduino Mega, not 1.1 or something that you see on your Ultimaker Electronics.

#define MOTHERBOARD 3 

// The number of real extruders in this machine

#define EXTRUDER_COUNT 1

/*********************************************************************************************
*  _   _ _ _   _                 _
* | | | | | |_(_)_ __ ___   __ _| | _____ _ __
* | | | | | __| | '_ ` _ \ / _` | |/ / _ \ '__|
* | |_| | | |_| | | | | | | (_| |   <  __/ |
*  \___/|_|\__|_|_| |_| |_|\__,_|_|\_\___|_|
* 
* Valid for versions: 1.0 and 1.1
* For documentation, see http://www.ultimaker.com/
*********************************************************************************************/

#if MOTHERBOARD == 3

// Comment out this if you are using a thermocouple
#define USE_THERMISTOR
//#define AD595_THERMOCOUPLE
//#define MAX6675_THERMOCOUPLE

// Set to 1 if enable pins are inverting
// For RepRap stepper boards version 1.x the enable pins are *not* inverting.
// For RepRap stepper boards version 2.x and above the enable pins are inverting.
#define INVERT_ENABLE_PINS 1

// Set ENDSTOP_PULL_UPS to "true" if you're using microswitches
// This will put a logical high in the input pins by connecting an internal 20K resistor to Vcc.
#define ENDSTOP_PULL_UPS true

// Set to one if the axis opto-sensor outputs inverting (ie: 1 means open, 0 means closed)
// RepRap opto endstops with H21LOI sensors are not inverting; ones with H21LOB
// are inverting.
// Set [XYZ]_ENDSTOP_INVERTING to "true" for using microswitches.

#define X_ENDSTOP_INVERTING true
#define Y_ENDSTOP_INVERTING true
#define Z_ENDSTOP_INVERTING true

// Motherboard 3 driving Pololu microstepping controllers - 16 microsteps

// Axis scaling in stepper-motor steps per mm of movement

// Select 1/16 STEP!
#define X_STEPS_PER_MM   79.87220447 //Ultimaker's belt pitch is 2.032mm. 2.032*20=40.064. 40.064/200/16 mm/step
#define INVERT_X_DIR 1

// Select 1/16 STEP!
#define Y_STEPS_PER_MM   79.87220447
#define INVERT_Y_DIR 0

// This stepper driver should be in QUARTER STEP MODE (LOW/HIGH/LOW I think)
#define Z_STEPS_PER_MM   200*8/6 //200*8/1.25
#define INVERT_Z_DIR 1

// Stepper-driven extruder
// E_STEPS_PER_MM is the number of steps needed to 
// extrude 1mm out of the nozzle.  E0 for extruder 0;
// E1 for extruder 1, and so on.

#define E0_STEPS_PER_MM   14.0//17.6      // NEMA 17 59/11 geared extruder 8mm diameter drive
#define E1_STEPS_PER_MM   14.0//17.6      // NEMA 17 59/11 geared extruder 8mm diameter drive

// The temperature routines get called each time the main loop
// has gone round this many times

#define SLOW_CLOCK 2000

// If you want to enable fancy stuff like RGB LEDs for feedback and just to show off.
// Make sure FANCY is defined if you want to have this enabled, otherwise comment it out.
#define FANCY
#define FANCY_LCD
#define FANCY_LED_PWM_MULTIPLY 0.3 // in case you run everything at a voltage higher than 12V!
#endif

//**********************************************************************************************

// The speed at which to talk with the host computer; default is 57600

#define HOST_BAUD 57600 // *RO

// Set 1s where you have endstops; 0s where you don't
// Both Darwin and Mendel have MIN endstops, but not MAX ones.

#define ENDSTOPS_MIN_ENABLED 1
#define ENDSTOPS_MAX_ENABLED 1

// The number of mm below which distances are insignificant (one tenth the
// resolution of the machine is the default value).

#define SMALL_DISTANCE 0.01 // *RO

// Useful to have its square

#define SMALL_DISTANCE2 (SMALL_DISTANCE*SMALL_DISTANCE) // *RO

//our maximum feedrates in mm/minute
#define FAST_XY_FEEDRATE 4000.0
#define FAST_Z_FEEDRATE  75.0

// Data for acceleration calculations
// Comment out the next line to turn accelerations off
//#define ACCELERATION_ON
// ERIK: changing to a software configurable parameter:
// To enable acceleration by default, configure to true. It can be turned of with M-code M142
//acceleration_enabled = true;

#define SLOW_XY_FEEDRATE 1200.0 // Speed from which to start accelerating
#define SLOW_Z_FEEDRATE 45


#if INVERT_ENABLE_PINS == 1  // *RO
#define ENABLE_ON LOW        // *RO
#else                        // *RO
#define ENABLE_ON HIGH       // *RO
#endif                       // *RO

// Set these to 1 to disable an axis when it's not being used,
// and for the extruder.  Usually only Z is disabled when not in
// use.  You will probably find that disabling the others (i.e.
// powering down the steppers that drive them) when the ends of
// movements are reached causes poor-quality builds.  (Inertia
// causes overshoot if the motors are not left powered up.)

#define DISABLE_X 0
#define DISABLE_Y 0
#define DISABLE_Z 1
#define DISABLE_E 0

// The number of 5-second intervals to wait at the target temperature for things to stabilise.
// Too short, and the extruder will jam as only part of it will be hot enough.
// Too long and the melt will extend too far up the insulating tube.
// Default value: 10

#define WAIT_AT_TEMPERATURE 10

// PID gains.  E_ = extruder, B_ = bed.  The Es are about right for a brass extruder about 8 mm 
// in diameter and 30 mm long heated by a 6 ohm coil with a 12v supply.  The B_ values are OK
// for the bed described here:  http://reprap.org/wiki/Mendel_heated_bed
// Extruding increase biases the input to the extruder heater when the extruder
// is running as it requires more power.

#define E_TEMP_PID_PGAIN 6.5// HIGHER: quicker 
#define E_TEMP_PID_IGAIN 0.50 // HIGHER: makes overshoot bigger, but also shorter if you LIMIT it, see below)
#define E_TEMP_PID_DGAIN 0.2 // Not doing much good
#define E_TEMP_PID_BAND 0.0
// To prevent integral windup, allow the I*GAIN to only have this much influence (below 255 makes sense):
#define E_TEMP_PID_I_LIMIT 200/E_TEMP_PID_IGAIN
#define EXTRUDING_INCREASE 7

#define B_TEMP_PID_PGAIN 2
#define B_TEMP_PID_IGAIN 0.07
#define B_TEMP_PID_DGAIN 1
#define B_TEMP_PID_BAND 1000.0

// To turn on PID debugging strings, set this to EXTRUDER_0_HEATER_PIN, EXTRUDER_1_HEATER_PIN or BED_HEATER_PIN
//#define DEBUG_PID EXTRUDER_0_HEATER_PIN

// The width of Henry VIII's thumb (or something).

#define INCHES_TO_MM 25.4 // *RO

// The things below should not be changed unless you know what you're doing:

#define X_STEPS_PER_INCH (X_STEPS_PER_MM*INCHES_TO_MM) // *RO
#define Y_STEPS_PER_INCH (Y_STEPS_PER_MM*INCHES_TO_MM) // *RO
#define Z_STEPS_PER_INCH (Z_STEPS_PER_MM*INCHES_TO_MM) // *RO


//our command string length

#define COMMAND_SIZE 128 // *RO

// Our response string length

#define RESPONSE_SIZE 256 // *RO

// The size of the movement buffer

#define BUFFER_SIZE 4 // *RO

// Number of microseconds between timer interrupts when no movement
// is happening

#define DEFAULT_TICK (long)1000 // *RO

// What delay() value to use when waiting for things to free up in milliseconds

#define WAITING_DELAY 1 // *RO

///******************************************************************************

// You probably only want to edit things below this line if you really really
// know what you are doing...


void delayMicrosecondsInterruptible(unsigned int us);

// Inline interrupt control functions

inline void enableTimerInterrupt() 
{
   TIMSK1 |= (1<<OCIE1A);
}
	
inline void disableTimerInterrupt() 
{
     TIMSK1 &= ~(1<<OCIE1A);
}
        
inline void setTimerCeiling(unsigned int c) 
{
    OCR1A = c;
}

inline void resetTimer()
{
  TCNT2 = 0;
}

#endif
