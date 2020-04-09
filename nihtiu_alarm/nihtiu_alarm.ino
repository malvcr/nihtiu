/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#include "alarm.h"
#include "comm.h"

#define VERSION "1.0"

AlarmNode::Alarm gAlarm;   // Alarm behaviour
AlarmNode::Comm* gComm;    // Communications
char             gCommand; // Command

void setup() {
    gComm    = new AlarmNode::Comm();
    gCommand = CMD::None;
}

void loop() {

    char vLine1[LINE_LEN+1];
    char vLine2[LINE_LEN+1];

    char vNewCommand;

    bool vReceived = false;
    
    if (gComm->recv(vNewCommand,vLine1,vLine2)) {
        if (CMD::Version == vNewCommand) {
            gComm->send(VERSION);
        }
        else {
            vReceived = true;
            gCommand  = vNewCommand;
        }
    }
    gAlarm.perform(gCommand,vLine1,vLine2);
    
} // loop
