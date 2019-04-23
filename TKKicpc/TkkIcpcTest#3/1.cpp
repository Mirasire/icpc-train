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

int  main()
{
	int T,n;
	int t=0;
	scanf("%d",&T);
	while(T--)
	{
		t++;
		int ans=0;
		scanf("%d",&n);
		stack<int>a,b;
		for(int i=0;i<n;i++)
		{
			int p;
			scanf("%d",&p);
			a.push(p);
		}
		for(int i=0;i<n;i++)
		{
			int p;
			scanf("%d",&p);
			b.push(p);
		}
		while(!a.empty())
		{
                        if(a.top()+b.top()>10)
			ans++;
			a.pop(),b.pop();
		}
		printf("Case %d: %d\n",t,ans);
	}
}