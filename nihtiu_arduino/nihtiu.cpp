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

    void App::setup() {
    } // App::setup

    void App::body() {
  
        Action::ID vActionID = Action::_ID::Continue;
    
        SettingType vSettingType;
        Text        vParamValue;
  
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
