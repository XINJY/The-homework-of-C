#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char name[20];//��������Ҫ�������ļ����ļ���
    char function[2];//����ƥ�������ļ���Ҫ���еĲ���
    int charNum=0,wordNum=0,lineNum=0;//�ֱ�����ͳ���ַ���������������

    //�����ļ���
    printf("��������Ҫ���в����ļ����ļ�����");
    scanf("%s",&name);

    //�����ļ�ָ��
    FILE *fp;

    //���ļ�
    if(( fp = fopen( name, "r" )) == NULL){
            printf(" File open error!\n" );
            exit(0);
   	}

   	//������Ҫ���ļ����е���ز���
   	printf("��������Ҫ���ļ����е���ز���\n -cͳ���ļ��е��ַ���\n -wͳ���ļ��еĴ���\n -lͳ���ļ�������\n");
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
        charNum--;
        printf("�ļ��е��ַ���Ϊ��%d",charNum);
   	}

   	//ͳ���ļ�����
   	if((function[0]=='-')&&(function[1]=='w')){
        char ch;
        while(feof(fp)==0){
                fscanf(fp,"%s",&ch);
                wordNum++;
        }
        wordNum--;
        printf("�ļ��еĴ���Ϊ��%d",wordNum);

   	}

   	//ͳ���ļ�����
   	if((function[0]=='-')&&(function[1]=='l')){
            char ch;
            ch = fgetc(fp);
            while(ch!=EOF){
                if(ch=='\n'){
                    wordNum++;
                }
                ch = fgetc(fp);
            }
            printf("�ļ��е�����Ϊ��%d",wordNum);
   	}

   	//�ر��ļ�
   	if(fclose(fp)){
            printf("Can not close the file!\n");
            exit(0);
    }

    return 0;
}

//wc.exe -c file.c     //�����ļ� file.c ���ַ��� fgetc()������ָ���ļ�����һ���ַ�
//wc.exe -w file.c    //�����ļ� file.c �Ĵʵ���Ŀ
//wc.exe -l file.c      //�����ļ� file.c ������
