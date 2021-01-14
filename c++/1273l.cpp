#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=3000+5;
struct aa{
	int next,cost,to;
}node[MAXN];
int head[MAXN],cnt;
inline void add(int from,int to,int cost)
{
	node[++cnt].to=to;
	node[cnt].cost=cost;
	node[cnt].next=head[from];
	head[from]=cnt;
}
int n,m;
int a[MAXN];
int dp[MAXN][MAXN];
int dfs(int u)
{
	if(u>=n-m+1)
	{
		dp[u][1]=a[u-(n-m)];
		return 1;
	}
	int sum=0;
	for(int i=head[u];i;i=node[i].next)
	{
		int v=node[i].to;
		sum+=dfs(v);
		for(int j=sum;j>=0;j--)
		{
			for(int k=1;k<=j;k++)
			{
				dp[u][j]=max(dp[u][j],dp[v][k]+dp[u][j-k]-node[i].cost);
			}
		}
	}
	return sum;
}
int main()
{
 	freopen("in.txt","r",stdin);
 	int y,c,k;
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=n-m;i++)
 	{
 		scanf("%d",&k);
 		for(int j=1;j<=k;j++)
 		{
 			scanf("%d%d",&y,&c);
 			add(i,y,c);
 		}
 	}
 	for(int i=1;i<=m;i++)
 	{
 		scanf("%d",&a[i]);
 	}
 	memset(dp,~0x3f,sizeof(dp));
 	for(int i=1;i<=n;i++)
 	{
 		dp[i][0]=0;
 	}
 	dfs(1);
 	for(int i=m;i>=1;i--)
 	{
 		if(dp[1][i]>=0)
 		{
 			printf("%d",i);
 			return 0;
 		}
 	}
}
//Òª¼ÇµÃ×¢ÊÍµôopen

