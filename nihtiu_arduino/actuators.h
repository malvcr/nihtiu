/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project hast the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#ifndef __ACTUATORS_H
#define __ACTUATORS_H

namespace Actuators {

    class BagValveMask {
    public:

        /**
         * @param pTestSpeed parameters will be calibrated at this speed in microseconds
         * @param pPressure  the pressure obtainable when pressing the BVM bat at the specified speed
         * @param pBagVolume the actual bag air capacity
         */
        void setup(unsigned int pTestSpeed, unsigned int pPressure, unsigned int pBagVolume);

        /**
         * @param pSpeed how many microseconds will be used to perform the inflation
         * @param pVolume quantity of air will be delivered in the specified time
         */
        void breath(unsigned int pSpeed, unsigned int pVolume);

        /**
         * @param pMaxSpeed the maximum speed the air will be freed.
         * 
         * This is the "maximum" speed, because the BVM has a natural limit when the presure
         * is released on it.  It is not possible to go faster than that.
         */
        void exhaust(unsigned int pMaxSpeed);
      
    }; // BagValveMask class

    class Alarm {

    public:
        void warning();
        void emergency();
        void reset();
      
    }; // Alarm class
    

    struct Devices  {

        BagValveMask aBVMController;
        Alarm        aAlarm;
        
    }; // Devices struct
  
} // Actuators namespace

#endif // __ACTUATORS_H
