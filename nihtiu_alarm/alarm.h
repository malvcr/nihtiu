/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */
 
#ifndef __ALARM_H
#define __ALARM_H

#include <LiquidCrystal.h>

namespace AlarmNode {
    
    class Alarm {
        LiquidCrystal* aLCDPtr;
    protected:
    
        void Warning      (char* pText);
        void Emergency    (char* pText);
        void SilentMessage(char* pLine1, char* pLine2);
        void Message      (char* pLine1, char* pLine2);
        
        void Warning  (const char* pText) {
            Warning(const_cast<char*>(pText));
        }
        void Emergency(const char* pText) {
            Emergency(const_cast< char*>(pText));
        }
        void SilentMessage  (const char* pLine1, const char* pLine2) {
            SilentMessage(const_cast<char*>(pLine1),const_cast<char*>(pLine2));
        }
        void Message  (const char* pLine1, const char* pLine2) {
            Message(const_cast<char*>(pLine1),const_cast<char*>(pLine2));
        }

        /**
         * Turn off the previous alarm command.
         */
        void Reset();
    
    public:
    
        Alarm();
        virtual ~Alarm();

        /**
         * Will "play" the alarm type according the provided pCommand.
         * 
         * Only the CMD::Message and CMD::SilendMessage will use the pLine2 data for
         * the second data displayed line.
         */
        void perform(char pCommand, char* pLine1, char* pLine2);
    
    }; // Alarm class

} // AlarmNode namespace

#endif // __ALARM_H
