#include <stdio.h>
#include <string.h>

#define MAXN 20
typedef enum {false, true} bool;

bool palindrome( char *s );

int main()
{
    char s[MAXN];

    scanf("%s", s);
    if ( palindrome(s)==true )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);

    return 0;
}

bool palindrome(char *s)
{
    char *a = s;//新定义一个指针
    int i = 0, j = 0, k = 0;
    while (*a != '\0')//指针遍历到最后一位
    {
        a++;
        i++;
    }
    a--;                     //因为最后一为为'\0'所以减一位
    while (*s != '\0')       //将两个指针进行比较
    {
        if (*s == *a)
        {

            k++;
        }
        else
        {
            return false;
        }
        s++;
        a--;
    }
    if (k == i)           //如果每个都相等k=i返回true
    {
        return true;
    }
}
