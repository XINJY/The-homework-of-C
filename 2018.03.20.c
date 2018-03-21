#include<stdio.h>
void sort(int *x,int n);
int main ( )
{int *p,i,a[10];
 p=a;
 for (i=0;i<10;i++)  scanf("%d",p++);
 p=a;
 sort(a,10);
 for(i=0;i<10;i++)  printf("%4d",*p++);
 printf("\n");
 return 0;
 }
 void sort(int *x,int n)
 {
     int i = 0, j = 0, tmp = 0, max = 0;
     for(i = 0;i < n-1;i++)
     {
         max = i;
         for(j = i;j < n;j++)
         {
             if(*(x+max)<*(x+j)){
                max = j;
             }
         }
         if(max != i){
                        tmp = *(x+max);
                        *(x+max) = *(x+i);
                        *(x+i) = tmp;
         }
     }
 }



