/**
 * Nihtiu
 * 
 * (c) 2020 Marco Alvarado
 * 
 * This project has the MIT Licensing.  Check the accompaining LICENSE file.
 * 
 */

#include <Arduino.h>
#include "tools.h"

namespace Tools {

    /**
     * @todo : this procedure must be checked
     */
    size_t split(Text& pSourceRef,char pSeparator,Text* pParts, size_t pMaxParts) {

         memset(pParts,0,pMaxParts*sizeof(Text));

        /**
         * This split implementation differs from others in the sense that
         * it calculates where could be the last possible position to find
         * a separator.  If we find a separator beyond that point, this would
         * be the last separator.
         *
         * This way, we only calculate the difference once, instead of one time
         * for each cycle.
         */

        size_t vSourceLength = strlen(pSourceRef);
        size_t vQty = 0;

        if ((0 == vSourceLength) || (0 == pMaxParts) || (nullptr == pParts)) { // trivial cases
            return 0;
        }
        else {

            char* vCurrentPos  = pSourceRef;
            char* vPreviousPos = nullptr;
            char* vMaxPos      = pSourceRef+vSourceLength-1;

            /**
             * static const size_type npos = static_cast<size_type>(-1)
             *
             * This works because natural overflow, becoming the biggest possible int number.
             */
            while (vCurrentPos != vMaxPos) {

                vCurrentPos = strchr(vPreviousPos,pSeparator);

                if (nullptr == vCurrentPos) {
                    strcpy(pParts[vQty],vPreviousPos);
                }
                else {
                    strncpy(pParts[vQty],vPreviousPos,vCurrentPos-vPreviousPos);

                    if (vCurrentPos > vMaxPos) {
                        vCurrentPos = vMaxPos+1;
                    }
                    else {
                        vPreviousPos = vCurrentPos + 1;
                    }
                }
                vQty++;

            } // while (vCurrentPos != string::npos) {
        }
        return vQty;

    } // split
  
} // Tools namespace
