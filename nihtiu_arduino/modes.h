/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#ifndef __MODES_H
#define __MODES_H

#include <Arduino.h>
#include "context.h"

namespace Mode {


    namespace _ID {
        const ID ACV   = 0;
        const ID SIMV  = 1;
        const ID PCV   = 2;
        const ID PSV   = 3;
        const ID PCIRV = 4;
        const ID APRV  = 5;
        const ID PRVC  = 6;
        const ID PAV   = 7;

        const ID _MaxMode = 8;
    }

    using _OP = void (*)(Nihtiu::Context& pContext);
    
    namespace OP {
      
        void volume_ACV     (Nihtiu::Context& pContext); // Assist-Control Ventilation
        void volume_SIMV    (Nihtiu::Context& pContext); // Synchronized Intermittent-Mandatory Ventilation
    
        void pressure_PCV   (Nihtiu::Context& pContext); // Pressure-Controlled Ventilation
        void pressure_PSV   (Nihtiu::Context& pContext); // Pressure Support Ventilation
        void pressure_PCIRV (Nihtiu::Context& pContext); // Pressure Controlled Inverse Ratio Ventilation
        void pressure_APRV  (Nihtiu::Context& pContext); // Airway Pressure Release Ventilation
    
        void dual_PRVC      (Nihtiu::Context& pContext); // Pressure Regulated Volume Control
        void interactive_PAV(Nihtiu::Context& pContext); // Proportional Assist Ventilation
        
    }


    class Manager {
        _OP aData[_ID::_MaxMode]; PROGMEM;
    public:
        Manager();
        virtual ~Manager();

        _OP operator[](ID pId);
        
    }; // Manager class
    
} // Mode namespace

#endif // __MODES_H
