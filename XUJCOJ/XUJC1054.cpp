#include <iostream>
#include <cstdio>
using namespace std;


const int maxn = 500000+5;
int number[maxn],tmp[maxn];
long long int ans=0;

void Mergesort(int q,int p)
{
    if(q<p)
    {
        int pos = (q+p)/2;
        Mergesort(q,pos);
        Mergesort(pos+1,p);
        int front=q,middle=pos+1,point=q;
        
        while(front <= pos && middle <= p)
        {
            if(number[front] <= number[middle]) 
            {
                tmp[point++] = number[front++];
            }
            else
            {
                tmp[point++] = number[middle++];
                ans+=(pos-front+1);
            }
        }
        while(middle <= p) tmp[point++] = number[middle++];
        while(front <= pos) tmp[point++] = number[front++];
        for(int i=q; i<=p; i++) number[i] = tmp[i];
    }
    return;
}

int main()
{
    int in;
    while(scanf("%d",&in)!=EOF && in)
    {
        ans=0;
        for(int i=0; i<in; i++) scanf("%d",number+i);
        Mergesort(0,in-1);
        cout << ans << endl;
    }
    return 0;
}

