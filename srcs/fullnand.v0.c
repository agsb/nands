#include <stdio.h>
#include <stdlib.h>

/*
search for solutions for nand connection matrices

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
    
    int in[NANDS*2], op[NANDS], np[NANDS];

    unsigned long int p, pp, q, qq, v[MAXCYS];
 
//
// long int uses 8 bytes in gcc 9.4.0
// 8 * 8 = 64 bits, by 4 gates nand by 74hc00,
// 64 / 4 = 16, a long int could map 16 chips

// to not do a 16 level nested for, 
// using a long int to map all combinations
//

// count until maximum 

    pp = 0;

    for (p = 1; pp < p; p++) {

        pp = p;

// continue


    // map connections, not using pulls to 0 or 1, only from outputs

        q = p;

        for (n = 0; n < MAXCHIPS; n++ ) {

            ip[n] = (int) (q & 0x0F);

            q = q >> 4;

            }

    // run some cycles

        for (m = 0, n = 0; n < MAXCYS; n++, m++ ) {

    // resolve next state, ip[x] maps 0, 1, or one of op[x-2]
        
            for (k = 0; k < NANDS; k++ ) {
            
                i = k * 2;
            
                j = i + 1;

                vi = (ip[i] > 1) ? op[ip[i] - 2] : ip[i] ;

                vj = (ip[j] > 1) ? op[ip[j] - 2] : ip[j] ;

                np[k] = ! ( vi | vj ) & 0x01;

                }
    
    // maps output ports as bits in a unsigned long int
    // for easy verifiy cycles
    //
        q = 0;

        for (k = 0; k < NANDS; k++ ) {
        
            op[k] = np[k];
            
            q = np[k] ? (q | np[k] << k) : q;

            }

    // maps the results

        v[m++] = q;
    
    // detect cycles

        for (i = 0; i < m; i++) {

            for (j = i + 1; j < m; j++) {

                d = j - i;

                for (k = 0; k < d; k++)  if (v[i+k] != v[j+k]) break;

                if ( k == d) n = MAXCYS; 

                } 
             } 
        

        if (m > MINCYS) {

            printf ("\n%04d|%02d|",m,c);

            for (k = 0; k < 8; k++) printf ("%1d:", ip[k]);

            for (k = 0; k < m; k++) printf ("%02d>",ds[k]); 

            }                                                                                                       

        }

    return (0);
    }

