#include<stdio.h>
void input(int *arr,int n);
void max_min(int *arr,int n);
void output(int *arr,int n);
int main()
{ int a[10];
input(a,10);
max_min(a,10);
 output(a,10);
 return 0;
}
void input(int *arr,int n)
{
    int i = 0;
    for(i = 0;i < n;i++)
    {
        scanf("%d",arr+i);
    }
}
void max_min(int *arr,int n)
{
    int i = 0, max = *arr, min = *arr, t = 0, indexmax = 0,indexmin = 0;//indexmax��indexmin�ֱ������ֵ����Сֵ���±�
    //������������ֵ
    for(i = 0;i < n;i++)
    {
        if(*(arr+i)>max){
            max = *(arr+i);
            indexmax = i;
        }
        if(*(arr+i)<min){
            min = *(arr+i);
            indexmin = i;
        }
    }
    //��ֵ����β���н���
    t = *(arr+n-1);
    *(arr+n-1)=max;
    *(arr+indexmax) = t;
    t = *arr;
    *arr=min;
    *(arr+indexmin) = t;
}
void output(int *arr,int n)
{
    int i;
    for(i = 0;i < n;i++)
    {
        printf("%3d",*(arr+i));
    }
}
