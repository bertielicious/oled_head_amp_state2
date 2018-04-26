/*
 * File:   init_ports.c
 * Author: philip
 *
 * Created on 24 April 2018, 18:40
 */


#include <xc.h>
#include "init_ports.h"
#include "config.h"
void init_ports(void) 
{
    
    
    /*setup internal clock oscillator*/
    OSCCONbits.SCS = 1;     // internal oscillator used for system clock
    OSCCONbits.IRCF2 = 1;   // 4MHz clock frequency
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 0;
    
    
    
    TRISAbits.TRISA0 = 0;   // diagnostic LED for Interrupt service routine
    TRISBbits.TRISB4 = 0;   // VOL STATE RED LED pin 13
    TRISCbits.TRISC3 = 0;   // MUTE STATE GREEN LED pin 7 
    TRISCbits.TRISC6 = 0;   // INPUT STATE YELLOW LED pin 8
    TRISCbits.TRISC4 = 0;   // SELECT_IP BLUE LED pin 6
    
    /*rotary encoder switch input*/
    TRISCbits.TRISC0 = 1;   // SWIP input pin 16
    
    /*serial communication pin */
    TRISBbits.TRISB7 = 0;   // serial data out TX pin 9
    
    /*clear all output pins */
    PORTBbits.RB4 = 0;
    PORTCbits.RC4 = 0;
    PORTCbits.RC3 = 0;
    PORTCbits.RC6 = 0;
    PORTCbits.RC7 = 0;
    PORTCbits.RC1 = 0;
    PORTBbits.RB6 = 0;
    
    /*OLED driver pins*/
    
    /*make SPI pins all outputs*/
    TRISBbits.TRISB6 = 0;       // SCK serial clock output pin 11
    TRISCbits.TRISC7 = 0;       // SDA serial data out pin 9
    TRISCbits.TRISC1 = 0;       // RESET pin 15
    TRISCbits.TRISC2 = 0;       // D/C pin 14
    TRISAbits.TRISA5 = 0;       // CS chip select (active low) pin 2
    
    /* SPI setup where uController in Master mode, OLED display will be a slave
     SSPSTAT REG (sync serial port status register*/
    SSPSTATbits.SMP = 1;    // data sampled at end of output time
    SSPSTATbits.CKE = 0;    // data transmitted on falling edge of SCK, CKP = 0 
    /* SSPCON REG (sync serial port control register*/
    SSPCONbits.WCOL = 0;    // cleared for no collision detection required
    SSPCONbits.SSPOV = 0;   // cleared for no overflow detection required
    SSPCONbits.SSPEN = 1;   // set to enable serial port pins SCK and SDO as serial port pins
    SSPCONbits.CKP = 1;     // set means idle state of clock is HIGH
    SSPCONbits.SSPM3 = 0;    // SPI master mode, clock = fosc/4
    SSPCONbits.SSPM2 = 0;
    SSPCONbits.SSPM1 = 0;
    SSPCONbits.SSPM0 = 0;
    
     /*make interrupt on change pins inputs*/
    TRISCbits.TRISC5 = 1;       // CLK input pin 5
    TRISAbits.TRISA2 = 1;       // DT input pin 17
            
}
