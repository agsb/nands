#include <stdio.h>
#include <stdlib.h>

#define MAX 200

int main (int argc, char * argv[]) {

    int n, m, p, q, i, j, k;

    int c, d, ds[MAX];

    int ip[8], op[5];

    // map connections, 0 none, 1 gate, 2 gate, 3 gate, 4 gate
    // any input could have only one connection
    // any output could have many connections

    for (ip[0] = 0; ip[0] < 5; ip[0]++) { 
    for (ip[1] = 0; ip[1] < 5; ip[1]++) { 
    for (ip[2] = 0; ip[2] < 5; ip[2]++) { 
    for (ip[3] = 0; ip[3] < 5; ip[3]++) { 
    for (ip[4] = 0; ip[4] < 5; ip[4]++) { 
    for (ip[5] = 0; ip[5] < 5; ip[5]++) { 
    for (ip[6] = 0; ip[6] < 5; ip[6]++) { 
    for (ip[7] = 0; ip[7] < 5; ip[7]++) { 

    /*
    for (k = 0; k < 8; k++) {    
        printf ("%1d|", ip[k]);
        }
    printf ("\n");
    */

    // if (0) {

    // pull up init

    op[0] = 0;

    for (c = 0; c < 16; c++) {
        op[1] = c & 0x1;
        op[2] = c & 0x2;
        op[3] = c & 0x4;
        op[4] = c & 0x8;
    

    // run 

    n = 0;

    for (m = 0, n = 0; n < MAX; n++, m++ ) {

    // gate 0 always 0, logics NANDS, p is bitwise result

        p = 0;

        for (k = 0; k < 4; k++ ) {
            
            i = ip[ k * 2 ];
            
            j = ip[ i + 1 ];

            op[ k + 1 ] = ( ! ( op[i] & op[j] ) ) & 0x01;

            p = p << 1 | op[ k + 1 ];

            }
         
         ds[m] = p;

    // detect cycles

         for (i = 0; i < m; i++) {

            for (j = i + 1; j < m; j++) {

                d = j - i;

                for (k = 0; k < d; k++)  if (ds[i+k] != ds[j+k]) break;

                if ( k == d) n = MAX;

                }
            }

         }

    if (m > 10) {

        printf ("\n%04d|%02d|",m,c);

        for (k = 0; k < 8; k++) {    
            printf ("%1d:", ip[k]);
            }
        
        
        for (k = 0; k < m; k++) {    
            printf ("%02d>",ds[k]);
            }


        }
    // }

    }

    } } } } } } } } 

    return (0);
    }
