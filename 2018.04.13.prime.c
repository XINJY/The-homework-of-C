#include <stdio.h>
#include <math.h>
int main ()
{
    long int n=0,i=0,j=0,x=0;
    n = 201*990;
    int axb[n];

    for(i=1;i<n;i++)
    {
        axb[i-1] = i;
    }
    for(i=1;i<=n;i++)
    {
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0){
                axb[i-1]=1;
            }
        }
    }
    for(i=0,x=0;i<n;i++)
    {
        if(axb[i]!=1){
            printf("%d ",axb[i]);
            x++;
            if(x%5 == 0){
            printf("\n");
            }
        }
    }
    return 0;
}
