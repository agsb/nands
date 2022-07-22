#include <stdio.h>
#include <stdlib.h>

/*
search for olutions for nand connection matrices

model for a bunch of 74hc00

Alvaro Barcellos @2022

*/

struct NAND {
    int next;
    int value;
    int port[2];
    };

typedef struct NAND nand;

// number of ports nand

    #define NANDS 64

// max number of values in cycles

    #define MAXBCK 200

int main (int argc, char * argv[]) {

// generic values

   int n, m, p, q, i, j, k;

/*

rules:

    each nand have 2 input and 1 output,
    each input could only have one connection
    each output could have many connections
    also a input could be pull-up or pull-down

    model as discrete clock events

    unsigned long int maps outputs, 

    gcc long int is 8 bytes, 64 bits, 

    max gates is 64 or 16 x 4 gates, 74hc00

    for N nands: 2*N inputs, N outputs
    
    each input could be [0=gnd, 1=vcc, 2 .. NANDS+2]

*/

    
    int in[NANDS*2], op[NANDS], np[NANDS];

    unsigned long int p, pp, q, m, v[MAXBCK];
 
    for (in[0] = 0; in[0] < 66; in[0]++) {
        
    pp = 0;

    for (p = 1; pp < p; p++) {

        pp = p;


        q = p;

        for (n = 0; n < 16; n++ ) {

            m = q & 0x0F;
            
            q = q >> 4;
            
            ip[n] = m;

            }


        kk = 0;
 
        
        for (k = 0; k < NANDS; k++ ) {
            
            i = k * 2;
            
            j = i + 1;

            vi = (ip[i] > 1) ? op[ip[i] - 2] : ip[i] ;

            vj = (ip[j] > 1) ? op[ip[j] - 2] : ip[j] ;

            np[k] = ! ( vi | vj ) & 0x01;

            }
    
    // maps output ports as bits in a unsigned long int

        q = 0;

        for (k = 0; k < NANDS; k++ ) {
        
            op[k] = np[k];
            
            q = np[k] ? (q | np[k] << k) : q;

            }

        m[kk++] = q;
    
        }

    return (0);
    }

