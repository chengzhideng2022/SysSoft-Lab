#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FREQUENCY                       5
#define MINIMUM_TEMPERATURE -10
#define MAXIMUM_TEMPERATURE 35

int main() {
    srand(time(NULL));  

    while (1) {
        float num = (float)(rand()% (MAXIMUM_TEMPERATURE*100 - MAXIMUM_TEMPERATURE*100+100) + MINIMUM_TEMPERATURE*100 ) / 100; 
        printf("Temperature = %1.2f @", num);
        fflush ( stdout );
        
        system("date");
       
        sleep(5); 
    }
    return 0;
}