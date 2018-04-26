
/* 
 * File:  send_spi_byte.h 
 * Author: Phil
 * Comments:
 * Revision history: 1
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SEND_SPI_BYTE
#define	SEND_SPI_BYTE

#include <xc.h> // include processor files - each processor file is guarded.  

void send_spi_byte(uchar byte);
#endif	