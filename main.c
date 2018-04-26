/* FINAL CODE
 * File:   main.c
 * Author: philip
 * version 16.4.18.1
 * Created on 27 March 2018, 20:29
 */


#include <xc.h>
#include "main.h"
#include "config.h"
#include "init_ports.h"
#include "ioc_enable.h"
#include "init_TMR1.h"
#include "config_oled.h"
#include "clear_oled.h"
#include "splash_screen.h"
#include "set_usart.h"
#include "putch.h"
#include "transmit_character.h"
#include "transmit_data.h"
#include "setup_vol_scrn.h"
#include "write_character.h"
#include "bar_graph.h"
#include "split_digits.h"
#include "get_digit.h"
#include <stdio.h>
#include "state_of_machine.h"
void main(void) 
{
 init_ports(); 
 set_usart();  
 config_oled();
 clear_oled();
 splash_screen();
 __delay_ms(2000);
 clear_oled();
 setup_vol_scrn();
 init_TMR1();
 int next_state = VOL;
 int current_state = VOL;
 ioc_enable();    
 

 
 printf("hello Tonie xxx\n");
 char ton[] = " Finite state machine - mini box little head\n";
 transmit_character(&ton[0]);
 printf("\n");
 printf( "Current_state = %d\n", current_state);
 
 while(1)
 {
     state_of_machine(&current_state);
     if(next_state != current_state)
     {
        printf(" current_state = %d\n", current_state);
        next_state = current_state;
        printf("NEW time_out = %d\n", time_out);
        printf("\n");
        bar_graph();
                split_digits();
                if(count >=0 && count <95)
                {
                    write_character(&minus[0], 0x0f,0xb3);
                }
            else
                {
                    write_character(&space[0],0x0f,0xb3);
                }   
            get_digit(tens, 0x1f);
            get_digit(units, 0x2f); 
            write_character(&d[0],0x3f,0xb3);
            write_character(&B[0],0x4f,0xb3);
        __delay_ms(500);
     }
 }
    
}
