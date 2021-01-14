#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
template <class T>inline void rd(T &x)
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
	return;
}
typedef long long ll;
const int MAXN=20;
ll m[MAXN],a[MAXN],n;
inline void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
	return;
}
inline ll inv(ll a,ll m)
{
	ll x,y;
	exgcd(a,m,x,y);
	return x;
}
inline ll CRT()
{
	ll M=1,res=0;
	for(int i=1;i<=n;i++)
	{
		M*=m[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll Mi=M/m[i];
		ll ti=inv(Mi,m[i]);
		res=(res+a[i]*Mi*(ti<0?ti+m[i]:ti))%M;
	}
	return res;
}
int main()
{
 	freopen("P1495.in","r",stdin);
 	rd(n);
 	for(int i=1;i<=n;i++)
 	{
 		rd(m[i]),rd(a[i]);
 	}
 	printf("%lld",CRT());
}
//Òª¼ÇµÃ×¢ÊÍµôopen

