#include <stdio.h>
int columns()
{
    double a=0.0, M[12][12];
    char T[2];
    int C,x,y;
    scanf("%d", &C);
    scanf("%s", &T);
    for(x=0;x<=11;x++)
    {
        for(y=0; y<=11; y++)
        {
        scanf("%lf", &M[x][y]);
        if(y==C)
            a+=M[x][y];
        }
    }
    if(T[0]=='S')
        printf("\n%.1lf\n",a);
    else if(T[0]=='M')
    {
            a=a/12.0; // num de entradas na matriz
        printf("%.1lf\n",a);
    }
    return 0;
}
