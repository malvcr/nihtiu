/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#include "nihtiu.h"

#include <EEPROM.h>

namespace Nihtiu {

    App::App() {
    } // App constructor

    App::~App() {
    } // App destructor

    bool App::discoverAction(Action::ID& pActionID, SettingType& pSettingType, Text& pParamValue) {
        // read the Serial line from the USB connected PC and parse it
        // on an Action and some Parameters.
        return false;
    } // App::discoverAction


    bool App::flag_resetted() {
      return aContext.aSensors.ctrlResetActive();
    } // App::resetted


    bool App::flag_onBattery() {
        return aContext.aSensors.onBatteryPower();
    }

    void App::setup() {
    } // App::setup

    void App::body() {
  
        Action::ID vActionID = Action::_ID::Continue;
    
        SettingType vSettingType;
        Text        vParamValue;

        // To control how battery is used is a basic requirement for
        // any ventilator device.  The idea is to react to a lack of main power
        // and then to continue with the Arduino basic logic, until the power
        // is restablished.
        //
        if (flag_onBattery()) {

            bool vReplayProblem = false;

            // Take into consideration any other currently played alarm, as the battery low
            // message can't hide it.
            //
            if (aContext.aRealTime.aTriggeredProblem != Problem::None) {
                vReplayProblem = true;
            }

            // The cycles on battery must work according with some experimental previous measure that must be
            // loaded as an operational setting.
            //
            if (aContext.aRealTime.aBatteryEmergencyCycled > aContext.aSettings[Nihtiu::_SettingType::BatteryEmergencyThreshold]) {
                aContext.aActuators.aAlarm.emergency("Very low Battery");
            }
            else {
                aContext.aActuators.aAlarm.warning("On Battery");
            }
            aContext.aRealTime.aBatteryEmergencyCycled++;

            // The battery problem can't hide any other important message previously delivered
            //
            if (vReplayProblem) {
                if (Problem::Warning == aContext.aRealTime.aTriggeredProblem) {
                    aContext.aActuators.aAlarm.warning(aContext.aRealTime.aProblemDesc);
                }
                else if (Problem::Emergency == aContext.aRealTime.aTriggeredProblem) {
                    aContext.aActuators.aAlarm.emergency(aContext.aRealTime.aProblemDesc);
                }
            }
        }
        else {
            aContext.aRealTime.aBatteryEmergencyCycled = 0;
        }
  
        if (Serial.available()) {
            discoverAction(vActionID,vSettingType,vParamValue);
        }
        else if (flag_resetted()) {
            vActionID = Action::_ID::Reset;
        }
    
        if (Action::_ID::Continue == vActionID) {
            aModesManager[aContext.aMode](aContext); // defined breath cycle
        }
        else {
            // O(1) execution 
            Serial.print(aActionsManager[vActionID](aContext,vSettingType,vParamValue));
        }
        Serial.flush();
      
    } // App::body


} // Nihtiu namespace
