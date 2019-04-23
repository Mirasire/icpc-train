#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	int cnt=0;
	cin>>T;
	while (T--)
	{
		cnt++;
		printf("Case %d: ",cnt);
		int n,m;
		cin>>n>>m;
		int *a=new int[n];
		int *b=new int[m];
		for (int i=0;i<n;i++)
			cin>>a[i];
		for (int i=0;i<m;i++)
			cin>>b[i];
		int x=0,y=0;
		bool Enda=false;
		bool Endb=false;
		bool Choose=false;
		while (x<n&&y<m)
		{
			if (a[x]<b[y])
				cout<<b[y++];
			else if (a[x]>b[y])
				cout<<a[x++];
			else
			{
				if (a.substr(x)>b.substr(y))
					cout<<a[x++];
				else cout<<b[y++];
			}
		}
		while (x<n)
			cout<<a[x++];
		while (y<m)
			cout<<b[y++];
		cout<<endl;
		delete []a;
		delete []b;
	}
}