#include<iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long
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
	if(x<0)
	{
		ll k=ceil((1.0-x)/m);
		x+=k*m;
	}
	else
	{
		ll k=(x-1)/m;
		x-=k*m;
	}
	return x;
}
int main()
{
 	//freopen("in.txt","r",stdin);
 	ll a,b;
 	scanf("%lld%lld",&a,&b);
 	printf("%lld",inv(a,b)); 
}
//Òª¼ÇµÃ×¢ÊÍµôopen

