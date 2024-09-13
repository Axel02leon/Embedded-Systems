// Name:         Axel Leon Vasquez
// Date:         7/31/2023
//Assignment:    Lab 4
//Youtube: https://youtu.be/dTrYCCoyFyc


#include <msp430.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {stopstate, gostate , state_num,} state_t;
typedef enum { RED, GREEN} color_t; 
typedef struct { 
    int switch1;
    int direction;
} input_t;


void init(){
    
    P1DIR |= BIT4; // Buzzer

    //right button
    P4DIR &= ~BIT1; //P4.1 = input 0 
    P4REN |= BIT1; //
    P4OUT |= BIT1; //
    P4IE |= BIT1;
    P4IES |= BIT1;
    P4IFG &= ~BIT1;
    __enable_interrupt();// is the #pragm
    float getDistance();// is the ultrasonic sensor distance from object to sensor
    

}

void RedCOLOR(int RED){ // indicates it stops or does not run
    switch (int RED)
    case 0: P6OUT |BIT6;
            break;
            
    case 1: P6OUT &= ~BIT6;
            break;

void GreenCOLOR(int GREEN){ // indicates that it turns on and is buzzing
    switch (int GREEN)
    case 0: P6OUT |BIT6;
               break;
               
    case 1: P6OUT &= ~BIT6;
               break;
}

void buzzer(int buzzer){  // buzzer control 
    switch (int buzzer)
        case 0: P2OUT |BIT1;
                break;
                   
        case 1: P2OUT &= ~BIT1;
                break;
    }
float getDistance(){ // distance and delay cycle
    
    TB0R = 0;
    P6DIR |= BIT3;//output on 6 BIT 3
    P6OUT |= BIT3;
    
    
    __delay_cycles(10);
    P6OUT &= ~BIT3;
    P6DIR &= ~BIT3;

    while ((P6IN & BIT3) == 0);
            TB0CTL = TBSSEL__SMCLK | MC__CONTINOUS;
       }

    while ((P6IN & BIT3) == 0 );
            TB0CTL = TBSSEL__SMCLK | MC__STOP;
       }
   float Num = 0;         
   float  floatsec = Num * 0.000001
            

   return distance;
  
   }
   
   
typedef struct{
    bool rightbuttonbuzzer;

} inputs_t;

bool righttbuttonbuzzer(){
    int rightbutton = P4IN & BIT1;
    _delay_cycles(100);
        return (P4IN & BIT1) == 0;
    }
    return false;
}


int main(void){
 
    
 WDTCTL = WDTPW | WDTHOLD;
 PM5CTL0 &= ~LOCKPM5; 

    inputs_t inputs;
    inputs.rightbuttonbuzz = false;


    init();
    while(1){
        switch(gostate){
        case gostate:
            nextState = gostate(&inputs);
            break;
        case stopstate:
            nextState = stopstate(&inputs);
            break;
        case num_state:
            nextState = num_state(&inputs);
            break;
        }
        inputs.rightbuttonbuzzer = rightbutton();
        
        rightbutton = false;
        num_state = gostate;
    }
}

state_t gostate(inputs_t* inputs){ // state from red to green 
    RedCOLOR = true;
    GreenCOLOR = false;
    nosound = false;

    if (inputs*gostate){
        inputts*righttButtonbuzzer = false;
        return gostate;
    }

    else{
        return stopstate;
    }
}

}

void nosound(int sound){ // creating no sound after turning green
    switch (int sound)
        case 0: P1OUT |BIT4;
                   break;
                   
        case 1: P1OUT &= ~BIT4;
                   break;
    }

#pragma vector=PORT4_VECTOR // incepction// 
__interrupt void ussISR(){
    
    rightbutton = (P4IN & BIT1) == 0

    P4IFG &= ~BIT1;
 if(!(P4IRS & BIT1)) {
     TBOCTL = TBSSEL_2 
     P4IES |=BIT1;
 }
 else{
     TB0CTL - TBCLR;
     
     
 }
}

