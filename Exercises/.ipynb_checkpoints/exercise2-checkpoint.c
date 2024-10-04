#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int Array[100]; // Use rand() % 10000 for init
    int max = 0;
    int min = 100000; 
    int avg;
    int sum = 0;

    srand(time(NULL));

    #pragma omp parallel for reduction(max:max) reduction(min:min) reduction(+:sum)
    
    for (int i = 0; i < 100; i++) {
        Array[i] = rand() % 10000;

         int thread_num = omp_get_thread_num();
        printf("Thread %d generated value %d for element %d\n", thread_num, Array[i], i);
        
        if (Array[i] > max) {
            max = Array[i];            
        }

        if (Array[i] < min) {
            min = Array[i];
        }

        sum += Array[i];
    }           

    avg = sum / 100;

    printf("\nMax: %d\n", max);
    printf("Min: %d\n", min);
    printf("Average: %d\n", avg);
    
    return 0;
}