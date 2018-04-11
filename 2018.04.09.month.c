#include <stdio.h>

char *getmonth( int n );

int main()
{
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);

    return 0;
}
char *getmonth( int n )
{
    char *month[13] = {"January","February","March","April","May","June","July","August","September","October","November","December","wrong input!"};
    char *s;
    if(n>=1 && n<=12)
    {
        s = month[n-1];
    }else
    {
        s = month[12];
    }
    return s;
}
