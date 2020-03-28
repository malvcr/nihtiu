/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#include "actions.h"
#include "nihtiu.h"

namespace Action {

    // ==============

    void _toUL(Nihtiu::Context& pContext,unsigned long& pDestValue,Text& pSourceValue) {
            
        char* vEndPtr;
        
        pDestValue = strtoul(pSourceValue,&vEndPtr,10);
        if ('\0' == vEndPtr[0]) {
            sprintf(pContext.aLastResult,"OK|%d|%d|\0",pContext.aRealTime.aInLinePresure,pContext.aRealTime.aInLineFlow);
        }
        else {
            sprintf(pContext.aLastResult,"ER|%d|%d|\0",pContext.aRealTime.aInLinePresure,pContext.aRealTime.aInLineFlow);
        }
        
    } // _toUL
    

    Text& OP::setMode(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue) {

        return pContext.aLastResult;
        
    } // OP::setMode


    Text& OP::storeProfile(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue) {
        return pContext.aLastResult;
    } // OP::storeProfile

    
    Text& OP::setProfile(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue) {
        return pContext.aLastResult;
    } // OP::setProfile

    
    Text& OP::changeBehaviour(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue) {

        // respirator hold never will go here ... it is very dangerous to work that action remotely
        // only a local button will be avaiable for holding respiration

        switch (pParamType) {

            case Nihtiu::ParamType::InspiratoryFlowTime : {
                    _toUL(pContext,pContext.aSettings.aInspiratoryFlowTime,pParamValue);
                }
                break;

            case Nihtiu::ParamType::ExpiratoryFlowTime : {
                    _toUL(pContext,pContext.aSettings.aExpiratoryFlowTime,pParamValue);
                }
                break; 

            case Nihtiu::ParamType::InspiratoryPause : {
                    _toUL(pContext,pContext.aSettings.aInspiratoryPause,pParamValue);
                }
                break;

            case Nihtiu::ParamType::ExpiratoryPause : {
                    _toUL(pContext,pContext.aSettings.aExpiratoryPause,pParamValue);
                }
                break;

            case Nihtiu::ParamType::InLinePresureGoal : {
                    _toUL(pContext,pContext.aSettings.aInLinePresureGoal,pParamValue);
                }
                break;

            case Nihtiu::ParamType::InLineFlowGoal: {
                    _toUL(pContext,pContext.aSettings.aInLineFlowGoal,pParamValue);
                }
                break;

            case Nihtiu::ParamType::HighPressureThreshold: {
                    _toUL(pContext,pContext.aSettings.aHighPressureThreshold,pParamValue);
                }
                break;

            case Nihtiu::ParamType::LowPressureThreshold: {
                    _toUL(pContext,pContext.aSettings.aLowPressureThreshold,pParamValue);
                }
                break;

            case Nihtiu::ParamType::HoldTime: {
                    _toUL(pContext,pContext.aSettings.aHoldTime,pParamValue);
                }
                break;


            case Nihtiu::ParamType::BVMTestSpeed: {
                    _toUL(pContext,pContext.aSettings.aBVMTestSpeed,pParamValue);
                }
                break;

            case Nihtiu::ParamType::BVMPressure: {
                    _toUL(pContext,pContext.aSettings.aBVMPressure,pParamValue);
                }
                break;

            default: {
            }
          
        } // switch (pParamType

        // STILL STUDYING HOW TO WORK THIS
// ????        ExhalationBlockerActivation =  8, // flag
      
      
        return pContext.aLastResult;
        
    } // OP::changeBehaviour

    
    Text& OP::getData(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue) {
        return pContext.aLastResult;
    } // OP::getData
    

    Text& OP::reset(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue) {
        return pContext.aLastResult;
    } // OP::reset


    Text& OP::hold(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue) {
        delay(pContext.aSettings.aHoldTime);
        return pContext.aLastResult;
    } // OP::reset

    
    // ==============
    
    Manager::Manager() {

        aData[_ID::Continue]        = nullptr; // not used
        aData[_ID::ChangeBehaviour] = OP::changeBehaviour;
        aData[_ID::GetData]         = OP::getData;
        aData[_ID::Reset]           = OP::reset;
        aData[_ID::SetMode]         = OP::setMode;
        aData[_ID::StoreProfile]    = OP::storeProfile;
        aData[_ID::SetProfile]      = OP::setProfile;      
        aData[_ID::Hold]            = OP::hold;
        
    } // Manager constructor

    
    Manager::~Manager() {
    } // Manager destructor

    
    _OP Manager::operator[](ID pId) {
      
        if ((pId > 0) && (pId < _ID::_MaxAction)) {
            return aData[pId];
        }
        else {
            return nullptr;
        } 
    }; // Manager::operator[]

    // ==============
  
} // Action namespace
