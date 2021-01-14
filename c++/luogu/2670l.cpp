#include <iostream>
#include <cstdio>
using namespace std;
int a[105][105];
int n,m;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	char x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//scanf("%c",&x);
			cin>>x;
			if(x=='*') a[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==1)
			{
				printf("*");
			}
			else
			{
				printf("%d",a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1]+a[i-1][j-1]+a[i-1][j+1]+a[i+1][j+1]+a[i+1][j-1]);
			}
		}
		printf("\n");
	}
}
