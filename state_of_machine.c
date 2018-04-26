 
/* FINAL CODE
 * File:   state_of_machine.c
 * Author: philip
 * version 16.4.18.1
 * Created on 16 April 2018, 14:44
 */
#include <xc.h>
#include "state_of_machine.h"
#include "config.h"

void state_of_machine(int *c_state) // *c_state is initially == VOL state
{ 
  if(*c_state == VOL && SWIP == HI)       // if button not pressed - path 0
    {
        *c_state = VOL;                     // stay in VOL state
        time_out = 0;
        VOL_LED = 1;
        MUTE_LED = 0;
        INPUT_LED = 0;
        SELECT_IP_LED = 0;  
        T1CONbits.TMR1ON = 0;
    }
  else if(SWIP == LO)
  {
      T1CONbits.TMR1ON = 1;
  }
  
  if (SWIP == LO && *c_state == VOL && time_out >= 10 && time_out <= 20)
  {
        *c_state = MUTE;                     // move to MUTE state - path 1
        time_out = 0;  
        VOL_LED = 0;
        MUTE_LED = 1;
        INPUT_LED = 0;
        SELECT_IP_LED = 0;  
        T1CONbits.TMR1ON = 0;
  }
  if (SWIP == HI && *c_state == MUTE)
      {
        *c_state = MUTE;                     // stay in  MUTE state - path 7
        time_out = 0;  
        VOL_LED = 0;
        MUTE_LED = 1;
        INPUT_LED = 0;
        SELECT_IP_LED = 0;  
        T1CONbits.TMR1ON = 0;
        }
  if (SWIP == LO && *c_state == MUTE && time_out >= 10 && time_out <= 20)
  {
      *c_state = VOL;                     // move back to VOL state - path 2
      time_out = 0;  
        VOL_LED = 1;
        MUTE_LED = 0;
        INPUT_LED = 0;
        SELECT_IP_LED = 0;  
        T1CONbits.TMR1ON = 1;
  
  }
  
  if(SWIP == LO && *c_state == VOL)
  {
      T1CONbits.TMR1ON = 1;  
  }
  __delay_ms(20);
  if (SWIP == HI && time_out > 0 && time_out <8)
  {
      *c_state = INPUT;                     // move to INPUT state - path 3
      time_out = 0;  
        VOL_LED = 0;
        MUTE_LED = 0;
        INPUT_LED = 1;
        SELECT_IP_LED = 0;  
        T1CONbits.TMR1ON = 0;
  }
  
  if(*c_state == INPUT && SWIP == HI)       // if button not pressed - path 8
    {
        *c_state = INPUT;                     // stay in INPUT state
        time_out = 0;
        VOL_LED = 0;
        MUTE_LED = 0;
        INPUT_LED = 1;
        SELECT_IP_LED = 0;  
        T1CONbits.TMR1ON = 0;
    }
  
  if (SWIP == LO && *c_state == INPUT && time_out > 0 && time_out <=8)
  {
      __delay_ms(20);
      *c_state = SELECT_IP;                     // move to INPUT state - path 3
      time_out = 0;  
        VOL_LED = 0;
        MUTE_LED = 0;
        INPUT_LED = 0;
        SELECT_IP_LED = 1;  
        T1CONbits.TMR1ON = 0;
  }
  if (SWIP == LO && *c_state == SELECT_IP && time_out > 0 && time_out <=8)
  {
      __delay_ms(20);
      *c_state = VOL;                     // move to INPUT state - path 3
      time_out = 0;  
        VOL_LED = 1;
        MUTE_LED = 0;
        INPUT_LED = 0;
        SELECT_IP_LED = 0;  
        T1CONbits.TMR1ON = 0;
  }
  T1CONbits.TMR1ON = 0;
}
  
 