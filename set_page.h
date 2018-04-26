
/* 
 * File:   set_page.h
 * Author: Phil
 * Comments:
 * Revision history: 1
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef SET_PAGE_H
#define	SET_PAGE_H

#include <xc.h> // include processor files - each processor file is guarded.  
void set_page(uchar memory_mode, uchar page_mode, uchar page_addr);
#endif	