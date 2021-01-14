#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
const ll m=1e9+7;
ll n;
struct matrix{
	ll d[5][5];
	matrix()
	{
		memset(d,0,sizeof(d));
	}
	friend matrix operator *(const matrix &x,const matrix &y)
	{
		matrix ans1;
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=2;j++)
			{
				for(int k=1;k<=2;k++)
				{
					ans1.d[i][j]+=x.d[i][k] * y.d[k][j]%m;
					ans1.d[i][j]=ans1.d[i][j]%m;
				}
			}
		}
		return ans1;
	}
}; 
matrix qwq;
matrix lyl;
inline matrix pow(matrix a,ll b)
{
	matrix ans,base=a;
	for(int i=1;i<=4;i++)
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
 //	freopen("in.txt","r",stdin);
 	scanf("%lld",&n);
 	if(n==1||n==2)
 	{
 		printf("1");
 		return 0;
 	}
 	qwq.d[1][1]=1;
 	qwq.d[1][2]=1;
 	qwq.d[2][1]=1;
 	lyl.d[1][1]=1;
 	lyl.d[2][1]=1;
 	matrix res=pow(qwq,n-2)*lyl;
 	printf("%lld",res.d[1][1]);
}
//Òª¼ÇµÃ×¢ÊÍµôopen
