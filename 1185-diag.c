#include <stdio.h>
int main(void)
{
    double a=0.0, M[12][12]; //matriz 12x12
    char T[2]; //variavel para caractere S ou M
    int C,x,y,z,p=10; 
    scanf("%s", &T);
    for(x=0;x<=11;x++)
    {
        for(y=0; y<=11; y++) // interar a matriz
        //scanf("%lf", &M[x][y]);
        M[x][y] = 0.5; // placeholder para nao digitar 144 caracteres  
    }
    for(z=0; z<=10;z++) 
    {
        for(C=0; C<=p;C++) //itera os elementos e soma os valores 
            a+=M[z][C];
        p--;
    }
    if(T[0]=='S')
        printf("%.1lf\n",a); //se for soma, so printa
    else if(T[0]=='M')
    {
        a=a/66.0;
        printf("%.1lf\n",a); //se for media
	}
    return 0;
}
