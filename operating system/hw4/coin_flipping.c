#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h> 
#include <time.h>


char coins[20] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
                  'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'};
int persons = 100;
int fliptimes = 10000;
pthread_mutex_t lock[20];

//generate a random 0 or 1, for flipping coins
void flipcoin(char* c){
    if((rand()%2)==0){
        *c = '0';
    }else{
        *c = 'X';
    }
}
//global lock, one person every lock
void* global(){
    pthread_mutex_lock(&(lock[0]));
    for(int j=0; j<fliptimes; j++){
        for(int i=0; i<20; i++){
            flipcoin(&(coins[i]));
        }
    }
    pthread_mutex_unlock(&(lock[0]));
}
//iteration lock, one 20-coin iteration every lock
void* iteration(){
    for(int j=0; j<fliptimes; j++){
        pthread_mutex_lock(&(lock[0]));
        for(int i=0; i<20; i++){
            flipcoin(&(coins[i]));
        }
        pthread_mutex_unlock(&(lock[0]));
    }
}
//coin lock, one lock for every coin
void* coin(){
    for(int j=0; j<fliptimes; j++){
        for(int i=0; i<20; i++){
            pthread_mutex_lock(&(lock[i]));
            flipcoin(&(coins[i]));
            pthread_mutex_unlock(&(lock[i]));
        }
    }
}
//a function creates n threads for a particular function and 
//join them together
void run_threads(int n, void* (*proc)(void*)){
    pthread_t tid[n];
    int erorr;
    for(int i=0; i< n; i++){
        erorr = pthread_create(&(tid[i]), NULL, proc, NULL);
        if (erorr != 0) 
            printf("\nThread can't be created :[%s]", strerror(erorr));
    }
    for(int i=0; i<n; i++){
        pthread_join(tid[i], NULL);
    }
}
//print current coins
void printcoin(){
    printf("coins: ");
    for(int i=0; i<20; i++){
        printf("%c", coins[i]);
    }
}
//time measurements for n threads running for proc function
static double timeit(int n, void* (*proc)(void *)){
    clock_t t1, t2;
    t1 = clock();
    run_threads(n, proc);
    t2 = clock();
    return ((double) t2 - (double) t1) / CLOCKS_PER_SEC * 1000;
}
//this prints result for every strategy we use
void printresult(char* name, void* (*strategy)(void *)){
    double timedif;

    printcoin();
    printf(" (start - %s lock)\n", name);
    timedif = timeit(persons, strategy);
    printcoin();
    printf(" (end - %s lock)\n", name);
    printf("%d threads x %d flips:   %f ms\n\n", persons, fliptimes, timedif);
}

int main(int argc, char* argv[]){
    time_t t;
    srand((unsigned) time(&t));

    int opt;
    while((opt = getopt(argc, argv, ":p:n:"))!=-1){
        switch(opt){
            case 'p':
                persons = atoi(optarg); //to change the amount of threads
                break;
            case 'n':
                fliptimes = atoi(optarg);// to change the flip times every person does
                break;
        }
    }

    //initialize mutex locks
    for(int i=0; i<20; i++){
        if (pthread_mutex_init(&(lock[i]), NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
        }
    }

    printresult("global", global);
    printresult("iteration", iteration);
    printresult("coin", coin);

    //destroy locks
    for(int i=0; i<20; i++){
        pthread_mutex_destroy(&(lock[i]));
    }
    pthread_exit(NULL);
    return 0;
}




