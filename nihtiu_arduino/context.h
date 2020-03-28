/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project hast the MIT Licensing.  Check the accompaining LICENSE file.
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

    enum class ParamType : byte {
      
        InspiratoryFlowTime         =  0, // setting
        InspiratoryPause            =  1, // setting
        ExpiratoryFlowTime          =  2, // setting
        ExpiratoryPause             =  3, // setting
        InLinePresureGoal           =  4, // setting
        InLineFlowGoal              =  5, // setting
        
        InLinePresure               =  6, // realtime
        InLineFlow                  =  7, // realtime
        
        ExhalationBlockerActivation =  8, // flag
        ManualInspiratoryHold       =  9, // flag
        HighPressureThreshold       = 10, // operational limit -> alarm
        LowPressureThreshold        = 11,  // operational limit -> alarm

        HoldTime                    = 12,
        BVMTestSpeed                = 13,
        BVMPressure                 = 14
    }; 
    
    enum class Problem : char{
        None      = 'N',
        Warning   = 'W',
        Emergency = 'E'
    };

    struct Settings {
        unsigned long aInspiratoryFlowTime = 0; 
        unsigned long aInspiratoryPause    = 0;
        unsigned long aExpiratoryFlowTime  = 0;
        unsigned long aExpiratoryPause     = 0;
        // T-INFL + PS-INSP + TM-EXFL + PS-EXPP = 1 Cycle
        unsigned long aInLinePresureGoal; 
        unsigned long aInLineFlowGoal;  
        unsigned long aHighPressureThreshold;
        unsigned long aLowPressureThreshold;
        unsigned long aHoldTime = 1000; // microseconds

        unsigned long aBVMTestSpeed = 0;
        unsigned long aBVMPressure  = 0;
        
    }; // Settings class

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
