//SSH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

double func(double x ){
    double y;
    y = x / ((x*x+2)*(x*x+2)*(x*x+2));
    return y;
}

long millisecond(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (1000*tv.tv_sec + tv.tv_usec/1000);
}

main (int argc, char *argv[]){
    long N, start, stop;
    int i;
    double sum, dx, a, b, GFLOPS
    struct timeval startTime, endTime;

    if (argc != 2){
        printf("argument error!\n");
        exit(1);
    }

    N = atoi(argv[1]);

    start = millisecond();

    sum = 0.0;
    a=0.0, b= 2.0;
    dx = (b-a)/N;

    for(i=0;i<N;i++){
        sum += (func(a)+func(a+dx))/2*dx;
        a += dx;
    }

    stop=millisecond();

    //'12' = amount of statements
    GFLOPS = (1+(N*12))/((double)(stop-start)*1000000000)

    printf("%lf\n", sum);
    printf("elapsed time : %ld milliseconds\n", stop-start);
    printf("GFLOPS : %lf\n", GFLOPS);

}
