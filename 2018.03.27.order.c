#include <stdio.h>
int fun(char *s,int num);
int main()
{
 char s[10];
 gets(s);
 fun(s,7);
 printf("%s",s);
 return 0;
 }
 int fun(char *s,int num)
{
    int i=0, j=0, k=0, n=0;
    char t;
    for(n=0;;n++)
    {
        if(*(s+n)=='\0')break;
    }
    n--;
        for(i=1;i<n-1;i++)
        {
            for(j=i;j<n;j++)
            {
                if(*(s+i)<*(s+j))
                {
                    t=*(s+i);
                    *(s+i)=*(s+j);
                    *(s+j)=t;
                }
            }
        }
}
