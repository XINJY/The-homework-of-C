#include <stdio.h>
struct money
{
    char name[10];
    float jmoney;
    float fmoney;
    float zmoney;
    float mony;
};
int main()
{
    int N,i=0;
    scanf("%d",&N);
    struct money s[i];
    for(i=0;i<N;i++)
    {
        scanf("%s %f %f %f",s[i].name,&s[i].jmoney,&s[i].fmoney,&s[i].zmoney);
        s[i].mony=s[i].jmoney+s[i].fmoney-s[i].zmoney;
    }
    for(i=0;i<N;i++)
    {
        printf("%s %.2f\n",s[i].name,s[i].mony);
    }
    return 0;
}
