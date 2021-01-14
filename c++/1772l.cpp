#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
const int MAXN=105;
struct node{
	int to,next,cost;
}edge[10005];
int head[MAXN],cnt;
int n,m,t,k,d;
struct bb{
	int num,l,r;
}cant[10005];
inline bool cmp(const bb &x,const bb &y)
{
	return x.l==y.l? x.r<y.r:x.l<y.l;
}
inline void add(int from,int to,int cost)
{
	edge[++cnt].to=to;
	edge[cnt].cost=cost;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
priority_queue< pair<int,int> > q;
ll co[MAXN][MAXN];
ll dp[MAXN];
bool tag[MAXN];
int dis[MAXN];
bool no[MAXN];
#define push(a,b) q.push(make_pair(a,b))
void disj()
{
	memset(dis,0x7f,sizeof(dis));
	memset(tag,0,sizeof(tag));
	dis[1]=0;
	push(0,1);
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(tag[u]) continue;
		tag[u]=1;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(no[v]==1) continue;
			if(dis[v]>dis[u]+edge[i].cost)
			{
				dis[v]=dis[u]+edge[i].cost;
				push(-dis[v],v);
			}
		}
	}
	memset(no,0,sizeof(no));
}
int main()
{
	freopen("in.txt","r",stdin);
	int x,y,c,p;
	scanf("%d%d%d%d",&t,&n,&k,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		add(x,y,c);
		add(y,x,c);
	}
	scanf("%d",&d);
	cnt=0;
	for(int i=1;i<=d;i++)
	{
		scanf("%d%d%d",&p,&x,&y);
		cant[++cnt].num=p;
		cant[cnt].l=x;
		cant[cnt].r=y;
	}
	sort(cant+1,cant+1+cnt,cmp);
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=t;j++)
		{
			for(int k=1;k<=d;k++)
			{
				if(!(cant[k].r<i||cant[k].l>j))	
				{
					no[cant[k].num]=1;
				}
				if(cant[k].l>j) break;
			}
			disj();
			co[i][j]=dis[n];
		}
	}
	/*for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=t;j++)
		{
			cout<<co[i][j]<<" ";
		}
		cout<<endl;
	}*/
//	memset(dp,0x3f,sizeof(dp));
	//dp[1]=co[1][1];
	for(int i=1;i<=t;i++) dp[i]=1e6+5;
	for(int i=1;i<=t;i++)
	{
		dp[i]=co[1][i]*i;
		for(int j=0;j<i;j++)
		{
			dp[i]=min(dp[i],dp[j]+co[j+1][i]*(i-j)+k);
		}
	}
	cout<<dp[t];
 	return 0;
}
