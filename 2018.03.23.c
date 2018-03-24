#include <stdio.h>
#define MAXN 20

void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXN];
    char t[MAXN]="happy new year";
    int m;

    scanf("%d\n", &m);
    //ReadString(t);
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}

void strmcpy( char *t, int m, char *s )
{
    int i,j;
    for(i=m-1,j=0;*(t+i)!='\0';i++,j++)
    {
        *(s+j)=*(t+i);
    }
    *(s+j) = '\0';
}
