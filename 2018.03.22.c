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
    char *a = s;//�¶���һ��ָ��
    int i = 0, j = 0, k = 0;
    while (*a != '\0')//ָ����������һλ
    {
        a++;
        i++;
    }
    a--;                     //��Ϊ���һΪΪ'\0'���Լ�һλ
    while (*s != '\0')       //������ָ����бȽ�
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
    if (k == i)           //���ÿ�������k=i����true
    {
        return true;
    }
}