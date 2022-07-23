#include <stdio.h>
#include <stdlib.h>

int main ( void ) {

    printf ("%ld %u\n", sizeof (int), (unsigned int) ~(0x0) );
    printf ("%ld %lu\n", sizeof (long int), (long unsigned int) ~(0x0) );

    return (0);
    }
