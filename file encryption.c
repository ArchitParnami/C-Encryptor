#include<stdio.h>
#include<conio.h>
#include "encrypt.h"
#include "decrypt.h"
#include<string.h>
#include<malloc.h>
FILE *fp;
void main()
{
    char file[20];
    char ch,*c,*e;
    int x,i=0,y;
    for(y=0;y<6;y++)
    printf("\n");
    printf("\t\t\t==========================\n");
    printf("\t\t\t|                        |\n");
    printf("\t\t\t| ********************** |\n");
    printf("\t\t\t| WELCOME TO C-EncrYptor |\n");
    printf("\t\t\t| ********************** |\n");
    printf("\t\t\t|                        |\n");
    printf("\t\t\t| 1.Encrypt a file       |\n");
   // printf("\t\t\t|------------------------|\n");
    printf("\t\t\t|                        |\n");
    printf("\t\t\t| 2.Decrypt a file       |\n");
    //
    printf("\t\t\t|------------------------|\n");
    printf("\t\t\t|                        |\n");
    printf("\t\t\t| 3.Exit                 |\n");
    printf("\t\t\t|                        |\n");
    printf("\t\t\t==========================\n");
    printf("\n\t\t\tenter choice: ");
    scanf("%d",&x);
    if(x==1)
    {
        printf("\t\t\t---------------------------\n");
        printf("\t\t\tenter file name: ");
        fflush(stdin);
        gets(file);
        //printf("\t\t\t--------------------------\n");
        fp=fopen(file,"rt");

        ch=fgetc(fp);
        while(ch!=EOF)
        {
            i++;
            ch=fgetc(fp);
        }
        printf("\t\t\t----------------------------\n");
        printf("\t\t\tno of characters read = %d\n",i);
        //printf("\t\t\t-------------------------------\n");
        rewind(fp);
        if(i!=0)
        {
            c=(char*)malloc(sizeof(char)*i);
            e=(char*)malloc(sizeof(char)*i*2);
            i=0;

            ch=fgetc(fp);
            while(ch!=EOF)
            {
                c[i]=ch;
                i++;
                ch=fgetc(fp);
            }

          c[i]='\0';
          fclose(fp);
          strcpy(e,"");
          strcpy(e,encrypt(c,e));
          //printf("file: %s\n",e);
          fp=fopen(file,"wt");

          for(i=0;e[i]!='\0';i++)
          fputc(e[i],fp);
          fclose(fp);
        }
         free(c);
         free(e);
        printf("\t\t\t----------------------------\n");
        printf("\t\t\tEncryption successfull!\n");
        printf("\t\t\t----------------------------\n");
    }

     else if(x==2)
     {
        printf("\t\t\t----------------------------\n");
        printf("\t\t\tenter file name: ");
        fflush(stdin);
        gets(file);
     //   printf("\t\t\t--------------------------\n");
        fp=fopen(file,"rt");

        ch=fgetc(fp);
        while(ch!=EOF)
        {
            i++;
            ch=fgetc(fp);
        }
        printf("\t\t\t----------------------------\n");
        printf("\t\t\tno of characters read = %d\n",i);
        //printf("\t\t\t--------------------------\n");
        rewind(fp);
        if(i!=0)
        {
            c=(char*)malloc(sizeof(char)*i);
            e=(char*)malloc(sizeof(char)*i);
            i=0;

            ch=fgetc(fp);
            while(ch!=EOF)
            {
                c[i]=ch;
                i++;
                ch=fgetc(fp);
            }

          c[i]='\0';
          fclose(fp);
          strcpy(e,"");
          strcpy(e,decrypt(c,e));

          fp=fopen(file,"wt");

          for(i=0;e[i]!='\0';i++)
          fputc(e[i],fp);
          fclose(fp);

          free(c);
          free(e);
          printf("\t\t\t----------------------------\n");
          printf("\t\t\tfile decrypted!\n");
          printf("\t\t\t----------------------------\n");



     }

}

     else
     {
         printf("\t\t\t--------------------------\n");
         printf("\t\t\t\tbye! bye!\n");
         printf("\t\t\t--------------------------\n");
     }

 getch();
}
