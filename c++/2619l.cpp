#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
const int MAXN=5e4+5;
const int MAXM=1e5+5;
int n,m,need;
struct aa{
	int s,to,cost,col;
}edge[MAXM];
int cnt;
inline void add(int from,int to,int cost,int col)
{
	edge[++cnt].to=to;
	edge[cnt].s=from;
	edge[cnt].cost=cost;
	edge[cnt].col=col;
}
inline bool cmp(const aa &x,const aa &y)
{
	return x.cost==y.cost ? x.col<y.col : x.cost<y.cost;
}
int f[MAXN],num;
ll res=0;
inline int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
inline void kruskal()
{
	int c=0;
	num=0,res=0;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u=edge[i].s;
		int v=edge[i].to;
		int xx=find(u);
		int yy=find(v);
		if(xx==yy)
		{
			continue;
		}
		else
		{
			c++;
			f[xx]=yy;
			res+=edge[i].cost;
			//printf("%d\n",res);
			if(edge[i].col==0) num++;
		}
		if(c==n-1) return;
	}
}
int main()
{
	int x,y,c,co;
 	freopen("in.txt","r",stdin);
 	scanf("%d%d%d",&n,&m,&need);
 	n++;
 	for(int i=1;i<=m;i++)
 	{
 		scanf("%d%d%d%d",&x,&y,&c,&co);
 		x++;
 		y++;
 		add(x,y,c,co);
 	}
 	//kruskal();
 	int l=-105,r=105;
 	int count=0;
 	while(l<=r)
 	{
 		int mid=l+r>>1;
 		for(int i=1;i<=m;i++)
 		{
 			if(edge[i].col==0)
 			{
 				edge[i].cost-=mid;
 			}
 		}
 		kruskal();
 		if(num<need)//白应该再多一点 
 		{
 			l=mid+1;
 		}
 		else if(num>need)
 		{
 			r=mid-1;
 		}
 		else
 		{
 			count=mid;break;
 			//ans=min(ans,res+need*mid);
 		}
 		for(int i=1;i<=m;i++)
 		{
 			if(edge[i].col==0)
 			{
 				edge[i].cost+=mid;
 			}
 		}
 	}
 	printf("%lld",res+need*count);
}
