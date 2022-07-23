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

 // count until maximum 

    for (p = 1; p < (long unsigned int) ~(0x0); p++) {

// continue

    // map connections from outputs

        r = p;

        for (n = 1; n < MAXCHIPS; n++ ) {

            ip[n] = (int) (r & 0x0F);

            r = r >> 4;

            }

    // map connections for inputs

    for (q = 1; q < ((long unsigned int) ~(0x0) / 2 + 1) ; q++ ) {

        r = q;

        for (k = 0; k < NANDS*2; k++) {

            in[n] = (int) (r & 0x03);

            r = r >> 2;

            }

    // run some cycles

        for (m = 0, n = 0; n < MAXCYS; n++, m++ ) {

    // resolve next state, ip[x] maps 0, 1, or one of op[x-2]
        
            for (k = 0; k < NANDS; k++ ) {
            
                i = k * 2;
            
                j = i + 1;

                if (in[i] == 3 || in[j] == 3) {
                    
                    np[k] = 0;
                    
                    continue;
                    
                    }

                vi = (in[i] > 1) ? op[ip[i]] : in[i] ;

                vj = (in[j] > 1) ? op[ip[j]] : in[j] ;

                np[k] = ! ( vi | vj ) & 0x01;

                }
    
    // maps output ports as bits in a unsigned long int
    // for easy verifiy cycles
    //
        for (q = 0, k = 0; k < NANDS; k++ ) {
        
            op[k] = np[k];
            
            q = np[k] ? (q | np[k] << k) : q;

            }

    // maps the results

        v[m++] = (unsigned int) q;
    
    // detect cycles

        for (i = 0; i < m; i++) {

            for (j = i + 1; j < m; j++) {

                d = j - i;

                for (k = 0; k < d; k++)  if (v[i+k] != v[j+k]) break;

                if ( k == d) n = MAXCYS; 

                } 
             } 
        

        if (m > MINCYS) {

            printf ("\n%lu|%lu|%u",p,q,m);

            for (k = 0; k < m; k++) printf ("%02d>",v[k]); 

            }                                                                                                       

        }

        }

        }

    return (0);
    }

