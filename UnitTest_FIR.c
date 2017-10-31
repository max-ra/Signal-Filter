//Should only work x64 Test System
#ifdef __x86_64__

#include <stdlib.h>
#include <stdio.h>
#include "Filter/Filter_FIR.h"

struct FIR_AV_8 VAL;

int main(int argc, char **argv)
{
    
    printf("UnitTest for FIR average 8 16bit implementation for AVR and PIC Microchip.\nAuthor: MRa\nDate: 31.10.2017\n====================\n\nPress any key to continue...");
    
    Filter_AV_8_init(&VAL);
    
    getchar();
    

    
 while(1) {
 
    printf("\nPleas Enter New Value ");
    int newval;
    
    scanf("%d", &newval);
    
    printf("Input Val: %i\n", newval);
    
    Filter_AV_8(&VAL,newval);
    
    printf("new average: %i\nfilter sample pos %i\nfilter total %i\ndata not reliable %i\n",VAL.average,VAL.pointer,VAL.total,VAL.erg_nvalid);
    
    
 }
	
    getchar();
	return 0;
}

#endif