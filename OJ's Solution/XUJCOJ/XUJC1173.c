#include <stdio.h>
#include <string.h>

#define N 10000

int Equal(char *str,char *Base,int n,int lon);
char Tmp[N],Input[N];

int main()
{
    int n;
    scanf("%d",&n);
    scanf(" %s",Input);
    for(int i=0; i<n; i++)
    {
        memset(Tmp,'\0',sizeof(char)*N);
        for(int j=0; j<=i; j++) Tmp[j]=Input[j];
        if(Equal(Tmp,Input,i+1,n)) printf("%s\n",Tmp);
    }
    return 0;
}

int Equal(char *str,char *Base,int n,int lon)
{
    for(int i=0; i<lon; i++)
    {
        if(str[i%n]!=Base[i])   return 0;
    }
    return 1;
}
