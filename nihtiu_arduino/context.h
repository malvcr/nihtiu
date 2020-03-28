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

        const SettingType InspiratoryFlowTime         =  0;
        const SettingType InspiratoryPause            =  1;
        const SettingType ExpiratoryFlowTime          =  2;
        const SettingType ExpiratoryPause             =  3;
        const SettingType InLinePresureGoal           =  4;
        const SettingType InLineFlowGoal              =  5;
        
        const SettingType HighPressureThreshold       =  6; // setting : operational limit -> alarm
        const SettingType LowPressureThreshold        =  7; // setting : operational limit -> alarm

        const SettingType HoldTime                    =  8;
        const SettingType BVMTestSpeed                =  9;
        const SettingType BVMPressure                 = 10;

        const SettingType _MaxType                    = 11;

    } // _SettingType namespace

    using Settings = unsigned long[_SettingType::_MaxType];

/*
 * Previously SettngType was a combined enumeration class including real time and flat elements.
 * 
 * That made things more complicated.  So the settings now are really fixed values that can be modified
 * by actions, but the other real-time elements must be controlled in a different way (this is not yet
 * finished).
 * 
    enum class ParamType : byte {

        InLinePresure               = 11, // realtime
        InLineFlow                  = 12, // realtime
        
        ExhalationBlockerActivation = 13, // flag
    }; 
*/    
    enum class Problem : char{
        None      = 'N',
        Warning   = 'W',
        Emergency = 'E'
    };

    struct RealTime {
      
        unsigned long aInLinePresure;    
        unsigned long aInLineFlow;        
        bool          aExhalationBlockerActive;
        ShortText     aLastProfile;

        Problem       aTriggeredProblem = Problem::None;
        Text          aProblemDesc;
        
    }; // RealTime struct

    
    struct Context  {

        Mode::ID           aMode;
        Text               aLastResult;
        RealTime           aRealTime;
        Settings           aSettings;
        Actuators::Devices aActuators;
        Sensors::Devices   aSensors;
        
    }; // Context class

} // Nihtiu namespace

#endif // __CONTEXT_H
