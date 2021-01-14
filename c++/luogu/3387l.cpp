#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e5+5;
struct aa{
	int next,to;
}edge[MAXM];
int head[MAXN],cnt;
int a[MAXN],n,m;
inline void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}

//------------------------
int dfn[MAXN],num;
int co[MAXN],col;
int st[MAXN],top;
int low[MAXN];
int dis[MAXN],cost[MAXN];
void tarjan(int u)
{
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else
		{
			if(!co[v])
			{
				low[u]=min(low[u],dfn[v]);
			}
		}
	}
	if(dfn[u]==low[u])
	{
		co[u]=++col;
		cost[col]+=a[u];
		while(st[top]!=u)
		{
			co[st[top]]=col;
			cost[col]+=a[st[top]];
			top--;
		}
		top--;//important!!!!!!!
	}
}

//-----------------
struct bb{
	int to,next;
}neweg[MAXM];
int h[MAXN];
int ru[MAXN];
inline void add2(int from,int to)
{
	neweg[++cnt].to=to;
	neweg[cnt].next=h[from];
	h[from]=cnt;
}
queue<int> q;
void work()
{
	for(int i=1;i<=col;i++)
		if(ru[i]==0)
		{
			q.push(i);
			dis[i]=cost[i];
		}
			
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=neweg[i].next)
		{
			int v=neweg[i].to;
			ru[v]--;
			dis[v]=max(dis[v],dis[u]+cost[v]);
			if(ru[v]==0) q.push(v);
		}
	}
}
int main()
{
 	freopen("P3387_1.in","r",stdin);
 	int x,y;
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d",&a[i]);
 	}
 	for(int i=1;i<=m;i++)
 	{
 		scanf("%d%d",&x,&y);
 		add(x,y);
 	}
 	for(int i=1;i<=n;i++)
 	{
 		if(!dfn[i]) tarjan(i);
 	}
 	//-------------清零 
 	//memset(h,0,sizeof(h));
 	cnt=0;
 	for(int u=1;u<=n;u++)
 	{
 		for(int j=head[u];j;j=edge[j].next)
 		{
 			int v=edge[j].to;
 			if(co[u]!=co[v])
 			{
 				add2(co[u],co[v]);
 				ru[co[v]]++;
 			}
 		}
 	}
 	work();
 	int ans=0;
 	for(int i=1;i<=col;i++)
 	{
 		ans=max(ans,dis[i]);
 	}
 	printf("%d",ans);
}
//要记得注释掉open

