#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue> 
#include <cstdlib> 
using namespace std;
const int MAXN=5e4+5;
struct aa{
	int to,next,cost;
}node[MAXN];
int n,m,cnt;
int head[MAXN];
inline void add(int from,int to,int cost)
{
	node[++cnt].to=to;
	node[cnt].cost=cost;
	node[cnt].next=head[from];
	head[from]=cnt;
}

//--------------
int dis[MAXN];
bool tag[MAXN];
int cal[MAXN];
queue <int> q;
inline void spfa()
{
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		if(cal[u]>n+1)
		{
			printf("NO");
			exit(0);
		}
		cal[u]++;
		q.pop();
		tag[u]=0;
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
 	freopen("P5960_1.in","r",stdin);
 	freopen("out.txt","w",stdout);
 	//memset(head,-1,sizeof(head));
 	int x,y,c;
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=m;i++)
 	{
 		scanf("%d%d%d",&x,&y,&c);
 		add(y,x,c);
 	}
 	for(int i=1;i<=n;i++)
 	{
 		add(0,i,0);
 	}
 	spfa();
 	printf("%d",dis[1]);
 	for(int i=2;i<=n;i++) printf(" %d",dis[i]);
}
//Òª¼ÇµÃ×¢ÊÍµôopen

