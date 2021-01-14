#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue> 
using namespace std;
const int MAXM=2e5+5;
const int MAXN=1e5+5;
struct aa{
	int to;
	int next;
	int cost;
}node[MAXM];
int n,m,s,cnt;
int head[MAXN];
template <class T> inline void rd(T &x)
{
	x=0;
	char ch;
	while(ch=getchar())
	{
		if(ch>='0'&&ch<='9') break;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
}
inline void add(int from,int to,int cost)
{
	node[++cnt].to=to;
	node[cnt].next=head[from];
	head[from]=cnt;
	node[cnt].cost=cost;
}
//-------
int dis[MAXN];
bool tag[MAXN];
#define push(a,b) q.push(make_pair(a,b)) 
priority_queue < pair< int ,int > >q;
inline void dijkstra()
{
	//memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	push(0,1);
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(tag[u]) continue;
		tag[u]=1;
		for(int i=head[u];i;i=node[i].next)
		{
			int v=node[i].to;
			int cost=node[i].cost;
			if(dis[v]>dis[u]+cost)
			{
				dis[v]=dis[u]+cost;
				push(-dis[v],v);
			}
		}
	}
}
int main()
{
 	freopen("in.txt","r",stdin);
 	int x,y,w;
 	rd(n),rd(m),rd(s);
 	for(int i=1;i<=m;i++)
 	{
 		rd(x),rd(y),rd(w);
 		add(x,y,w);
 	}
 	for(int i=1;i<=n;i++) dis[i]=1e10;
 	dijkstra();
 	for(int i=1;i<=n;i++)
 	{
 		printf("%d ",dis[i]);
 	}
}
//Òª¼ÇµÃ×¢ÊÍµôopen

