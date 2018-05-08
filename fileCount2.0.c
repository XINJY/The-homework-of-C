#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //����������в�����Ĭ�ϵ�һ������ΪҪ�������ļ���argv[1]���ڶ���������ƥ��Ĳ���argv[2]
    if(argc==1){
        char name[20];//��������Ҫ�������ļ����ļ���
        char function[2];//����ƥ�������ļ���Ҫ���еĲ���
        int charNum=0,wordNum=0,lineNum=0;//�ֱ�����ͳ���ַ���������������

        //�����ļ���
        printf("Please enter the file name that needs to be done:");
        scanf("%s",&name);

        //�����ļ�ָ��
        FILE *fp;

        //���ļ�
        if((fp = fopen( name, "r" )) == NULL){
                printf(" File open error!\n" );
                exit(0);
        }

        //������Ҫ���ļ����е���ز���
        printf("Please enter the relevant operation that needs to be done to the file:\n -c The number of characters in a statistical file.\n -w The number of words in a statistical document.\n -l The number of rows in a statistical file.\n");
        scanf("%s",&function);

        //ƥ�����Ĺ��ܲ������ļ�

        //ͳ���ļ��ַ���
        if((function[0]=='-')&&(function[1]=='c')){
            char ch;
            ch = fgetc(fp);//fgetc(�ļ���)������ָ���ļ��ж�ȡһ���ַ�EOF��������Ƿ��ļ���ĩβ
            while(ch!=EOF){
                charNum++;
                ch = fgetc(fp);
            }
            printf("The number of characters in the file is:%d",charNum);
        }

        //ͳ���ļ�����
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

        //ͳ���ļ�����
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

        //�ر��ļ�
        if(fclose(fp)){
                printf("Can not close the file!\n");
                exit(0);
        }

        }
        else if(argc==2){
            char function[2];//����ƥ�������ļ���Ҫ���еĲ���
            int charNum=0,wordNum=0,lineNum=0;//�ֱ�����ͳ���ַ���������������

            //�����ļ�ָ��
            FILE *fp;
            //���ļ�
            if((fp = fopen( argv[1], "r" )) == NULL){
                    printf(" File open error!\n" );
                    exit(0);
            }
            //������Ҫ���ļ����е���ز���
            printf("Please enter the relevant operation that needs to be done to the file:\n -c The number of characters in a statistical file.\n -w The number of words in a statistical document.\n -l The number of rows in a statistical file.\n");
            scanf("%s",&function);

            //ƥ�����Ĺ��ܲ������ļ�
            //ͳ���ļ��ַ���
            if((function[0]=='-')&&(function[1]=='c')){
                char ch;
                ch = fgetc(fp);//fgetc(�ļ���)������ָ���ļ��ж�ȡһ���ַ�EOF��������Ƿ��ļ���ĩβ
                while(ch!=EOF){
                    charNum++;
                    ch = fgetc(fp);
                }
                printf("The number of characters in the file is:%d",charNum);
            }

            //ͳ���ļ�����
            else if((function[0]=='-')&&(function[1]=='w')){
                char ch;
                while(feof(fp)==0){
                        fscanf(fp,"%s",&ch);
                        wordNum++;
                }
                wordNum--;
                printf("The number of words in the document is:%d",wordNum);
            }

            //ͳ���ļ�����
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
            //�ر��ļ�
            if(fclose(fp)){
                printf("Can not close the file!\n");
                exit(0);
            }
        }
        else if(argc==3){
            int charNum=0,wordNum=0,lineNum=0;//�ֱ�����ͳ���ַ���������������

            //�����ļ�ָ��
            FILE *fp;
            //���ļ�
            if((fp = fopen( argv[1], "r" )) == NULL){
                    printf(" File open error!\n" );
                    exit(0);
            }
            //ͳ���ļ��ַ���
            if(!strcmp(argv[2],"-c")){
                char ch;
                ch = fgetc(fp);//fgetc(�ļ���)������ָ���ļ��ж�ȡһ���ַ�EOF��������Ƿ��ļ���ĩβ
                while(ch!=EOF){
                    charNum++;
                    ch = fgetc(fp);
                }
                printf("The number of characters in the file is:%d",charNum);
            }

            //ͳ���ļ�����
            else if(!strcmp(argv[2],"-w")){
                char ch;
                while(feof(fp)==0){
                        fscanf(fp,"%s",&ch);
                        wordNum++;
                }
                wordNum--;
                printf("The number of words in the document is:%d",wordNum);
            }

            //ͳ���ļ�����
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
            //�ر��ļ�
            if(fclose(fp)){
                printf("Can not close the file!\n");
                exit(0);
            }
        }
    return 0;
}
