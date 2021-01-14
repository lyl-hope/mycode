#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
const ll M=1000000007;
ll n,k;

struct matrix{
	ll d[105][105];
	matrix()//一定要清零！！！ 
	{
		memset(d,0,sizeof(d));
	}
	friend matrix operator*(const matrix &a,const matrix &b)
	{
		matrix ans1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					ans1.d[i][j]+=(a.d[i][k] * b.d[k][j]%M);
					ans1.d[i][j]=ans1.d[i][j]%M;
				}
			}
		}
		return ans1;
	}
};
matrix a;
matrix pow(matrix a,ll b)
{
	matrix ans,base=a;
	for(int i=1;i<=n;i++)
	{
		ans.d[i][i]=1;
	}
	while(b)
	{
		if(b&1)
		{
			ans=ans*base;
		}
		base=base*base;
		b>>=1;
	}
	return ans;
}
int main()
{
 	freopen("P3390_1.in","r",stdin);
 	freopen("out.txt","w",stdout) ;
 	scanf("%lld%lld",&n,&k);
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			scanf("%lld",&a.d[i][j]);
 		}
 	}
 	matrix res=pow(a,k);
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			printf("%lld ",res.d[i][j]);
 		}
 		printf("\n");
 	}
}
//要记得注释掉open

