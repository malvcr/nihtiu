/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project hast the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#ifndef __ACTIONS_H
#define __ACTIONS_H

#include <Arduino.h>
#include "modes.h"
#include "context.h"

namespace Action {

    namespace _ID {

        const ID Continue        = 0;
        const ID ChangeBehaviour = 1;
        const ID GetData         = 2;
        const ID Reset           = 3;
        const ID SetMode         = 4;
        const ID StoreProfile    = 5;
        const ID SetProfile      = 6;
        const ID Hold            = 7;

        const ID _MaxAction      = 8;
        
    } // _ID namespace


    namespace OP {

        /**
         * Sets the machine working mode
         */
        Text& setMode     (Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue);
        Text& storeProfile(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue);
        Text& setProfile  (Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue);

        /**
         * Changes the specified parameter value, that will have some impact in how the 
         * machine works.
         */
        Text& changeBehaviour(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue);

        /**
         * Obtain the current value for a specified parameter
         */
        Text& getData        (Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue);

        /**
         * Return the machine to the standard behaviour
         */
        Text& reset          (Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue);

        /**
         * Wait "some time" before continuing with the next breath cycle.
         */
        Text& hold           (Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue);
        
    } // OP namespace

    using _OP = Text& (*)(Nihtiu::Context& pContext, Nihtiu::ParamType pParamType, Text& pParamValue);

    class Manager {
        _OP aData[_ID::_MaxAction]; PROGMEM;
    public:
        Manager();
        virtual ~Manager();

        _OP operator[](ID pId);
        
    }; // Manager class
    
} // Action namespace

#endif // __ACTIONS_H
