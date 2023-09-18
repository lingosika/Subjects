#include <stdio.h>
#include <stdlib.h>
#include <stirng.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct{
    char s; //semaphore
    int sum;
}SHM;

main(int argc, char *argv[]){

    int shm_id;
    void *shm_add;
    SHM *shm;
    int key;

    int data;
}
