#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

//ans可能爆long long
const int N=200010;
int deg[N];
ll w[N],cnt[N]; 
int v[N];
int s,n,m;
queue<int> Q;
vector<int> ed[N];


//对于单点的考虑 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		ed[a].push_back(b);
		ed[b].push_back(a);
		deg[a]++;//出度
		deg[b]++;//出度 
	}
	scanf("%d",&s);
	
	for(int i=1;i<=n;i++) if(deg[i]==1 && i!=s) Q.push(i);//叶子
 
	while(!Q.empty()){
		int now=Q.front();Q.pop();
		deg[now]=-1;//不能deg[now]--，对于孤立点的考虑 
		
		for(auto nxt:ed[now]){
			if(deg[nxt]<0) continue;//1->2
			
			deg[nxt]--;
			cnt[nxt]=max(cnt[nxt],cnt[now]+w[now]);
			
			if(deg[nxt]==1 && nxt!=s) Q.push(nxt);
		}
	} 
	
	ll sum=0,sum1=0;
	for(int i=1;i<=n;i++){
		if(deg[i]<0) continue;//不能等于0，如果是孤立点，将少考虑一种情况 
		sum+=w[i];
		sum1=max(sum1,cnt[i]);
	}
	
	ll ans=sum+sum1;
	cout<<ans<<"\n";
	return 0;
}