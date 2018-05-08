#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char name[20];//用来存需要操作的文件的文件名
    char function[2];//用来匹配对相关文件需要进行的操作
    int charNum=0,wordNum=0,lineNum=0;//分别用来统计字符数、词数和行数

    //读入文件名
    printf("请输入需要进行操作文件的文件名：");
    scanf("%s",&name);

    //定义文件指针
    FILE *fp;

    //打开文件
    if((fp = fopen( name, "r" )) == NULL){
            printf(" File open error!\n" );
            exit(0);
   	}

   	//读入想要对文件进行的相关操作
   	printf("请输入需要对文件进行的相关操作\n -c统计文件中的字符数\n -w统计文件中的词数\n -l统计文件的行数\n");
   	scanf("%s",&function);

   	//匹配读入的功能并操作文件

   	//统计文件字符数
   	if((function[0]=='-')&&(function[1]=='c')){
        char ch;
        ch = fgetc(fp);//fgetc(文件名)函数从指定文件中读取一个字符EOF用来检测是否到文件的末尾
        while(ch!=EOF){
            charNum++;
            ch = fgetc(fp);
        }
        printf("文件中的字符数为：%d",charNum);
   	}

   	//统计文件词数
   	else if((function[0]=='-')&&(function[1]=='w')){
        char ch;
        while(feof(fp)==0){
                fscanf(fp,"%s",&ch);
                wordNum++;
        }
        wordNum--;
        printf("文件中的词数为：%d",wordNum);

   	}

   	//统计文件行数
   	else if((function[0]=='-')&&(function[1]=='l')){
            char ch;
            ch = fgetc(fp);
            while(ch!=EOF){
                if(ch=='\n'){
                    wordNum++;
                }
                ch = fgetc(fp);
            }
            wordNum++;
            printf("文件中的行数为：%d",wordNum);
   	}
   	else{
        printf("输入错误！没有对应功能\n 请关闭窗口重新运行程序。");
    }

   	//关闭文件
    if(fclose(fp)){
            printf("Can not close the file!\n");
            exit(0);
    }

    return 0;
}
