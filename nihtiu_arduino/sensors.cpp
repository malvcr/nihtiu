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


    unsigned long Devices::readPressureSensor() {

        int vRawData = analogRead(AIR_PRESSURE_ANALOG_PIN);

        unsigned long vPressureData = vRawData /* and the right conversion */;

        return vPressureData;
      
    } // Devices::readPressureSensor

    
    unsigned long Devices::readFlowSensor() {

        int vRawData = analogRead(AIR_FLOW_ANALOG_PIN);

        unsigned long vPressureData = vRawData /* and the right conversion */;

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
