#include<string.h>


int deconvert(char);

char* decrypt(char en[],char den[])
{
   char dch,lch,uch;
    int i,dpos,dx,dlen,d1,d0,dn;

  strcpy(en,strrev(en));

  for(i=0;en[i]!=0;i++)
  {
     dch=en[i];

     if(dch>=-27 && dch<=-2)
     {
         dch=-dch;
         dpos=dch-1;
         dpos=96+dpos;
         for(dx=97;dx<=122;dx++)
         {
             if(dx==dpos)
              {
                  lch=dx;
                  break;
              }
        }

         dlen=strlen(den);
         den[dlen]=lch;
         den[dlen+1]='\0';
     }

     else if (dch>=49 && dch<=57)
     {
         dpos=dch-48;
         dpos=64+dpos;
         for(dx=65;dx<dpos;dx++)
         {}
         uch=dx;
         dlen=strlen(den);
         den[dlen]=uch;
         den[dlen+1]='\0';

    }

    else if(dch==-108)
    {
        d1=deconvert(en[i+1]);
        d0=deconvert(en[i+2]);
        dpos=d1*10+d0;
        dpos=64+dpos;
        for(dx=65;dx<dpos;dx++)
        {}
        uch=dx;
        dlen=strlen(den);
        den[dlen]=uch;
        den[dlen+1]='\0';
        i=i+2;
    }

    else if(dch>=65 && dch<=90)
    {
        switch(dch)
        {
            case 'Z':dn=0;break;
            case 'O':dn=1;break;
            case 'N':dn=9;break;
            case 'E':dn=8;break;
            case 'T':
                     switch(en[i+1])
                     {
                         case 'w':dn=2;i++;break;
                         case 'h':dn=3;i++;break;
                     }
                     break;
            case 'F':
                     switch(en[i+1])
                     {
                         case 'o':dn=4;i++;break;
                         case 'i':dn=5;i++;break;
                     }
                     break;
            case 'S':
                     switch(en[i+1])
                     {
                         case 'i':dn=6;i++;break;
                         case 'e':dn=7;i++;break;
                     }
                     break;
        }

        uch=convert(dn);
        dlen=strlen(den);
        den[dlen]=uch;
        den[dlen+1]='\0';

    }

     else
     {
        dlen=strlen(den);
        den[dlen]=dch;
        den[dlen+1]='\0';

     }

  }

return den;

}



int deconvert(char ch)
{
    int x;
    switch(ch)
    {
        case '0':x=0;break;
        case '1':x=1;break;
        case '2':x=2;break;
        case '3':x=3;break;
        case '4':x=4;break;
        case '5':x=5;break;
        case '6':x=6;break;
        case '7':x=7;break;
        case '8':x=8;break;
        case '9':x=9;break;
    }
return x;

}

