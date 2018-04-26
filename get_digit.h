/* 
 * File:   get_digit.h
 * Author: PG
 * Comments: prints number to oled for given digit supplied
 * Revision history: 0.1
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef GET_DIGIT_H
#define GET_DIGIT_H

#include <xc.h> // include processor files - each processor file is guarded.  

void get_digit (uchar digit, uchar shuffle);
#endif	/* GET_DIGIT_H */

