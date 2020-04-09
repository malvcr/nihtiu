/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */
 
#ifndef __DEFS_H
#define __DEFS_H

    #define DFLT_SPEED 9600
    #define LINE_LEN     16
    #define BUFFER_LEN   33 // [1] command [16] line1 [16] line2

#ifndef __AVR_ATmega2560__    

    //
    // These are the particular pin numbers used with the Arduino Nano that will
    // provide the "alarn" system.
    //
    
    #define LCD_RS      12
    #define LCD_EN      11
    #define LCD_D4       2
    #define LCD_D5       3
    #define LCD_D6       4
    #define LCD_D7       5
    
    #define Buzzer_PIN   6
    #define RedLED_PIN   7
    #define GreenLED_PIN 8
    
    /*
     * If the blind command is implemented, another pin must be used
     * to provide 3.3v to the LCD backlight that be able to turn off
     * by command.
     * 
     */

    // A 16 bytes empty line to be used with some LCD operations
    //
    #define EMPTY_LINE "                "

    // Particular frequencies used with the Buzzer on this implementation.
    // They are using the Lylipond standard with "is" for sharp and "es" for flat notes
    
    #define _A   440
    #define _Ais 466
    #define _Bes 466
    #define _B   494
    #define _Bis 523
    #define _Ces 494
    #define _C   523
    #define _Cis 554
    #define _Des 554
    #define _D   587
    #define _Dis 622
    #define _Ees 622
    #define _E   659
    #define _Eis 698
    #define _Fes 659
    #define _F   698
    #define _Fis 740
    #define _Ges 740
    #define _G   784
    #define _Gis 830
    #define _Aes 830
    #define _A2  880

#endif
    
    /**
     * Different command types.
     */
    namespace CMD {
        const char Message   = 'M'; // turn on an information + noise, alarm
        const char SilentMsg = 'S'; // turn on an information alarm
        const char Warning   = 'W'; // turn on a  warning alarm
        const char Emergency = 'E'; // turn on an emergency alarm
        const char Off       = 'O'; // turn off the previous activated alarm
        const char None      = 'N'; // no specified operation
        const char Version   = 'V'; // returns the current alarm system version
        const char Blind     = 'B'; // future usage (probably, turn off the LCD backlight) [not yet used]
    } // CMD namespace

#endif // __DEFS_H
