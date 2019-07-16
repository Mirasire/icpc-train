#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
int main() 
{
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    int cnt=0;
    char c;
    char s[10005];
    while(gets(s))
    {
        //printf("%s\n",s);
        _Bool flag=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='}')
                cnt--;
        }
        for(int i=0;i<strlen(s);i++)
        {
            if(flag)
            { for(int j=0;j<4*cnt;j++)
                    printf(" ");
                    flag=0;
            }
            c=s[i];
            if(c=='{')
            {
                cnt++;
                if(cnt!=1)
                    printf(" ");
                    //cout<<" ";
                printf("%c\n",c);
                flag=1;
                //cout<<c<<endl;
            }
            else if(c==',')
                printf("%c ",c);
                //cout<<c<<" ";
            else if(c==';')
                printf("%c\n",c),flag=1;
                //cout<<c<<endl;
            else if(c!=' '&&c!='\t')
                printf("%c",c);
                //cout<<c;
        }
    }
}
