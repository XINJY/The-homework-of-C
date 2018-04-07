#include <stdio.h>
struct student{
    char num[5];
    char name[11];
    int score;
};
int main()
{
    int N,i=0,sum=0;
    float average;
    scanf("%d",&N);
    struct student s[N];
    for(i=0;i<N;i++)
    {
        scanf("%s %s %d",s[i].num,s[i].name,&s[i].score);
        sum=sum+s[i].score;
    }
    average = sum/N*1.0;
    printf("%.2f\n",average);
    for(i=0;i<N;i++)
    {
        if(s[i].score<average){
            printf("%s %s\n",s[i].name,s[i].num);
        }
    }
    return 0;
}
