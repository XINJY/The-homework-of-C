#include<stdio.h>
int fun(char *str,char *substr);
int main()
{ char str[81]="asdasasdfgasdaszx67asdmklo",substr[4]="asd";
 int n;
 n=fun(str,substr);
 printf("n=%d\n",n);
 return 0;
}
int fun(char *str,char *substr)
{
    int i=0,j=0,k=0,n=0;
    for(i=0;str[i]!='\0';i++)//��ĸ����ʼ����
    {
        for(j=i,k=0;str[j]==substr[k];j++,k++)//ÿ�α����ĵ�ǰ�ַ�����Ҫ���Ӵ��ĵ�һ���ַ����бȽϰ��Ӵ������������һ
        {
            if(substr[k+1]=='\0')
            {
                n++;
            }
        }
    }
    return n;
}
