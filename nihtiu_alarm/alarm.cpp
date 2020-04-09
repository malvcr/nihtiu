/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */
 
#include "alarm.h"
#include "defs.h"
#include <Arduino.h>

namespace AlarmNode {
    
    Alarm::Alarm() {
    
        aLCDPtr = new LiquidCrystal(LCD_RS,LCD_EN,LCD_D4,LCD_D5,LCD_D6,LCD_D7);
        // set up the LCD's number of columns and rows:
        aLCDPtr->begin(16, 2);
    
        pinMode(Buzzer_PIN  ,OUTPUT);
        pinMode(RedLED_PIN  ,OUTPUT);
        pinMode(GreenLED_PIN,OUTPUT);
      
    } // Alarm constructor
    
    
    Alarm::~Alarm() {
    
        delete aLCDPtr;
      
    } // Alarm destructor
    


    void Alarm::Warning(char* pText) {
      
        aLCDPtr->clear();

        aLCDPtr->setCursor(0,0);
        aLCDPtr->print("*** Warning ***");
        aLCDPtr->setCursor(0,1);
        aLCDPtr->print(pText);

        tone(Buzzer_PIN,_D);
        delay(100);
        tone(Buzzer_PIN,_E);
        delay(100);
        tone(Buzzer_PIN,_F);
        delay(100);
        tone(Buzzer_PIN,_G);
        delay(100);
        tone(Buzzer_PIN,_A);
        delay(100);
        
        noTone(Buzzer_PIN);
        for (int vIdx=0; vIdx<5; vIdx++) {
            digitalWrite(GreenLED_PIN,HIGH);
            delay(100);
            digitalWrite(GreenLED_PIN,LOW);
            delay(100);
        }
      
    } // Alarm::Warning

    
    void Alarm::Emergency(char* pText) {

        aLCDPtr->clear();

        aLCDPtr->setCursor(0,1);
        aLCDPtr->print(pText);

        for (int vIdx=0; vIdx<3; vIdx++) {

            digitalWrite(RedLED_PIN,HIGH);
            delay(100);
            digitalWrite(RedLED_PIN,LOW);
          
            aLCDPtr->setCursor(0,0);
            aLCDPtr->print("** EMERGENCY **");
            delay(100);
            aLCDPtr->setCursor(0,0);
            aLCDPtr->print(EMPTY_LINE);
            delay(100);

            tone(Buzzer_PIN,_D);
            delay(50);
            tone(Buzzer_PIN,_Dis);
            delay(50);
            tone(Buzzer_PIN,_E);
            delay(50);
            tone(Buzzer_PIN,_F);
            delay(50);
            tone(Buzzer_PIN,_A2);
            delay(50);

            
        }
        aLCDPtr->print("** EMERGENCY **");
        noTone(Buzzer_PIN);

        delay(100);
        
    } // Alarm::Emergency


    void Alarm::SilentMessage  (char* pLine1, char* pLine2) {

        aLCDPtr->clear();
      
        aLCDPtr->setCursor(0,0);
        aLCDPtr->print(pLine1);
        aLCDPtr->setCursor(0,1);
        aLCDPtr->print(pLine2);

        digitalWrite(GreenLED_PIN,HIGH);
        delay(100);
        digitalWrite(GreenLED_PIN,LOW);

        delay(1000);
        
    } // Alarm::SilentMessage


    void Alarm::Message  (char* pLine1, char* pLine2) {

        aLCDPtr->clear();
      
        aLCDPtr->setCursor(0,0);
        aLCDPtr->print(pLine1);
        aLCDPtr->setCursor(0,1);
        aLCDPtr->print(pLine2);

        tone(Buzzer_PIN,100);
        delay(5);
        tone(Buzzer_PIN,120);
        delay(5);
            
        noTone(Buzzer_PIN);
        digitalWrite(GreenLED_PIN,HIGH);
        delay(100);
        digitalWrite(GreenLED_PIN,LOW);

        delay(1000); // don't saturate the NANO without need
        
    } // Alarm::Message

    void Alarm::Reset() {
        aLCDPtr->clear();
        noTone(Buzzer_PIN);
        digitalWrite(GreenLED_PIN,LOW);
        digitalWrite(RedLED_PIN,LOW);
    } // Alarm::Reset

    void Alarm::perform(char pCommand, char* pLine1, char* pLine2) {
          
        switch (pCommand) {
          
            case CMD::Warning: {
                    Warning(pLine1);
                }
                break;
            case CMD::Emergency: {
                    Emergency(pLine1);
                }
                break;
            case CMD::SilentMsg: {
                    SilentMessage(pLine1,pLine2);
                }
                break;
            case CMD::Message: {
                    Message(pLine1,pLine2);
                }
                break;
            case CMD::Off: {
                    Reset();
                }
                break;
        }
        
    } // Alarm::perform

} // AlarmNode namespace
  
