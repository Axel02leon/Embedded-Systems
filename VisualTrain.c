// NAME : AXEL LEON VASQUEZ
// DATE : 7/6/23
// LAB 3
// Youtube : https://youtu.be/3SI4ysgnMnY
// This Program will lead a train through a digital 4 bit either, FOWARD, REVERSE or STOP 


#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>
#include "Four_Digit_Display.h"

typedef enum{ STOP, RUN, REVERSE, MAX_STATE} state_t;
typedef enum{ RED, GREEN} COL; 


void digit(){
_enable_inruption();
Four_digit_init();
}

void init(){                  
 
    P4DIR &= ~BIT1; //	enable
    P4REN |= BIT1;  // enable
    P4OUT |= BIT1;  // enable

    P4IE |= BIT1;   // interrupt
    P4IES |= BIT1;  // condition
    P4IFG &= ~BIT1;

    P2DIR &= ~BIT3; // input
    P2REN |= BIT3;  // enable  resistor
    P2OUT |= BIT3;  // enable pull-up resistor

    P2IE |= BIT3;   // enables interrupt
    P2IES |= BIT3;  // high-to-low trigger 
    P2IFG &= ~BIT3;

  

void colorLED(int color)

    switch (color)
    {
    case 0: // red on, green off
        P1OUT |= BIT0;
        P6OUT &= ~BIT6;

        break;
    case 1: // red off, green on
        P1OUT &= ~BIT0;
        P6OUT |= BIT6;
        break;

           case 2: //red on, green on
              P1OUT |= BIT0;
             P6OUT |= BIT6;
           break;
    }

void casePosition(int position) // cases from 0 to 11 states
{
    four_digit_clear();
    switch (position)
    {
    case 0:
        display_segment(POS_2, SEG_D); // redisplays the position
        display_segment(POS_3, SEG_D);
        display_segment(POS_4, SEG_D);
        break;
    case 1:
        display_segment(POS_1, SEG_D);
        display_segment(POS_2, SEG_D);
        display_segment(POS_3, SEG_D);
        break;
    case 2:
        display_segment(POS_2, SEG_D);
        display_segment(POS_1, SEG_D | SEG_E);
        break;
    case 3:
        display_segment(POS_1, SEG_D | SEG_E | SEG_F);
        break;
    case 4:
        display_segment(POS_1, SEG_A | SEG_E | SEG_F);
        break;
    case 5:
        display_segment(POS_1, SEG_A | SEG_F);
        display_segment(POS_2, SEG_A);
        break;
    case 6:
        display_segment(POS_1, SEG_A);
        display_segment(POS_2, SEG_A);
        display_segment(POS_3, SEG_A);
        break;
    case 7:
        display_segment(POS_2, SEG_A);
        display_segment(POS_3, SEG_A);
        display_segment(POS_4, SEG_A);
        break;
    case 8:
        display_segment(POS_3, SEG_A);
        display_segment(POS_4, SEG_A | SEG_B);
        break;
    case 9:
        display_segment(POS_4, SEG_A | SEG_B | SEG_C);
        break;
    case 10:
        display_segment(POS_4, SEG_B | SEG_C | SEG_D);
        break;
    case 11:
        display_segment(POS_4, SEG_C | SEG_D);
        display_segment(POS_3, SEG_D);
        break;
    }
}



state_t STOP(input_t* input)// stop the digital display
{
    COL = 0;
    stop = 1;
    colorLED(0);

    state_t nextState;

    if (w1)
    { // switch 1 is pressed
        nextState = RUN;
    }
    else
    {
        nextState = stop;
    }
    return nextState;


state_t RUN(input_t* input) // runs the digital display
{
    COL = 1;
    stop  = 1;
    colorLED(1);

    state_t nextState;

    if (sw1)
    { // s1 is press
        nextState = stop;
    }
    if (Sw2)
    { // sw2 is press
        nextState = REVERSE;
    }
    else
    {
        nextState = RUN;
    }
    return nextState;

state_t REVSERSE(input_t* input)
{
    
    colorLED(Green);
    CASEPosition(input* position);

   
    if (input* position == 0)
        input* position = 1;
    else;
        

    if (input*sw1) {
        return stop; // Stop}
    if (input* switch2) // switch 2 changes {
        if (input->direction == RUN) // 
            input->direction = REVERSE;
        else
            input->direction = RUN ;
    }

    return input* COL;
};

void delay() // time set for the digital
{
    volatile long int i = 0;
    for (i; i < 100000; i++)
    {
    }
}

int main(void){
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;     // 
    init();

  
    
    while (1){
    
    if(switch_1()) {
        sw1 = 1;
    } else {
        sw1 = 0;
    }

    if(switch_2()) {
        sw2 = 1;
    } else {
        sw2 = 0;
    }

   ;
        
    if (sw2 == 0)
            change = 1;
        else {
            change = -1;
        }
        if (sw1 == 0)
        {  
            casepos = (casepos+change+2);
            setPosition(casepos);
        }

        delay();
    }
}