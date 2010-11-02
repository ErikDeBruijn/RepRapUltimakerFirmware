#ifndef PINS_H
#define PINS_H

#define MOTHERBOARD 3
#if MOTHERBOARD == 0

#error The Arduino cannot run the 5D GCode interpreter

/****************************************************************************************
* Arduino pin assignment - left here as they might be useful
*
****************************************************************************************/
// 
#define X_STEP_PIN (byte)25
#define X_DIR_PIN (byte)23
#define X_MIN_PIN (byte)13
#define X_MAX_PIN (byte)12

#define Y_STEP_PIN (byte)31
#define Y_DIR_PIN (byte)33
#define Y_MIN_PIN (byte)10
#define Y_MAX_PIN (byte)11

#define Z_STEP_PIN (byte)37
#define Z_DIR_PIN (byte)39
#define Z_MIN_PIN (byte)8
#define Z_MAX_PIN (byte)9


//extruder pins
#define EXTRUDER_0_MOTOR_SPEED_PIN  (byte)43
#define EXTRUDER_0_MOTOR_DIR_PIN    (byte)45
#define EXTRUDER_0_HEATER_PIN       (byte)2
#define EXTRUDER_0_FAN_PIN          (byte)3
#define EXTRUDER_0_TEMPERATURE_PIN  (byte)0  // Analogue input
#define EXTRUDER_0_VALVE_DIR_PIN             (byte)16       //NB: Conflicts with Max Z!!!!
#define EXTRUDER_0_VALVE_ENABLE_PIN          (byte)15 
#define EXTRUDER_0_STEP_ENABLE_PIN  41 // 5 - NB conflicts with the fan; set -ve if no stepper


/****************************************************************************************
* Sanguino/RepRap Motherboard with direct-drive extruders
*
****************************************************************************************/
#elif MOTHERBOARD == 1

#ifndef __AVR_ATmega644P__
#error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu.
#endif

#define DEBUG_PIN        0

#define X_STEP_PIN (byte)15
#define X_DIR_PIN (byte)18
#define X_MIN_PIN (byte)20
#define X_MAX_PIN (byte)21
#define X_ENABLE_PIN (byte)19

#define Y_STEP_PIN (byte)23
#define Y_DIR_PIN (byte)22
#define Y_MIN_PIN (byte)25
#define Y_MAX_PIN (byte)26
#define Y_ENABLE_PIN (byte)19

#define Z_STEP_PIN (byte)29
#define Z_DIR_PIN (byte)30
#define Z_MIN_PIN (byte)2
#define Z_MAX_PIN (byte)1
#define Z_ENABLE_PIN (byte)31

// Heated bed - TODO: reassign these

#define BED_HEATER_PIN (byte)3
#define BED_TEMPERATURE_PIN (byte)1 


//extruder pins
#define EXTRUDER_0_MOTOR_SPEED_PIN   (byte)12
#define EXTRUDER_0_MOTOR_DIR_PIN     (byte)16
#define EXTRUDER_0_HEATER_PIN        (byte)14
#define EXTRUDER_0_FAN_PIN           (byte)3
#define EXTRUDER_0_TEMPERATURE_PIN  (byte)4    // Analogue input
#define EXTRUDER_0_VALVE_DIR_PIN     (byte)17
#define EXTRUDER_0_VALVE_ENABLE_PIN  (byte)13  // Valve needs to be redesigned not to need this
#define EXTRUDER_0_STEP_ENABLE_PIN  (byte)3  // 3 - Conflicts with the fan; set -ve if no stepper

#define EXTRUDER_1_MOTOR_SPEED_PIN   (byte)4
#define EXTRUDER_1_MOTOR_DIR_PIN    (byte)0
#define EXTRUDER_1_HEATER_PIN        (byte)24
#define EXTRUDER_1_FAN_PIN           (byte)7
#define EXTRUDER_1_TEMPERATURE_PIN  (byte)3  // Analogue input
#define EXTRUDER_1_VALVE_DIR_PIN    (byte) 6
#define EXTRUDER_1_VALVE_ENABLE_PIN (byte)5   // Valve needs to be redesigned not to need this 
#define EXTRUDER_1_STEP_ENABLE_PIN  (byte)-1  // 7 - Conflicts with the fan; set -ve if no stepper


/****************************************************************************************
* RepRap Motherboard with RS485 extruders
*
****************************************************************************************/

#elif MOTHERBOARD == 2

#ifndef __AVR_ATmega644P__
#error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu.
#endif

//x axis pins
#define X_STEP_PIN      15
#define X_DIR_PIN       18
#define X_ENABLE_PIN    19
#define X_MIN_PIN       20
#define X_MAX_PIN       21

//y axis pins
#define Y_STEP_PIN      23
#define Y_DIR_PIN       22
#define Y_ENABLE_PIN    24
#define Y_MIN_PIN       25
#define Y_MAX_PIN       26

//z axis pins
#define Z_STEP_PIN      27
#define Z_DIR_PIN       28
#define Z_ENABLE_PIN    29
#define Z_MIN_PIN       30
#define Z_MAX_PIN       31

#define E_STEP_PIN      17
#define E_DIR_PIN       16

//our pin for debugging.

#define DEBUG_PIN        0

//our SD card pins
#define SD_CARD_WRITE    2
#define SD_CARD_DETECT   3
#define SD_CARD_SELECT   4

//our RS485 pins
#define TX_ENABLE_PIN	12
#define RX_ENABLE_PIN	13

//pin for controlling the PSU.
#define PS_ON_PIN       14

/****************************************************************************************
* Arduino Mega pin assignment
*
****************************************************************************************/

#elif MOTHERBOARD == 3

#ifndef __AVR_ATmega1280__
#error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
#endif

#define DEBUG_PIN        0

#define X_STEP_PIN (byte)25 // X motor werkt!
#define X_DIR_PIN (byte)23
#define X_MIN_PIN (byte)22// needed a different PIN than 13!
#define X_MAX_PIN (byte)12
#define X_ENABLE_PIN (byte)27

#define Y_STEP_PIN (byte)31 // Y motor werkt ook!
#define Y_DIR_PIN (byte)33
#define Y_MIN_PIN (byte)11
#define Y_MAX_PIN (byte)10
#define Y_ENABLE_PIN (byte)29

// Z motor lijkt te werken maar niet helemaal lekker ivm verkeerde microstepper 
// instelling, moet ik nog de pull-ups een kleinere weerstand geven zodat het op 
// een logische hoog komt. Maar hij draait!!
#define Z_STEP_PIN (byte)37 
#define Z_DIR_PIN (byte)39
#define Z_MIN_PIN (byte)9
#define Z_MAX_PIN (byte)8
#define Z_ENABLE_PIN (byte)35

// Heated bed

#define BED_HEATER_PIN (byte)4 // Therm 3 - niet getest
#define BED_TEMPERATURE_PIN (byte)11 // 

/*
enX=27,enY29,enY35,ext41,A51
*/

//extruder pins

#define EXTRUDER_0_STEP_PIN (byte)43 // extruder volledig getest, werkt!
#define EXTRUDER_0_DIR_PIN (byte)45
#define EXTRUDER_0_ENABLE_PIN (byte)41
#define EXTRUDER_0_HEATER_PIN (byte)2
#define EXTRUDER_0_TEMPERATURE_PIN (byte)9// 0 = thermocouple exp. board.//9 = THERM1, 10=THERM2

#define EXTRUDER_1_STEP_PIN (byte)49 // extruder volledig getest, werkt OOK!!
#define EXTRUDER_1_DIR_PIN (byte)47
#define EXTRUDER_1_ENABLE_PIN (byte)51
#define EXTRUDER_1_HEATER_PIN (byte)3
#define EXTRUDER_1_TEMPERATURE_PIN (byte)10 


#else

#error Unknown MOTHERBOARD value in configuration.h

#endif

#endif
