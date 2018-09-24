#include<stdio.h>

int matrix()
{
    int i,j; //matrix counters
	int n,x; //matrix len and matrix number
    while(n!=0){ //zero is the break number
        scanf("%d",&n); //receive matrix len (nxn)
        for(i=1;i<=n;i++){ 
            for(j=1;j<=n;j++){            
                x = i; // if the matrix is 1x1, prints only 1 and x = i
                if(j < x) x = j; // if the matrix is bigger than 1, x = j
                if(n-i+1 < x) x = n-i+1; // line 
                if(n-j+1 < x) x = n-j+1; // columns
                printf("%3d",x); // 4 justified to the left
                if(j < n) printf(" "); //a space after if has some number more
                else printf("\n"); // if is the last number breaks the line
            }
        }
        printf("\n");
    }
    return 0;
}
