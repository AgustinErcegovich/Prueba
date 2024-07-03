#include "CRUCE.h"
#include "MKL25Z4.h"
#include "ctype.h"
int i = 0, S1[] = {0, 1, 2}, S2[] = {3, 4, 5}, s1[] = {6, 7}, s2[] = {8, 9};

void inicioSemaforos(){
    SIM -> SCGC5|=SIM_SCGC5_PORTA_MASK; 
    for(i = 0; i < 10; i++){
        PORTA -> PCR[i]|= PORT_PCR_MUX(1);
        PTA -> PSOR|= (0 << i);
    }
}

void Semaforo(int num, char tipo, char color){
    char c = tolower(color);
    if(num == 1){
        if(tipo == 'n'){
            switch (c) {
            case 'r':
                PTA -> PSOR |= (1u << 0);
                delay(40000);
                break;
            case 'a':
                PTA -> PSOR |= (1u << 1);
                delay(10000);
                break;
            case 'v':
                PTA -> PSOR |= (1u << 2);
                delay(300000);
                break;    
            default:
                break;
            }
        } else if(tipo == 'g'){
            switch (c) {
            case 'r':
                PTA -> PSOR |= (1u << 6);
                delay(10000);
                break;
            case 'v':
                PTA -> PSOR |= (1u << 7);
                delay(300000);
                break;    
            default:
                break;
            }
        }
    }
}