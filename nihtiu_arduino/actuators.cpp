/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#include "actuators.h"

namespace Actuators {


      void BagValveMask::setup(unsigned int pTestSpeed, unsigned int pPressure, unsigned int pBagVolume) {

          // With this data must calculate the internal parameters that the particular technology to 
          // control the Bag will be used.
        
      } // BagValveMask


      void BagValveMask::breath(unsigned int pSpeed, unsigned int pVolume) {

          // Using the setup data, must press the bag until the specified volume have been
          // send to the patient in the specified time
        
      } // BagValveMask::breath


      void BagValveMask::exhaust(unsigned int pMaxSpeed) {

          // Knowning the already sent air to the patient must release the bag for the air 
          // to be extracted from the patient in the specified time
        
      } // BagValveMask::exhaust

      // -------------

      void Alarm::warning() {

          // Set a medium disturbing alarm
          // maybe some sound for 1/10 second and a blue light
        
      } // Alarm::warning

      
      void Alarm::emergency() {

          // Set a very noisy alarm
          // maybe some sound for 1/2 second and a red light
        
      } // Alarm::emergency

      
      void Alarm::reset() {

          // Turn off the alarm
        
      } // Alarm::reset

        
} // Actuators namespace
