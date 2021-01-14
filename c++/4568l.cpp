#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=(1e4+5)*11;
struct aa{
	int to;
	int next;
	int cost;
}node[2500001];
int n,m,k;
int s,t,cnt,minn=1e9;
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
	node[cnt].cost=cost;
	node[cnt].next=head[from];
	head[from]=cnt;
}

//----------
int dis[MAXN];
bool tag[MAXN];
priority_queue < pair<int ,int > >q;
#define push(a,b) q.push(make_pair(a,b))
inline void dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	push(0,s);
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(tag[u]) continue;
		tag[u]=1;
		for(int i=head[u];i;i=node[i].next)
		{
			int v=node[i].to;
			if(dis[v]>dis[u]+node[i].cost)
			{
				dis[v]=dis[u]+node[i].cost;
				push(-dis[v],v);
			}
		}
	}
}
int main()
{
 	freopen("in.txt","r",stdin);
 	int x,y,w;
 	rd(n),rd(m),rd(k);
 	rd(s),rd(t);
 	++s,++t;
 	for(int i=1;i<=m;i++)
 	{
 		rd(x),rd(y),rd(w);
 		++x,++y;
 		add(x,y,w);
 		add(y,x,w);
 		for(int j=1;j<=k;j++)
 		{
 			add(x+j*n,j*n+y,w);
 			add(j*n+y,x+j*n,w);
 			add(x+(j-1)*n,y+j*n,0);
 			add(y+(j-1)*n-n,x+j*n,0);
 		}
 	}
 	for(int i=1;i<=k;i++) add(t+(i-1)*n,t+i*n,0);
 	dijkstra();
 /*	for(int i=0;i<=k;i++)
 	{
 		minn=min(minn,dis[t+n*i]);
 	}*/
 	printf("%d",dis[t+n*k]);
}
//Òª¼ÇµÃ×¢ÊÍµôopen

