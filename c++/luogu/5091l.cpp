#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll unsigned long long
bool flag;
ll a,phi,m,b;
inline ll calc(ll n)
{
	ll res=n;
	for(ll i=2;(ll)i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0) n/=i;
			res=res/i*(i-1);
		}
	}
	if(n>1) res=res/n*(n-1);
	return res;
}
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
		if(x>=phi) x=x%phi,flag=1;
		ch=getchar();
	}
	return;
}
inline ll power(ll a,ll b)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1)
		{
			ans=ans%m*base%m;
		}
		base=base%m*base%m;
		b>>=1;
	}
	return ans%m;
}
int main()
{
 	freopen("in.txt","r",stdin);
 	scanf("%lld%lld",&a,&m);
 	phi=calc(m);
 	rd(b);
 	if(flag)
 		b+=phi;
 	printf("%llu",power(a,b));
}
//Òª¼ÇµÃ×¢ÊÍµôopen

