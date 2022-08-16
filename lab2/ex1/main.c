#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FREQUENCY                       5
#define MINIMUM_TEMPERATURE ( -10 * 100 )
#define MAXIMUM_TEMPERATURE (  35 * 100 )

void read_sensor ( void ) {
    float random_temperature = ( ( MINIMUM_TEMPERATURE + rand ( ) % ( MAXIMUM_TEMPERATURE - MINIMUM_TEMPERATURE ) ) / 100.0 );
    printf ( "Temperature = %05.2f @\t",random_temperature );
    fflush ( stdout );
    system ( "date" );
}

int main ( int argc, char * argv [ ] ) {
    srand ( time ( NULL ) );

    while ( 1 ) {
        read_sensor ( );
        sleep ( FREQUENCY );
    }

    return ( 0 );
}
