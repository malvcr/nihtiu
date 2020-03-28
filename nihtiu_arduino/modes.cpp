/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project hast the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#include "modes.h"

namespace Mode {

    void Update_Sensors(Nihtiu::Context& pContext) {

        pContext.aRealTime.aInLinePresure = pContext.aSensors.readPressureSensor();
        pContext.aRealTime.aInLineFlow    = pContext.aSensors.readFlowSensor();
      
    } // Update_Sensors


    Nihtiu::Problem Check_Problems(Nihtiu::Context& pContext) {

        // Check thresholds, abnormal pressure behavior, etc...
        //

        // if there is a warning {
            strcpy(pContext.aRealTime.aProblemDesc,"Hi, there something to check");
            pContext.aActuators.aAlarm.warning();
            pContext.aRealTime.aTriggeredProblem = Nihtiu::Problem::Warning; // OR
        // } else if there is an emergency {
            strcpy(pContext.aRealTime.aProblemDesc,"Wakeup ... big problem here");
            pContext.aActuators.aAlarm.emergency();
            pContext.aRealTime.aTriggeredProblem = Nihtiu::Problem::Warning;
        // }

        return pContext.aRealTime.aTriggeredProblem;
        
    } // Check_Problems

    
    bool Check_Hold(Nihtiu::Context& pContext) {

        bool vHoldPressed = false;
        while (!pContext.aSensors.ctrlHoldActive()) {
            delay (pContext.aSettings.aHoldTime); 
            vHoldPressed = true; // manual bypass so the expiration time will be avoided
        }

        return vHoldPressed;
      
    } // Check_Hold

    
    // ==============

    void OP::volume_ACV     (Nihtiu::Context& pContext) {   // Assist-Control Ventilation

       // WORK IN PROGRESS ... 
       // This mode is not yet finished ... lack the patient intervention ...
       //
       
        Update_Sensors(pContext);

        // First check problems
        Nihtiu::Problem vProblem = Check_Problems(pContext);

        // the vProblem variable must be taken into consideration in the algorithm
        //

        {
            // Calculate these parameters according with the last setup settings and
            // realtime data
            //
            unsigned long vBreathSpeed  = 0; // calculate it
            unsigned long vExhaustSpeed = 0; // calculate it
            unsigned long vBreathVolume = 0; // calculate it

            pContext.aActuators.aBVMController.breath(vBreathSpeed,vBreathVolume);

            if (!Check_Hold(pContext)) {
                delay(pContext.aSettings.aInspiratoryPause);
            }
            
            pContext.aActuators.aBVMController.exhaust(vExhaustSpeed);
            
            delay(pContext.aSettings.aExpiratoryPause);
        }
        
    } // OP::volume_ACV
    
    void OP::volume_SIMV    (Nihtiu::Context& pContext) {   // Synchronized Intermittent-Mandatory Ventilation
        Update_Sensors(pContext);
    } // OP::volume_SIMV

    void OP::pressure_PCV   (Nihtiu::Context& pContext) {   // Pressure-Controlled Ventilation
        Update_Sensors(pContext);
    } // OP::pressure_PCV
    
    void OP::pressure_PSV   (Nihtiu::Context& pContext) {   // Pressure Support Ventilation
        Update_Sensors(pContext);
    } // OP::pressure_PSV
    
    void OP::pressure_PCIRV (Nihtiu::Context& pContext) {   // Pressure Controlled Inverse Ratio Ventilation
        Update_Sensors(pContext);
    } // OP::pressure_PCIRV
    
    void OP::pressure_APRV  (Nihtiu::Context& pContext) {  // Airway Pressure Release Ventilation
        Update_Sensors(pContext);
    } // OP::pressure_APRV

    void OP::dual_PRVC      (Nihtiu::Context& pContext) {  // Pressure Regulated Volume Control
        Update_Sensors(pContext);
    } // OP::dual_PRVC
    
    void OP::interactive_PAV(Nihtiu::Context& pContext) {  // Proportional Assist Ventilation
        Update_Sensors(pContext);
    } // OP::interactive_PAV

    // ==============
    
    Manager::Manager() {

        aData[_ID::ACV]   = OP::volume_ACV;
        aData[_ID::SIMV]  = OP::volume_SIMV;
        aData[_ID::PCV]   = OP::pressure_PCV; 
        aData[_ID::PSV]   = OP::pressure_PSV; 
        aData[_ID::PCIRV] = OP::pressure_PCIRV;
        aData[_ID::APRV]  = OP::pressure_APRV; 
        aData[_ID::PRVC]  = OP::dual_PRVC;     
        aData[_ID::PAV]   = OP::interactive_PAV;
        
    } // Manager constructor

    
    Manager::~Manager() {
    } // Manager destructor

    
    _OP Manager::operator[](ID pId) {
      
        if (pId < _ID::_MaxMode) {
            return aData[pId];
        }
        else {
            return nullptr;
        } 
    }; // Manager::operator[]

    // ==============
  
} // Mode namespace
