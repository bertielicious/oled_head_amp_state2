
/* 
 * File:   write_character.h
 * Author: Phil
 * Comments:
 * Revision history: 1
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef WRITE_CHARACTER
#define	WRITE_CHARACTER

#include <xc.h> // include processor files - each processor file is guarded.  
uchar write_character(uchar *ptr, uchar inc, uchar page);

#endif	/* XC_HEADER_TEMPLATE_H */