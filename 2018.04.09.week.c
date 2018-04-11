#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex( char *s );

int main()
{
    int n;
    char s[MAXS];

    scanf("%s", s);
    n = getindex(s);
    if ( n==-1 ) printf("wrong input!\n");
    else printf("%d\n", n);

    return 0;
}
int getindex( char *s )
{
    int i=0;
    char *week[8] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    for(i=0;i<7;i++)
    {
        if(strcmp(s,week[i])==0)
        {
            break;
        }
    }
    if(i<7){
        return i;
    }else{
        return -1;
    }
}
