#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [number of digits]\n", argv[0]);
        return 1;
    }
    
    int digits = atoi(argv[1]);
    if (digits <= 0) {
        printf("Number of digits should be a positive integer.\n");
        return 1;
    }

#pragma omp parallel num_threads(4)
   {
    int threadIndex = omp_get_thread_num();

    unsigned long int n = (unsigned long int) pow(10, digits*2);  // number of samples
    unsigned long int count = 0;  // number of points inside the circle
    
    struct drand48_data seed;
    srand48_r(threadIndex+time(NULL), &seed);

    for (unsigned long int i = 0; i < n; i++) {
      double x, y;
      drand48_r(&seed, &x);
      drand48_r(&seed, &y);
      if (x * x + y * y <= 1) {
          count++;
      }
    }
    
    double pi = 4.0 * count / n;
    printf("Estimate of pi with %d digits: %.15f\n", digits, pi);

   }
    
    return 0;
}

