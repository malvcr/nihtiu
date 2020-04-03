/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#include "actuators.h"

#include <Arduino.h>
#include <Wire.h>

namespace Actuators {

      BagValveMask::BagValveMask() {

          aStepperPtr = new Stepper(
              StepsPerRevolution,
              ULN2003_IN1_PIN,
              ULN2003_IN2_PIN,
              ULN2003_IN3_PIN,
              ULN2003_IN4_PIN
          );
        
      } // BagValveMask constructor


      BagValveMask::~BagValveMask() {

          delete aStepperPtr;
          
      } // BagValveMask destructor

      


      void BagValveMask::setup(unsigned int pTestTime, unsigned int pPressure, unsigned int pBagVolume) {

          aTestTime      = pTestTime;
          aTestPressure  = pPressure;
          aTestBagVolume = pBagVolume;

          // With the Time, Pressure and Volume parameters will perform a series of tests with the
          // air bag, to find the right speed that make these parameters to match.
          //
          // In each case needs to real the real pressure and flow information from the machine
          // sensors
          //
          
          aTestSpeedRPM = 5; // Calculate it according with the nature of the implementation
        
      } // BagValveMask


      void BagValveMask::breath(unsigned int pPressingTime, unsigned int pVolume) {

          // aUsedSpeed indicates how fast the engine must work to achieve
          // the pPressingTime goal.
          //
          aUsedSpeed = aTestSpeedRPM * ( aTestTime / pPressingTime );    

          aStepperPtr->setSpeed(aUsedSpeed);

          // aUsedSteps indicates how many steps the motor must perform to
          // have the right volume with the calculated speed.
          //
          aUsedSteps = (pVolume / aTestBagVolume);

          aStepperPtr->step(aUsedSteps);

          aUsedTime = pPressingTime;
        
      } // BagValveMask::breath


      void BagValveMask::exhaust(unsigned int pRecoverTime) {

          // Knowning the already sent air to the patient, must release the bag, for the air 
          // to be extracted from the patient at the specified time.

          unsigned int vNeededSpeed = aUsedSpeed * ( aUsedTime / pRecoverTime );

          aStepperPtr->setSpeed(vNeededSpeed);

          aStepperPtr->step(aUsedSteps * -1); // motor runs backwards

      } // BagValveMask::exhaust

      // -------------

      Alarm::Alarm() {
          Wire.begin();
      } // Alarm constructor


      // The alarm will wait for a short flag specifying the type of
      // operation to perform.  It can be:
      //
      // *W* : Warning
      // *E* : Emergency
      // *R* : Reset (turn off the alarm)
      //
      // If the operation is *W* or *E*, will wait for a short
      // message (32 byte maximum), that will show in a LCD screen
      // or similar device.
      //

      void Alarm::warning(Text& pText) {

          Wire.beginTransmission(AlarmSlaveAddress);
          Wire.write("*W*");
          Wire.endTransmission();
          Wire.beginTransmission(AlarmSlaveAddress);
          Wire.write(pText);
          Wire.endTransmission();
        
      } // Alarm::warning

      
      void Alarm::emergency(Text& pText) {

          Wire.beginTransmission(AlarmSlaveAddress);
          Wire.write("*E*");
          Wire.endTransmission();
          Wire.beginTransmission(AlarmSlaveAddress);
          Wire.write(pText);
          Wire.endTransmission();
        
      } // Alarm::emergency

      
      void Alarm::reset() {

          Wire.beginTransmission(AlarmSlaveAddress);
          Wire.write("*R*");
          Wire.endTransmission();
        
      } // Alarm::reset

        
} // Actuators namespace
