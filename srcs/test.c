#include <stdio.h>
#include <stdlib.h>

/*
search for solutions for nand connection matrices

model for a bunch of 74hc00

Alvaro Barcellos @2022

*/

// number of ports nand

    #define MAXCHIPS 16

    #define NANDS 64

// number of values in cycles

    #define MAXCYS 200

    #define MINCYS 10

/*

rules:

    each nand have 2 input and 1 output,
    each input could only have one connection
    each output could have many connections
    also input could be pull-up or pull-down

    model as discrete clock events

    unsigned long int maps outputs, 

    gcc long int is 8 bytes, 64 bits, 

    max gates is 64 or 16 x 4 gates, 74hc00

    for N nands: 2*N inputs, N outputs
    
    each input could be [0=gnd, 1=vcc, 2 .. NANDS+2]

*/

int main (int argc, char * argv[]) {

// generic values
    
    int n, m, i, j, k, d;
    
    int in[NANDS*2], ip[NANDS*2], op[NANDS], np[NANDS];

    long unsigned int p, q, r, s, vi, vj;

    unsigned int v[MAXCYS];
 
/*

 a long int uses 8 bytes in gcc 9.4.0 8 * 8 = 64 bits, 

 a 74hc00 have 4 gates nands, 8 inputs, 4 outputs

 64 bits / 4 gates = 16 chips, a long int could map 16 chips

 each input connection could be mapped by 2 bits as

 0=pulldown, 1=pullup, 2=inputs, 3=tristate

 64 bits/ 2 = 32, a long int could map 32 inputs 

 could use long ints to map all combinations of 16 chips

 */

    // map connections from outputs

    m = 0;

    for (p = 1; p < (long unsigned int) ~(0x0); p++) {

    // map connections for inputs

    for (q = 1; q < ((long unsigned int) ~(0x0) / 2 + 1) ; q++ ) {


            printf ("\n%lu|%lu|%u",p,q,m);

        }

    }

    return (0);
    }

