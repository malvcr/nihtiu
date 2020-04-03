/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#include "modes.h"

namespace Mode {

    void Update_Sensors(Nihtiu::Context& pContext) {

        pContext.aRealTime.aInLinePressure = pContext.aSensors.readPressureSensor();
        pContext.aRealTime.aInLineFlow     = pContext.aSensors.readFlowSensor();
      
    } // Update_Sensors


    Nihtiu::Problem Check_Problems(Nihtiu::Context& pContext) {

        // Checking the pressure thresholds

        if (pContext.aRealTime.aInLinePressure < pContext.aSettings[Nihtiu::_SettingType::LowPressureThreshold]) {
            pContext.aRealTime.aTriggeredProblem = Nihtiu::Problem::Emergency;
            strncpy(pContext.aRealTime.aProblemDesc,"Pres below limit-%d",pContext.aRealTime.aInLinePressure);
            pContext.aActuators.aAlarm.emergency(pContext.aRealTime.aProblemDesc);
        }
        else if (pContext.aRealTime.aInLinePressure > pContext.aSettings[Nihtiu::_SettingType::HighPressureThreshold]) {
            pContext.aRealTime.aTriggeredProblem = Nihtiu::Problem::Emergency;
            strncpy(pContext.aRealTime.aProblemDesc,"Pres above limit-%d",pContext.aRealTime.aInLinePressure);
            pContext.aActuators.aAlarm.emergency(pContext.aRealTime.aProblemDesc);
        }

        // Checking some warning "guard" around the pressure thresholds
        
        else if (pContext.aRealTime.aInLinePressure < (pContext.aSettings[Nihtiu::_SettingType::HighPressureThreshold] - 
                                                       pContext.aSettings[Nihtiu::_SettingType::PressureWarningLevel])) {
            pContext.aRealTime.aTriggeredProblem = Nihtiu::Problem::Warning;
            strncpy(pContext.aRealTime.aProblemDesc,"Pres near low limit-%d",pContext.aRealTime.aInLinePressure);
            pContext.aActuators.aAlarm.warning(pContext.aRealTime.aProblemDesc);
        }
        else if (pContext.aRealTime.aInLinePressure < (pContext.aSettings[Nihtiu::_SettingType::HighPressureThreshold] - 
                                                       pContext.aSettings[Nihtiu::_SettingType::PressureWarningLevel])) {
            pContext.aRealTime.aTriggeredProblem = Nihtiu::Problem::Warning;
            strncpy(pContext.aRealTime.aProblemDesc,"Pres near high limit-%d",pContext.aRealTime.aInLinePressure);
            pContext.aActuators.aAlarm.warning(pContext.aRealTime.aProblemDesc);
        }

        // No problems found
        
        else {
            // The alarm reset is automatic, but the SBC that receives the Arduino information
            // must keep a reference on the last alarm triggered.  This just will turn off the Arduino light and
            // sound.
            pContext.aActuators.aAlarm.reset();
            pContext.aRealTime.aTriggeredProblem = Nihtiu::Problem::None;
        }
        return pContext.aRealTime.aTriggeredProblem;
        
    } // Check_Problems

    
    bool Check_Hold(Nihtiu::Context& pContext) {

        bool vHoldPressed = false;

        // Only loops if the hold control line is active
        
        while (!pContext.aSensors.ctrlHoldActive()) {
            delay (pContext.aSettings[Nihtiu::_SettingType::HoldTime]); 
            vHoldPressed = true; // manual bypass so the expiration time will be avoided
        }

        return vHoldPressed;
      
    } // Check_Hold
    

    void Wait_Trigger(Nihtiu::Context& pContext, unsigned long pTimeout, bool pCheckBreath) {

        bool vTriggered = false;

        while (!vTriggered) {
          
            Update_Sensors(pContext);

            // Checks if the patient changed the pressure level
            //

            if (pCheckBreath) {
                if (pContext.aSensors.breathDetected()) {
                    vTriggered = true;
                }              
            }

            // Checks if the timeout time expired
            //
            
            if (!vTriggered) {
                // maximum breath time has passed ... let's force a new breath cycle
                if (pContext.aRealTime.elapsedTime() > pTimeout) {
                    vTriggered = true;
                }
            }
            if (!vTriggered) {
                delay(10); // check 100 times in a second
            }
        }
      
      
    } // Wait_Trigger
    

    // https://www.openanesthesia.org/modes_of_mechanical_ventilation/
    
    
    // ==============
    // Assist-Control Ventilation (ACV)
    // Continouos mandatory ventilation (CMV)
    // Trigger:  exhaust time pass or patient attempt a breath
    // Limit  :  
    // Cycle  :
    

    void OP::volume_ACV     (Nihtiu::Context& pContext) {   // Assist-Control Ventilation

        // WORK IN PROGRESS ... 
        // This mode is not yet finished ... lack what to do when problems are detected...
        //
        // First check problems
        Nihtiu::Problem vProblem = Check_Problems(pContext);

        // Will wait until the expiration time arrives or the patient breath (the first thing happens).
        //
        Wait_Trigger(
            pContext,pContext.aSettings[Nihtiu::_SettingType::ExpiratoryPause], // timeout
            true                                                                // check breath
        );
        
        {
            // The machine will send the InLineFlowGoal quantity of air in the InspiratoryFlowTime quantity
            // of microseconds
            //
            pContext.aActuators.aBVMController.breath(
                pContext.aSettings[Nihtiu::_SettingType::InspiratoryFlowTime],
                pContext.aSettings[Nihtiu::_SettingType::InLineFlowGoal]
            );

            // Then will wait if the hold button have not been pressed (otherwise it will only wait for the
            // hold button to be released).
            //
            if (!Check_Hold(pContext)) {
                delay(pContext.aSettings[Nihtiu::_SettingType::InspiratoryPause]);
            }

            // And will let the bag to return to its natural size in the ExpiratoryFlowTime of microseconds.
            //
            pContext.aActuators.aBVMController.exhaust(pContext.aSettings[Nihtiu::_SettingType::ExpiratoryFlowTime]);

            // The time counter must be updated for the "Eval_Triggered" method to work correctly.
            //
            pContext.aRealTime.updateFinishedTime();
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
