    #include<iostream>
    #include<queue>
    #include<string.h> 
    using namespace std;
    int s,n,m;
    struct Node        //定义结构体，表明一种状态，分别为三个容器中水的体积，以及当前时间 
    {
    	int s,n,m,t;
    };
    //Node situation[105];
    Node st;
    bool vis[105][105];
    int bfs()
    {
    	queue<Node>q;              
    	st.s=s;
    	st.n=0;
    	st.m=0;
    	st.t=0;
    	q.push(st);              //把初始状况压入队列 
    	vis[0][0]=1;
    	vis[n][m]=1;
    	while(q.empty()!=1)
    	{
    		Node u=q.front();        //u为这一步的状态，为下一步v的初态 
    		Node v;
    		if(u.n==s/2&&u.s==s/2)return u.t;
    		v.t=u.t+1;
    		if(u.s!=0&&u.n!=n)                                //s->n
    		{
    			v.m=u.m;
    			if(u.n+u.s<=n)                               //倒不满 
    			{
    				v.s=0;
    				v.n=u.n+u.s;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    			else                                            //溢出来 
    			{
    				v.s=u.s+u.n-n;
    				v.n=n;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    		}
    		if(u.n!=0&&u.s!=s)                      //n->s
    		{
    			v.m=u.m;
    			if(u.n+u.s<=s)                         //倒不满 
    			{
    				v.s=u.n+u.s;
    				v.n=0;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    			else                                   //溢出来 
    			{
    				v.s=s;
    				v.n=u.s+u.n-s;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    		}
    		if(u.s!=0&&u.m!=m)       //s->m
    		{
    			v.n=u.n;
    			if(u.m+u.s<=m)     //倒不满 
    			{
    				v.s=0;
    				v.m=u.m+u.s;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    			else                //溢出来 
    			{
    				v.s=u.s+u.m-m;
    				v.m=m;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    		}
    		if(u.m!=0&&u.s!=s)                      //m->s
    		{
    			v.n=u.n;
    			if(u.m+u.s<=s)                       //倒不满 
    			{
    				v.s=u.m+u.s;
    				v.m=0;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    			else                            //溢出来 
    			{
    				v.s=s;
    				v.m=u.s+u.m-s;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    		}
    		if(u.n!=0&&u.m!=m)                      //n->m
    		{
    			v.s=u.s;
    			if(u.n+u.m<=m)                        //倒不满 
    			{
    				v.m=u.n+u.m;
    				v.n=0;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    			else
    			{
    				v.m=m;
    				v.n=u.m+u.n-m;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    		}
    		if(u.m!=0&&u.n!=n)       //m->n
    		{
    			v.s=u.s;
    			if(u.n+u.m<=n)     //倒不满 
    			{
    				v.m=0;
    				v.n=u.n+u.m;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    			else                //溢出来 
    			{
    				v.m=u.m+u.n-n;
    				v.n=n;
    				if(vis[v.n][v.m]==0)
    				{
    					q.push(v);
    					vis[v.n][v.m]=1;
    				}
    			}
    		}
    		q.pop();
    	}
    	return 0;
    }
    int main()
    {
    	while(cin>>s>>n>>m)
    	{
    		if(s==0&&n==0&&m==0)break;
    		if(s%2!=0)
    		{
    			cout<<"NO"<<endl;
    			continue;
    		}
    		if(m>n)swap(m,n);
    		memset(vis,0,sizeof(vis));
    		int time=bfs();
    		if(time!=0)
    			cout<<time<<endl;
    		else
    			cout<<"NO"<<endl;
    	}
    } 




