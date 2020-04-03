/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#ifndef __CONTEXT_H
#define __CONTEXT_H


namespace Mode {
    using ID = byte;
} // Mode namespace


namespace Action {
    using ID = byte;
} // Action namespace


#include "modes.h"
#include "tools.h"
#include "sensors.h"
#include "actuators.h"

namespace Nihtiu {

    using SettingType = byte;
    
    namespace _SettingType {

        const SettingType InspiratoryFlowTime         =  0; // The time needed to breath
        const SettingType InspiratoryPause            =  1; // The time the air must stay in the lungs
        const SettingType ExpiratoryFlowTime          =  2; // The time needed to exhale
        const SettingType ExpiratoryPause             =  3; // The time before breathing again
        const SettingType InLinePressureGoal          =  4; // The IDEAL pressure level
        const SettingType InLineFlowGoal              =  5; // The IDEAL flow (volume by time) level
        
        const SettingType HighPressureThreshold       =  6; // Pressure above this limit trigger emergency alarm
        const SettingType LowPressureThreshold        =  7; // Pressure below this limit trigger emergency alarm
        const SettingType PressureWarningLevel        =  8; // The "warning" distance to arrive to the thresolds

        const SettingType HoldTime                    =  9; // Granularity for the hold button waiting time
        const SettingType BVMTestSpeed                = 10; // How fast the BVM will be depleted without intervention
        const SettingType BVMPressure                 = 11; // Pressure used to calibrate the BVM

        const SettingType _MaxType                    = 11; 

    } // _SettingType namespace

    using Settings = unsigned long[_SettingType::_MaxType];

    enum class Problem : char{
        None      = 'N',
        Warning   = 'W',
        Emergency = 'E'
    };

    struct RealTime {
      
        unsigned long aInLinePressure;    
        unsigned long aInLineFlow; 
        unsigned long aLastFinishedTime = millis();       
        ShortText     aLastProfile;

        Problem       aTriggeredProblem = Problem::None;
        Text          aProblemDesc;

        unsigned long elapsedTime() {
            // about "millis rollover" issue : https://forum.arduino.cc/index.php/topic,42997.0.html
            return millis() - aLastFinishedTime;
        }
        void updateFinishedTime() {
            aLastFinishedTime = millis();
        }
        
        
    }; // RealTime struct

    
    struct Context  {

        Mode::ID           aMode;
        Text               aLastResult;
        RealTime           aRealTime;
        Settings           aSettings;
        Sensors::Devices   aSensors;
        Actuators::Devices aActuators;

        unsigned long cycleTime() {
            return aSettings[_SettingType::InspiratoryFlowTime]+
                   aSettings[_SettingType::InspiratoryPause]+
                   aSettings[_SettingType::ExpiratoryFlowTime]+
                   aSettings[_SettingType::ExpiratoryPause];
        }
        Context() {
            aActuators.aBVMController.setSensors(&aSensors);
        }
        
    }; // Context class

} // Nihtiu namespace

#endif // __CONTEXT_H
