#include<stdio.h>
#define N 10
int fun(int *a,int *b,int n);
int main()
{ int a[N],i,max,p=0;
for(i=0;i<N;i++) scanf("%d",&a[i]);
 max=fun(a,&p,N);
 printf("max=%d,position=%d\n",max,p);
 return 0;
}
int fun(int *a,int *b,int n)//*a=a *b=&pÏÂ±ê n=N;
{
    int i = 0,max = *(a+1);
    for(i = 1;i < n;i++)
    {
        if(*(a+i)>max){
            max = *(a+i);
            *b = i;
        }
    }
    return max;
}
