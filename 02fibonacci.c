#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fib(int argc, char *argv[]) {
 
    int t; // input qtd
    int n; // value to be calc
    int i; // counter
    unsigned long long int fib [61]; //unsigned: without sign, long long to 64 bits int

    fib [0] = 0; // fib(0)
    fib [1] = 1; // fib(1)
    
    for(i = 2; i <= 60; i++){ // counter from 2 to 60
        fib [i] = fib [i-1] + fib [i-2]; // fib 
    }
    scanf("%d", &t); // receive input qtd
    
    for(i = 1; i<= t; i++){ // receive calc "t" times
        scanf("%d", &n); //receive value to be calc
        printf("Fib(%d) = %llu\n",n, fib[n]); // show equivalent fib number index
    }

 
    return 0;
}
