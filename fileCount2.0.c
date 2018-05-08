#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //如果用命令行操作，默认第一个参数为要操作的文件名argv[1]，第二个参数是匹配的操作argv[2]
    if(argc==1){
        char name[20];//用来存需要操作的文件的文件名
        char function[2];//用来匹配对相关文件需要进行的操作
        int charNum=0,wordNum=0,lineNum=0;//分别用来统计字符数、词数和行数

        //读入文件名
        printf("Please enter the file name that needs to be done:");
        scanf("%s",&name);

        //定义文件指针
        FILE *fp;

        //打开文件
        if((fp = fopen( name, "r" )) == NULL){
                printf(" File open error!\n" );
                exit(0);
        }

        //读入想要对文件进行的相关操作
        printf("Please enter the relevant operation that needs to be done to the file:\n -c The number of characters in a statistical file.\n -w The number of words in a statistical document.\n -l The number of rows in a statistical file.\n");
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
            printf("The number of characters in the file is:%d",charNum);
        }

        //统计文件词数
        else if((function[0]=='-')&&(function[1]=='w')){
            char ch;
            while(feof(fp)==0){
                    ch=fgetc(fp);
                    fscanf(fp,"%s",&ch);
                        wordNum++;
            }
            wordNum--;
            printf("The number of words in the document is:%d",wordNum);

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
                printf("The number of rows in the file is:%d",wordNum);
        }
        else{
            printf("Input error!There is no corresponding function\n Please close the window and rerun the program.");
        }

        //关闭文件
        if(fclose(fp)){
                printf("Can not close the file!\n");
                exit(0);
        }

        }
        else if(argc==2){
            char function[2];//用来匹配对相关文件需要进行的操作
            int charNum=0,wordNum=0,lineNum=0;//分别用来统计字符数、词数和行数

            //定义文件指针
            FILE *fp;
            //打开文件
            if((fp = fopen( argv[1], "r" )) == NULL){
                    printf(" File open error!\n" );
                    exit(0);
            }
            //读入想要对文件进行的相关操作
            printf("Please enter the relevant operation that needs to be done to the file:\n -c The number of characters in a statistical file.\n -w The number of words in a statistical document.\n -l The number of rows in a statistical file.\n");
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
                printf("The number of characters in the file is:%d",charNum);
            }

            //统计文件词数
            else if((function[0]=='-')&&(function[1]=='w')){
                char ch;
                while(feof(fp)==0){
                        fscanf(fp,"%s",&ch);
                        wordNum++;
                }
                wordNum--;
                printf("The number of words in the document is:%d",wordNum);
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
                    printf("The number of rows in the file is:%d",wordNum);
            }
            else{
                printf("Input error!There is no corresponding function\n Please close the window and rerun the program.");
            }
            //关闭文件
            if(fclose(fp)){
                printf("Can not close the file!\n");
                exit(0);
            }
        }
        else if(argc==3){
            int charNum=0,wordNum=0,lineNum=0;//分别用来统计字符数、词数和行数

            //定义文件指针
            FILE *fp;
            //打开文件
            if((fp = fopen( argv[1], "r" )) == NULL){
                    printf(" File open error!\n" );
                    exit(0);
            }
            //统计文件字符数
            if(!strcmp(argv[2],"-c")){
                char ch;
                ch = fgetc(fp);//fgetc(文件名)函数从指定文件中读取一个字符EOF用来检测是否到文件的末尾
                while(ch!=EOF){
                    charNum++;
                    ch = fgetc(fp);
                }
                printf("The number of characters in the file is:%d",charNum);
            }

            //统计文件词数
            else if(!strcmp(argv[2],"-w")){
                char ch;
                while(feof(fp)==0){
                        fscanf(fp,"%s",&ch);
                        wordNum++;
                }
                wordNum--;
                printf("The number of words in the document is:%d",wordNum);
            }

            //统计文件行数
            else if(!strcmp(argv[2],"-l")){
                    char ch;
                    ch = fgetc(fp);
                    while(ch!=EOF){
                        if(ch=='\n'){
                            wordNum++;
                        }
                        ch = fgetc(fp);
                    }
                    wordNum++;
                    printf("The number of rows in the file is:%d",wordNum);
            }
            //关闭文件
            if(fclose(fp)){
                printf("Can not close the file!\n");
                exit(0);
            }
        }
    return 0;
}
