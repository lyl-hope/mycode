#include<iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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
#define ll long long
inline ll getphi(ll n)
{
	ll res=n;
	for(int i=2;(ll)i*i<=n;i++)
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
ll ans,n;
int main()
{
 	freopen("in.txt","r",stdin);
 	rd(n);
 	ll sqr=sqrt(n);
 	for(int i=1;i<sqr;i++)
 	{
 		if(n%i==0)
 		{
 			ans+=i*getphi(n/i);
 			ans+=(n/i)*getphi(i);
 		}
 	}
 	if(sqr*sqr==n)
 	{
 		ans+=sqr*getphi(sqr);
 	}
 	else
 	{
 		if(n%sqr==0)
 		{
 			ans+=sqr*getphi(n/sqr);
 			ans+=(n/sqr)*getphi(sqr);
 		}
 	}
 	printf("%lld",ans);
}
//Òª¼ÇµÃ×¢ÊÍµôopen

