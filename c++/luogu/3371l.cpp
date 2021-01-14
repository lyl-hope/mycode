#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=5e5+5;
const int INF=(1<<31)-1;
struct aa{
	int to;
	int next;
	int cost;
}node[MAXM];
int n,m,s,cnt;
int head[MAXN];
template <class T>inline void rd(T &x)
{
	x=0;
	char ch;
	int sign=1;
	while(ch=getchar())
	{
		if(ch=='-') sign=-1;
		if(ch>='0'&&ch<='9') break;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	x=x*sign;
	return;
}
inline void add(int from,int to,int cost)
{
	node[++cnt].to=to;
	node[cnt].cost=cost;
	node[cnt].next=head[from];
	head[from]=cnt;
}

//-----
int dis[MAXN];
bool tag[MAXN];
int cal[MAXN];
queue <int>q;
inline void spfa()
{
	dis[s]=0;
	tag[s]=1;//whether the number is in the queue
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		tag[u]=0;
		if(cal[u]>n)
		{
			cout<<INF;
			exit(0);
		}
		cal[u]++;
		for(int i=head[u];i;i=node[i].next)
		{
			int v=node[i].to;
			int cost=node[i].cost;
			if(dis[v]>dis[u]+cost)
			{
				dis[v]=dis[u]+cost;
				if(!tag[v])
				{
					q.push(v);
					tag[v]=1;
				}
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
 	for(int i=1;i<=n;i++) dis[i]=INF;
 	spfa();
 	for(int i=1;i<=n;i++)
 	{
 		printf("%d ",dis[i]);
 	}
}
//Òª¼ÇµÃ×¢ÊÍµôopen

