
/* 
 * File:   ioc_enable.h
 * Author: Phil
 * Comments: allows rotary encoder to trigger an edge triggered interrupt
 * Revision history: 1
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef IOC_ENABLE
#define	IOC_ENABLE

#include <xc.h> 
void ioc_enable(void);
#endif	
