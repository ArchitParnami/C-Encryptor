#include<string.h>

char* digit(char,char*);
char* upper(char,char*);
char lower(char);
char convert(int);

char* encrypt(char str[],char en[])
{
    char a[10],d[3],st[4];


    char ch,t;
    int x,len;


    strcpy(en,"");

    for(x=0;str[x]!='\0';x++)
    {
        ch=str[x];

        if(ch>=48 && ch<=57)
        {
            strcat(en,digit(ch,d));
        }
        else if(ch>=65 && ch<=90)
        {
            strcat(en,upper(ch,st));
        }

        else if(ch>=97 && ch<=122)
        {
            t=lower(ch);
            len=strlen(en);
            en[len]=t;
            en[len+1]='\0';
        }
        else
        {
            len=strlen(en);
            en[len]=ch;
            en[len+1]='\0';
        }

    }

  len=strlen(en);
  en[len]='\0';

 strcpy(en,strrev(en));
  return en;

}

char* digit(char ch,char d[])
{ //char d[2];
    switch(ch)
    {
        case '0':strcpy(d,"Z");break;
        case '1':strcpy(d,"O");break;
        case '2':strcpy(d,"Tw");break;
        case '3':strcpy(d,"Th");break;
        case '4':strcpy(d,"Fo");break;
        case '5':strcpy(d,"Fi");break;
        case '6':strcpy(d,"Si");break;
        case '7':strcpy(d,"Se");break;
        case '8':strcpy(d,"E");break;
        case '9':strcpy(d,"N");break;
    }
  return d;

}

char lower(char ch)
{
    char c;
    int x,pos=0;
    for(x=97;x<=ch;x++)
    {
        ++pos;
    }
  c=-pos-1;

 return c;
}

char* upper(char ch,char st[])
{
    int x,y,pos=0;
    //char str[2];

        for(x=65;x<=ch;x++)
        {
            ++pos;
        }

    y=pos;

        if(y/10==0)
        {
            st[0]=convert(y);
            st[1]='\0';
        }
        else
        {
            st[0]=-108;
            st[1]=convert(y/10);
            st[2]=convert(y%10);
            st[3]='\0';
        }

  return st;

}
char convert(int n)

{char ch;
      switch(n)
     {
        case 0:ch='0';break;
        case 1:ch='1';break;
        case 2:ch='2';break;
        case 3:ch='3';break;
        case 4:ch='4';break;
        case 5:ch='5';break;
        case 6:ch='6';break;
        case 7:ch='7';break;
        case 8:ch='8';break;
        case 9:ch='9';break;
     }


    return ch;
}

