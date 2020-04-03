/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#include "sensors.h"

namespace Sensors {


    Devices::Devices() {

        pinMode(AIR_PRESSURE_ANALOG_PIN,INPUT);
        pinMode(AIR_FLOW_ANALOG_PIN    ,INPUT);

        pinMode(CTRL_HOLD_DIGITAL_PIN  ,INPUT);
        pinMode(CTRL_RESET_DIGITAL_PIN ,INPUT);

        // 1) Calibreate
        // 2) Check mm H2O
        //    Use these values to define the Conversion rates
        //
        aPressureConversionRate = 0;
        aFlowConversionRate     = 0;

    } // Devices constructor


    unsigned long Devices::readPressureSensor() {

        float vRawData = analogRead(AIR_PRESSURE_ANALOG_PIN);

        unsigned long vPressureData = (vRawData * aPressureConversionRate);// 0 - 1023

        return vPressureData;
      
    } // Devices::readPressureSensor

    
    unsigned long Devices::readFlowSensor() {

        float vRawData = analogRead(AIR_FLOW_ANALOG_PIN);

        unsigned long vPressureData = (vRawData * aFlowConversionRate);  // 0 - 1023

        return vPressureData;

    } // Devices::readFlowSensor


    bool Devices::readCtrlSignal(int pPin) {

        int vRawData = digitalRead(pPin);

        return (1 == vRawData);
      
    } // Devices::readCtrlSignal


    bool Devices::breathDetected() {

        // We have flow and pressure sensors
        // ... what is the right way to dettect a breath?
        // Maybe each physical devices have different thresholds .. check them
        //    carefully

        return (readPressureSensor() > 0);
      
    } // Devices::breathDetected
    
  
} // Sensors namespace
