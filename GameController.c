//Name:         Axel Leon Vasquez
//Date:         8/9/23
//Assignment:   Lab 5 Game Controller Top Gun
//Youtube:      https://youtu.be/M1YQFhb8FGQ

#include <msp430.h>
#include <stdbool.h>
#include <stdint.h>


void initUART(){
   
    P4SEL0 |= BIT3 | BIT2;  // UART PINS
    P4SEL1 &= ~(BIT3 | BIT2);
   
    UCA1CTLW0 = UCSWRST |UCA1CTLW0 |= UCSSEL__ACLK | UCA1BRO_0| UCSPB_0|
    UCA1BR0 = 3;                             
    UCA1BR1 = 0;
    UCA1MCTLW |= 0x9200; // 9600 rate 
    UCA1CTLW0 &= ~UCSWRST;     
    UCA1IE |= UCRXIE; // Helps ENABLE the interruptions
}
void init(){
     //SW1 On
         P4DIR &= BIT1;
         P4REN |= BIT1;
         P4OUT |= BIT1;      
         P2DIR &= ~BIT3; // Enable P.2       
         P2REN |= BIT3;// Set P2.3 as high 
         P2OUT |= BIT3;
 }
void init(){
      WDTCTL = WDTPW | WDTHOLD;                
        PM5CTL0 &= ~LOCKLPM5;
     init();
  }
void initClOCK(){
    CSCTL4 |= SELA__XT1CLK;
    CSCTL6 |= XT1BYPASS_1 | XTS_0;  // Use LOW-FREQ mode
}
void UART(){
    while(!(UCA1IFG & UCTXIFG));
    UCAQTXBUF = TX;
    int variable;
    float ADCvariable;
    

void initADCART(){
   
     P1SEL1 |= BIT1;
     ADCCTL0 |= ADCSHT_2 | ADCON;        
     ADCCTL1 |= ADCSHP | ADCSSEL_2;             
     ADCCTL2 &= ~ADCRES;
     ADCCTL2 |= ADCRES_2;                
     ADCMCTL0 |= ADCINCH_1 | ADCSREF_0; 
     }
   
}
bool SW1(){
     return ((P2IN & BIT3) == 0){
         
     }
        
bool SW2(){
  return ((P4IN & BIT1) == 0){
  
  }
      
  void processADCUART() {
      while (!(UCA1IFG & UCTXIFG));

      ADCCTL0 |= ADCENC | ADCSC;

      while (ADCCTL1 & ADCBUSY);
      uint16_t ADC_Result = ADCMEM0;

      if (ADC_Result >= 255) {
          ADC_Result = 254;
      }

      sendUART(ADC_Result);

      __delay_cycles(500);
  } 
  
  
  
  
  
#pragma vector=USCI_A1_VECTOR
__interrupt void PORT1_ISR(void)
{
  UCA1TXBUF = UCA1RXBUF; // no flags
 
 P2DIR &= ~BIT3;
 
}

int main(void)

WDTCTL = WDTPW | WDTHOLD;
  PM5CTL0 &= ~LOCKLPM5;

  initUART();
  initSwitches();
  initCLOCK();
  initADCURT();


  while (1) {
      processADCUART();

      if (SW1Pressed() || SW2Pressed()) {
          sendUART(255);
          UCA1IE &= ~UCRXIE; // Disable UART RX interrupt 
          delay_cycles(500);
          UCA1IE |= UCRXIE;  // ENABLE UART RX interrupt
      }

      delay_cycles(500);
  }
}

  __enable_interrupt();
  while(1){
      ADCUART();
      if((SW1() || SW2() -> true ){
          UART(255);
      UCA1FG =0; 
      
  }
}
