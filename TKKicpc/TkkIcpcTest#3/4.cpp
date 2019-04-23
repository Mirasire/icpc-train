#include<iostream>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include <cstdio>
using namespace std;
int a[100100],b[100100];

int main()
{
    //freopen("in","r",stdin);
    int T,t=0;
    scanf("%d",&T);
    while(T--)
    {
        t++;
        memset(a,0,400400);
        memset(b,0,400400);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
        printf("Case %d: ",t);
        int i=0,j=0;
        while(i<n&&j<m)
        {
            //cout << "Q3" << endl;
            if(a[i]>b[j])
            printf("%c",(char)(a[i]+'0')),i++;
            else if(a[i]<b[j])
            printf("%c",(char)(b[j]+'0')),j++;
            else
            {
                //cout<<"Q2"<<endl;
                bool flag=false;
                int x=i+1,y=j+1;
                //cout << "x " << x << ' ' << "y " << y << endl;
                while(x<=n&&y<=m)
                {
                    if(x==n)
                         x--;
                    if(y==m)
                        y--;
                    if(x==n-1&&y==m-1)
                    {
                        for(int k=i;k<n;k++)            
                        printf("%c",(char)(a[k]+'0'));
                        for(int k=j;k<m;k++)
                        printf("%c",(char)(b[k]+'0'));
                        i=n,j=m;
                        flag=true;
                    }
                    if(a[x]!=b[y]||a[x]!=a[i]||b[y]!=b[j])
                    {
                        if(max(a[x],b[y])<=a[i])
                        {
                           //cout << "Q1" << endl;
                            for(int k=i;k<x;k++)
                            printf("%c",(char)(a[k]+'0'));
                            for(int k=j;k<y;k++)
                            printf("%c",(char)(b[k]+'0'));
                            i=x,j=y;
                            flag=true;
                        }
                        else if(a[x]>b[y])
                        {
//cout << "Q2" << endl
                            for(int k=i;k<=x;k++)
                            printf("%c",(char)(a[k]+'0'));
                            i=x+1;
                            flag=true;
                        }
                        else if(a[x]<b[y])
                        {
                            //cout << "Q3" << endl;
                            for(int k=i;k<=y;k++)
                            printf("%c",(char)(b[k]+'0'));
                            j=y+1;
                            flag=true;
                        }
                    }
                    if(flag)
                    break;
                    x++,y++;
                }
            }
        }
        while(i<n || j<m)
        {
            if(i<n)
            {
                while(i<n) 
                {
                    printf("%c",(char)(a[i]+'0'));
                    i++;
                }
            }
            if(j<m)
            {
                while(j<m) 
                {
                    printf("%c",(char)(b[j]+'0'));
                    j++;
                }
            }
        }
        printf("\n");
    }
}
