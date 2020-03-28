/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project hast the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#ifndef __NIHTIU_H
#define __NIHTIU_H

#include <Arduino.h>
#include "actions.h"
#include "modes.h"

namespace Nihtiu {

    class App {

        Action::Manager aActionsManager;
        Mode::Manager   aModesManager;
        Context         aContext;
        
    protected:

        bool discoverAction(Action::ID& pActionID, ParamType& pParamType, Text& pParamValue);

        /**
         * Indicates if the reset line is active (and cleans it for further checing).
         */
        bool flag_resetted();


    public:

        App();
        ~App();

        void setup();

        void body();
    
    }; // App class

} // Nihtiu namespace

#endif // __NIHTIU_H
