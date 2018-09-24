#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menor(int argc, char *argv[]) {
 
    int n; // array len
    int min, pos; // min value and position
    int a; // counter
    int x[n]; // array
	
    scanf("%d", &n); // receive len

    for(a=0; a<n; a++)
    	scanf("%d", &x[a]); //receive vetor of given len. if you pass more than n numbers, the program misses
    min=x[0]; //initialize min var with the first vetor position
    for(a=1; a<n; a++)
    {
        if(min>x[a]) //if the min value is biggest than the number 
        {
            min=x[a]; //the number is the min
            pos=a; //a is the position of the number
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", min, pos);
    
    return 0;
    

}
