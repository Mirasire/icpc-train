#include<iostream>
#include<algorithm>
#include<ctime>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
using namespace std;

const int maxn = 1e5+100;
int sm[maxn];
int xm[maxn];

int  main()
{
    int T;
    int cnt = 0;
    scanf("%d",&T);
    while(T--)
    {
        memset(xm,0,sizeof(xm));
        memset(sm,0,sizeof(sm));
        int N,M;
        scanf("%d%d",&N,&M);
        for(int i=0; i<N; i++) scanf("%d",sm+i);
        for(int i=0; i<M; i++) scanf("%d",xm+i);
        //for(int i=0; i<N; i++) printf("%d ",sm[i]);
        //cout << endl;
        //for(int i=0; i<M; i++) printf("%d ",xm[i]);
        //cout << endl;
        int end = max(N,M);
        int i=0,j=0;
        printf("Case %d: ",++cnt);
        for( i=0,j=0; i<N&&j<M;)
        {
            if(sm[i] > xm[j])
            {
                printf("%d",sm[i]);
                i++;
            }
            else if(sm[i] == xm[j])
            {
                if(i==N-1&&j==M-1)
                {
                    printf("%d%d",sm[i],xm[j]);
                    i++,j++;
                }
                else
                {
                    int x=i+1,y=j+1;
                    if(x==N)
                    x--;
                    if(y==M)
                    y--;
                    if(sm[x]>xm[y])
                    {
                        printf("%d",sm[i]);i++;
                    }
                    else if(sm[x]<xm[y])
                    {
                        printf("%d",xm[j]);j++;
                    }
                    else
                    {
                        printf("%d",sm[i]);i++;
                    }
                }
            }
            else
            {
                printf("%d",xm[j]);
                j++;
            }
        }
        while(i<N || j<M)
        {
            if(i<N)
            {
                while(i<N) 
                {
                    printf("%d",sm[i]);
                    i++;
                }
            }
            if(j<M)
            {
                while(j<M) 
                {
                    printf("%d",xm[j]);
                    j++;
                }
            }
        }
        printf("\n");
    }
     return 0;
}
