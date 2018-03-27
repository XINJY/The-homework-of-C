#include <stdio.h>
void delnum(char *s);
int main ()
{ char item[80];
gets(item);
 delnum(item);
 printf("%s\n",item);
 return 0;
}
void delnum(char *s)
{
    int i = 0,j = 0;
    while(s[i] != '\0') {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}
