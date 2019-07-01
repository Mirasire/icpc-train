//AcVersion
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string Target;
int c;
struct Node
{ 
	string s1,s2;
	int step;
	Node() : step(0) {}
};

string shuffle(string a,string b)
{
	string s12;
    string middle;
	for(int i=0; i<c; i++)	
    {
        middle = b[i];
        middle += a[i];
        s12 += middle;
    }
	return s12;
}

int bfs(Node in)
{
	Node now,next;
	queue<Node> List;
	map<string,bool> Visite;
	List.push(in);
	while(!List.empty())
	{
		now = List.front();
        List.pop();
		string key = shuffle(now.s1,now.s2);
		if(key==Target) return(now.step+1);
		else if(Visite[key]) return -1;
        Visite[key] = 1;
		string a,b;
		for(int i=0,j=c*2-1; i<c; i++,j--) a+=key[i],b=key[j]+b;
        //cout << a << endl;
        //cout << b << endl;
		next.s1 = a;
		next.s2 = b;
		next.step = now.step+1;
        List.push(next);
	}
	return -1;
}

int main()
{
    freopen("in","r",stdin);
	int N,cnt = 0;
	scanf("%d",&N);
	while(N--)
	{
		Node in;
		cin >> c >> in.s1 >> in.s2 >> Target;
        //cout << "Target " << Target << endl;
		printf("%d %d\n",++cnt,bfs(in));
	}
	return 0;
}
