/*
 * File:   ioc_enable.c
 * Author: philip
 *
 * Created on 16 April 2018, 19:43
 */


#include <xc.h>

void ioc_enable(void) 
{
    INTCONbits.GIE = 1;         // enable global interrupts
    INTCONbits.INTE = 1;       // enable external interrupt on PORTAbits.RA2 pin 17
    OPTION_REGbits.INTEDG = 0;  //interrupt of falling edge of DT
}

