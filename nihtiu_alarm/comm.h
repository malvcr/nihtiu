/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */
 
#ifndef __COMM_H
#define __COMM_H

#include "defs.h"

namespace AlarmNode {
    
    class Comm {
    public:
        Comm(int pSpeed = DFLT_SPEED);

#ifdef __AVR_ATmega2560__
        /**
         * Sends an alarm command with data to the Alarm system.
         * 
         * The alarm can be one of the following types (known as "commands"):
         * 
         * CMD::Message   - An information message (uses two 16 character text lines)
         * CMD::SilendMsg - An information message with the 16 character text but without any noise
         * CMD::Warning   - A  warning message (uses one 16 character text line)
         * CMD::Emergency - An emergency message (uses one 16 character text line)
         * CMD::Off       - Turn off the previous provided message
         * CMD::None      - No particular behaviour
         * 
         * @param pCommand The alarm command we want to send to the alarm
         * @param pLine1   First text line for the alarm display
         * @param pLine2   Possible Second text line for the alarm display
         */
        bool send(char pCommand, char* pLine1, char* pLine2);
#else
        /**
         * Receives a command to be processed by the alarm, and correspond to the data was 
         * provided by another Arduino using the send command.
         * 
         * Check the send documentation for details about the parameters.
         */
        bool recv(char& pCommand, char* pLine1, char* pLine2);

        /**
         * Send textual data to the Master (Arduino Mega).
         */
        void send(const char* pData);
#endif
            
    }; // Comm

} // AlarmNode namespace

#endif // __COMM_H
