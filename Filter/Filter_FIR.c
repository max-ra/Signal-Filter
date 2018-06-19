// ##### Including #####

#include "Filter_FIR.h"

// ##### Settings #####


// ##### definition #####
	

// ##### Status definition #####
	

// ##### variable #####


// ##### function #####

void Filter_AV_8_init (struct FIR_AV_8 *Data) {
   uint_fast8_t i;
   
   for (i = 0; i < 8; i++) {
    Data->Samples[i] = 0;
    Data->pointer = 0;
    Data->average = 0;
    Data->total = 0;
    Data->erg_nvalid = 1;
   }
}

void Filter_AV_8(struct FIR_AV_8 *Data, uint_fast16_t *Sample) {
//Lösche Ältesten Eintrag aus der Liste und Positioniere dort den Neuesten 
   Data->total -= Data->Samples[Data->pointer];
    Data->total += *Sample;
    Data->Samples[Data->pointer] = *Sample;
    
//Signalisiere das Die Ergebnisse Valide sind (Der Speicher einmal komplett volgelaufen ist. 
    if (Data->erg_nvalid) {
        if (Data->pointer == 7) {
            Data->erg_nvalid = 0;
        }
    }
    
//Schiebe Pointer auf den Nächste Eintrag. Modulo (%) Sorgt dafür das nach der 7 Automatich auf 0 gesprungen wird. 
    Data->pointer = (Data->pointer + 1) % 8;
    
//Divison durch 8. Die verschiebeopperation ist eine Divisoin von 2 ^n n ist in diesem Beispiel 3 -> 2^3 = 8.
    Data->average = Data->total >> 3;
}