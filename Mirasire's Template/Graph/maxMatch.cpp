//=============dfs找增广路部分=============
//n为Y集,base1
bool dfs(int u) {
	for(int v=1; v=n; v++) {
		if(line[u][v] && !vis[v]) { //!!
			vis[v] = 1;
			if(match[v]==-1 || dfs(match[v])) {
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

//=============调用部分=============
int sum = 0; //记录匹配数目
memset(match,-1,sizeof(match)); //初始化Y匹配的X的编号

for(int i=1; i<=n; i++) {
	memset(vis,0,sizeof(vis)); //!!
	if(dfs(i)) sum++;
}
