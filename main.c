/*
 * File:   main.c
 * Author: Ramazan Subasi (Subram)
 *
 * Created on 4 Haziran 2014 Cuma, 12:05
 */

#include <xc.h>
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTRC oscillator; port I/O function on both RA6/OSC2/CLKO pin and RA7/OSC1/CLKI pin)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off)
#pragma config CCPMX = RB0      // CCP1 Pin Selection bit (CCP1 function on RB0)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode disabled)

#define _XTAL_FREQ 4000000

void main (void) {
    ANSEL=0x00;     //
    TRISB=0x04;     //
    PORTB=0x01;
    PSA=1;          //Prescaler is assigned to the WDT
    PS0=1;          //PS Rate 1:32
    PS1=0;
    PS2=1;
    WDTPS0=0;       // WDTPS Rate 1:512
    WDTPS1=0;
    WDTPS2=1;
    WDTPS3=0;
    //___delay_ms(2000); //Brenner kullanýlacaksa aktif edilmelidir.
    while (1) {
        RB1=~RB1;
        while(RB0==0) {
            CLRWDT();
        }
        SLEEP();
    }
}