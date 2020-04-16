/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#ifndef __SENSORS_H
#define __SENSORS_H

#include <Arduino.h>

namespace Sensors {

    /**
     * Take into consideration that some sensors don't work reading their data directly on
     * analog pins as they are more complex than that and usually require a formal communication
     * channel as the i2c one.
     */

    #define AIR_PRESSURE_ANALOG_PIN    0 // use the right analog pin
    #define AIR_FLOW_ANALOG_PIN        1 // use the right analog pin

    #define CTRL_HOLD_DIGITAL_PIN      2 // use the right digital pin
    #define CTRL_RESET_DIGITAL_PIN     3 // use the right digital pin
    #define CTRL_ONBATTERY_DIGITAL_PIN 4 // use the right digital pin

    class Devices {

        float aPressureConversionRate;
        float aFlowConversionRate;
      
        bool  readCtrlSignal(int);
    public:

        Devices();

        unsigned long readPressureSensor(); 
        unsigned long readFlowSensor();
        
        bool ctrlHoldActive() {
            return readCtrlSignal(CTRL_HOLD_DIGITAL_PIN);
        }
        bool ctrlResetActive() {
            return readCtrlSignal(CTRL_RESET_DIGITAL_PIN);
        }
        bool onBatteryPower() {
            // Take into consideration that the power failure will have
            // negative logic here...
            //
            return !readCtrlSignal(CTRL_ONBATTERY_DIGITAL_PIN);
        }

        bool breathDetected();
      
    }; // Devices class
  
} // Sensors namespace

#endif // __SENSORS_H
