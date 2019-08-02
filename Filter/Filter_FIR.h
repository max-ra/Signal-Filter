#ifndef FILTER_FIR_H
#define	FILTER_FIR_H

// ##### Including #####
//#include <stdint.h>
#include "../../../global.h"

/** Inspired by stevenvh (https://electronics.stackexchange.com/users/2064/stevenvh) Post https://electronics.stackexchange.com/questions/42734/fastest-moving-averaging-techniques-with-minimum-footprint */


// ##### Settings #####


// ##### definition #####

/** Average over 8 16bit. */
typedef struct {
    uint_fast16_t Samples[8];     /**< Speicher der Messwerte. */
    uint_fast16_t average;        /**< Mittelwert aus den Samples. */
    uint_fast32_t total;          /**< Sammples aufsummiert. */
    uint_fast8_t pointer;        /**< Zeigt auf den Aeltesten Sampel Eintrag. */
    unsigned erg_nvalid : 1;      /**< 0 Wenn das erste Mall alle sampels in den Speicher eingelesn wurde und den average Ergebnissen vertraut werden kann. */
} FIR_AV_8;
	

// ##### Status definition #####
	

// ##### variable #####


// ##### function #####

void Filter_AV_8_init (FIR_AV_8 *Data);

/** FIR Filter Average over 8 16bit.
 *  param[in] Data Filter Speicher Struktur.
 *  param[in] Sample Neuer Messwert der Verechnet werden muss */
void Filter_AV_8 (FIR_AV_8 *Data, uint_fast16_t *Sample);

#endif	/* FILTER_FIR_H */