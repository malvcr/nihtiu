/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */
 
#include "comm.h"
#include <Arduino.h>

namespace AlarmNode {

    /* IMPORTANT IMPLEMENTATION NOTE
     *  
     * When using this library with the Arduino Mega, it will look for the Serial 1 
     * interface for not to collision with the standard Serial over USB connection.
     * 
     * With all the other Arduinos not having more than one Serial interface, the
     * standard Serial 0 (unique one) will be used.  However, when this happens, the 
     * machine can't use the standard USB data connection, as the Arduino share the 
     * 0 and 1 data lines between the Serial and USB connections.
     */
    
    Comm::Comm(int pSpeed) {
    #ifdef __AVR_ATmega2560__
        Serial1.begin(pSpeed);
    #else
        Serial.begin(pSpeed);
    #endif
    } // Comm constructor
    
#ifdef __AVR_ATmega2560__    


    void LOCAL_PutData(char* pDest, char pCommand, char* pLine1, char* pLine2) {

        pDest[0] = pCommand;

        bool vFinished=false;

        for (int vIdx=0; vIdx<LINE_LEN; vIdx++) {
          
            char vTest = pLine1[vIdx];
            
            if ((vTest == '\0')||(vTest == '\r')) {
                vFinished = true;
            }
            if (vFinished) {
                pDest[1+vIdx]='\32';
            }
            else {
                pDest[1+vIdx]=vTest;
            }
          
        }

        vFinished=false;
        
        for (int vIdx=0; vIdx<LINE_LEN; vIdx++) {
          
            char vTest = pLine2[vIdx];
            
            if ((vTest == '\0')||(vTest == '\r')) {
                vFinished = true;
            }
            if (vFinished) {
                pDest[1+LINE_LEN+vIdx]='\32';
            }
            else {
                pDest[1+LINE_LEN+vIdx]=vTest;
            }
        }
        pDest[BUFFER_LEN]='\0';
      
    } // LOCAL_PutData

    bool Comm::send(char pCommand, char* pLine1, char* pLine2) {
        char vBuffer[BUFFER_LEN+1];
        LOCAL_PutData(vBuffer,pCommand,pLine1,pLine2);
        Serial1.write(vBuffer);
    } // Comm::send
    
#else    

    void LOCAL_GetLine(char* pSource, char* pLine) {
      
        bool vFinished=false;
        
        for (int vIdx=0;vIdx<LINE_LEN;vIdx++) {
          
            char vTest = pSource[vIdx];
            //
            // The \r is usually inserted on the IDE's Serial Monitor as it is not
            // included programatically when sending data from the Mega to the Nano.
            //
            if ((vTest == '\0')||(vTest == '\r')) {
                vFinished = true;
            }
            if (vFinished) {
                pLine[vIdx]='\32';
            }
            else {
                pLine[vIdx]=vTest;
            }
        }
        pLine[LINE_LEN]='\0';
      
    } // LOCAL_GetLine

    
    bool Comm::recv(char& pCommand, char* pLine1, char* pLine2) {
      
        char vBuffer[BUFFER_LEN+1];
        memset (vBuffer,' ',BUFFER_LEN+1);
        
        bool vReceived = false;
        
        if (Serial.available() > 0) {
          
            vReceived    = true;
            int  vReaded = Serial.readBytes((char*)vBuffer,BUFFER_LEN);
            
            pCommand = vBuffer[0];

            if (vReaded > 1) {
                LOCAL_GetLine(vBuffer+1,pLine1);
            }
            else {
                memset(pLine1,'\32',LINE_LEN);
                pLine1[LINE_LEN] = '\0';
                memset(pLine2,'\32',LINE_LEN);
                pLine2[LINE_LEN] = '\0';
            }

            if (vReaded > (LINE_LEN+1)) {
                LOCAL_GetLine(vBuffer+1+LINE_LEN,pLine2);
            }
            else {
                memset(pLine2,'\32',LINE_LEN);
                pLine2[LINE_LEN] = '\0';
            }

            // Any other command will be rejected at this level
            //
            vReceived = 
               ((pCommand == CMD::Message)||
                (pCommand == CMD::SilentMsg)||
                (pCommand == CMD::Warning)||
                (pCommand == CMD::Emergency)||
                (pCommand == CMD::Blind)||
                (pCommand == CMD::Off)||
                (pCommand == CMD::Version));
        }
        return vReceived;
        
    } // Comm:recv

    void Comm::send(const char* pData) {
        Serial.println(pData);
    }
#endif

} // AlarmNode namespace
