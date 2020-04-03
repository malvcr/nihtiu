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
            sprintf(pContext.aLastResult,"OK|%d|%d|\0",pContext.aRealTime.aInLinePressure,pContext.aRealTime.aInLineFlow);
        }
        else {
            sprintf(pContext.aLastResult,"ER|%d|%d|\0",pContext.aRealTime.aInLinePressure,pContext.aRealTime.aInLineFlow);
        }
        
    } // _toUL
    

    Text& OP::setMode(Nihtiu::Context& pContext, Nihtiu::SettingType pSettingType, Text& pParamValue) {

        return pContext.aLastResult;
        
    } // OP::setMode


    Text& OP::storeProfile(Nihtiu::Context& pContext, Nihtiu::SettingType pSettingType, Text& pParamValue) {
        return pContext.aLastResult;
    } // OP::storeProfile

    
    Text& OP::setProfile(Nihtiu::Context& pContext, Nihtiu::SettingType pSettingType, Text& pParamValue) {
        return pContext.aLastResult;
    } // OP::setProfile

    
    Text& OP::changeBehaviour(Nihtiu::Context& pContext, Nihtiu::SettingType pSettingType, Text& pParamValue) {

        // respirator hold never will go here ... it is very dangerous to work that action remotely
        // only a local button will be avaiable for holding respiration

        if (pSettingType < Nihtiu::_SettingType::_MaxType) {
            _toUL(pContext,pContext.aSettings[pSettingType],pParamValue);
        }
        // STILL STUDYING HOW TO WORK THIS
// ????        ExhalationBlockerActivation =  8, // flag
      
      
        return pContext.aLastResult;
        
    } // OP::changeBehaviour

    
    Text& OP::getData(Nihtiu::Context& pContext, Nihtiu::SettingType pSettingType, Text& pParamValue) {
        return pContext.aLastResult;
    } // OP::getData
    

    Text& OP::reset(Nihtiu::Context& pContext, Nihtiu::SettingType pSettingType, Text& pParamValue) {
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
