#include<iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;
const int MAXN=300005;
struct aa{
	int to,next,cost;
}node[MAXN];
int n,cnt,k;
long long ans;
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
inline void add_edge(const int &x,const int &a,const int &b)
{
	switch (x)
	{
		case 1 :{
			add(a,b,0),add(b,a,0);
			break;
		}
		case 2 :{
			add(a,b,1);
			break;
		}
		case 3 :{
			add(b,a,0);
			break;
		}
		case 4 :{
			add(b,a,1);
			break;
		}
		case 5 :{
			add(a,b,0);
			break;
		}
	}
	return;
}

//---------------
int dis[MAXN];
bool tag[MAXN];
int cal[MAXN];
queue <int> q;
inline void spfa()
{
	//for(int i=1;i<=n;i++) dis[i]=-INF;
	dis[0]=1;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		if(cal[u]>n)
		{
			printf("-1");
			exit(0);
		}
		cal[u]++;
		q.pop();
		tag[u]=0;
		for(int i=head[u];i;i=node[i].next)
		{
			int v=node[i].to;
			int cost=node[i].cost;
			if(dis[v]<dis[u]+cost)
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
 //	freopen("candy5.in","r",stdin);
 	int x,a,b;
 	//scanf("%d%d",&n,&k);
 	rd(n),rd(k);
 	for(int i=1;i<=k;i++)
 	{
 		//scanf("%d%d%d",&x,&a,&b);
 		rd(x),rd(a),rd(b);
 		if(x==2&&a==b || x==4&&a==b)
 		{
 			cout<<"-1";
 			return 0;
 		}
 		add_edge(x,a,b);
 	}
 	for(int i=n;i>=1;i--) add(0,i,0);
 	spfa();
 	for(int i=1;i<=n;i++)
 	{
 		ans+=dis[i];
 	}
 	printf("%lld",ans);
}
//Òª¼ÇµÃ×¢ÊÍµôopen

