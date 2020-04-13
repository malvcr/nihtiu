/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#ifndef __ACTUATORS_H
#define __ACTUATORS_H

#include "tools.h"
#include "sensors.h"
#include "comm.h"

#include <Stepper.h>

namespace Actuators {

    // This is encoded according with the ULN2003 step motor
    // controller.  Modify accordingly for your own needs
    //
    #define ULN2003_IN1_PIN  8
    #define ULN2003_IN2_PIN  9
    #define ULN2003_IN3_PIN 10
    #define ULN2003_IN4_PIN 11

    #define StepsPerRevolution 2048

    // Originally the Alarm was supposed to be connected with the
    // I2C communication ports.  However, it is better to use the
    // extra serial ports the Mega have for such purpose and the
    // independent Alarm system (based on an Arduino Nano), have
    // been created around that port.
    //
    // Buth, the nihtiu_arduino and the nihtiu_alarm systems share
    // the comm.h and comm.cpp for such reason.  They will become
    // a formal Arduino library in the future.
    //
    // Then, the I2C will not be used with the Actuators, but only 
    // with those sensors are required to communicate using it.
    //
    
    #define AlarmSlaveAddress 1
    
    class BagValveMask {
      
        Stepper* aStepperPtr;

        unsigned int aTestTime;
        unsigned int aTestPressure;
        unsigned int aTestBagVolume;
        unsigned int aTestSpeedRPM;

        unsigned int aUsedTime;
        unsigned int aUsedSpeed;
        unsigned int aUsedSteps;

        Sensors::Devices* aSensorsPtr;
        
    public:

        BagValveMask();
        virtual ~BagValveMask();

        void setSensors(Sensors::Devices* pSensorsPtr) {
            aSensorsPtr = pSensorsPtr;
        }

        /**
         * @param pTestTime   parameters will be calibrated at this time in microseconds
         * @param pPressure  the pressure obtainable when pressing the BVM bat at the specified speed
         * @param pBagVolume the actual bag air capacity
         */
        void setup(unsigned int pTestTime, unsigned int pPressure, unsigned int pBagVolume);

        /**
         * @param pPressingTime  how many microseconds will be used to perform the inflation
         * @param pVolume quantity of air will be delivered in the specified time
         */
        void breath(unsigned int pPressingTime, unsigned int pVolume);

        /**
         * @param pRecoverTime  the time to let the BVM to recover its size.
         * 
         * This is the "maximum" speed, because the BVM has a natural limit when the presure
         * is released on it.  It is not possible to go faster than that.
         */
        void exhaust(unsigned int pRecoverTime);
      
    }; // BagValveMask class

    class Alarm {

        AlarmNode::Comm aComm;

    public:

        Alarm();
    
        void warning  (char* pText);
        void emergency(char* pText);
        void message  (char* pLine1, char* pLine2);
        void silentMsg(char* pLine1, char* pLine2);
        
        void reset();
      
    }; // Alarm class
    

    struct Devices  {

        BagValveMask aBVMController;
        Alarm        aAlarm;
        
    }; // Devices struct
  
} // Actuators namespace

#endif // __ACTUATORS_H
