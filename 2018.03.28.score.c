#include <stdio.h>
int main()
{
    int N,i;
    float sum=0, average=0, max=0, min=0;
    scanf("%d",&N);
    int a[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    max = a[0];
    min=a[0];
    for(i=0;i<N;i++)
    {
        sum = sum + a[i];
        if(a[i]>max){
            max=a[i];
        }
        if(a[i]<min){
            min=a[i];
        }
    }
    average=sum/N;
    printf("average = %.2f\nmax = %.2f\nmin = %.2f\n",average,max,min);
    return 0;
}
