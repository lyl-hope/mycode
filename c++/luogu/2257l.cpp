#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
const int MAXN=1000000;
ll mu[MAXN+10],prime[MAXN+10],v[MAXN+10],f[MAXN+10],s[MAXN+10];
ll m;
void calc()
{
	mu[1]=1;
	for(int i=2;i<=MAXN;i++)
	{
		if(v[i]==0)
		{
			v[i]=i;
			prime[++m]=i;
			mu[i]=-1;
		}
		for(int j=1;j<=m;j++)
		{
			int p=prime[j];
			if(p>v[i]||p*i>MAXN) break;
			v[p*i]=p;
			if(i%p==0) break;//i中有p的因子 
			mu[p*i]=-mu[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		int p=prime[i];
		for(int j=1;j*p<MAXN;j++)
		{
			f[j*p]+=mu[j];//+???求第二个的和 
		}
	}
	for(int i=1;i<=MAXN;i++)
	{
		s[i]=s[i-1]+f[i];
	} 
}
ll sol(int a,int b)
{
	int minn=min(a,b);
	ll ans=0;
	for(int l=1;l<=minn;)
	{
		int r=min(a/(a/l),b/(b/l));
		ans+=(s[r]-s[l-1])*(ll)(a/r)*(ll)(b/r);//a,b/l也可 
		l=r+1;
	}
	return ans;
}
int main()
{
 	freopen("P2257.in","r",stdin);
 	calc();
 	int n,m,t;
 	scanf("%d",&t);
 	while(t--)
 	{
 		scanf("%d%d",&n,&m);
 		ll ans=sol(n,m);
 		printf("%lld\n",ans);
 	}
}
//要记得注释掉open

