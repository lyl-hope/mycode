#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
const ll M=1e9+7;
ll n;
struct matrix{
	ll d[4][4];
	matrix()
	{
		memset(d,0,sizeof(d));
	}
	friend matrix operator *(const matrix &x,const matrix &y)
	{
		matrix ans1;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					ans1.d[i][j]+=(x.d[i][k]*y.d[k][j]%M)%M;
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
	for(int i=1;i<=3;i++)
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
 	freopen("in.txt","r",stdin);
 	int T;
 	scanf("%d",&T);
 	for(int k=1;k<=T;k++)
 	{
 		scanf("%lld",&n);
	 	if(n==1||n==2||n==3)
	 	{
	 		printf("1\n");
	 		continue;
	 	}
	 	//memset(qwq.d,0,sizeof(qwq.d));
	 	qwq.d[1][1]=1,qwq.d[1][2]=0,qwq.d[1][3]=1;
	 	qwq.d[2][1]=1,qwq.d[2][2]=0,qwq.d[2][3]=0;
	 	qwq.d[3][1]=0,qwq.d[3][2]=1,qwq.d[3][3]=0;
	 	lyl.d[1][1]=1;
	 	lyl.d[2][1]=1;
	 	lyl.d[3][1]=1;
	 	matrix res=pow(qwq,n-3)*lyl;
	 	printf("%lld\n",res.d[1][1]);
	}
}
//Òª¼ÇµÃ×¢ÊÍµôopen

