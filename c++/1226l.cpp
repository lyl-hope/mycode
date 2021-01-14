#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
inline ll pow(ll a,ll b,ll c)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1)
		{
			ans=ans*base%c;
		}
		base=base*base%c;
		b>>=1;
	}
	return ans%c;
}
int main()
{
 	freopen("in.txt","r",stdin);
 	ll a,b,c;
 	scanf("%lld%lld%lld",&a,&b,&c);
 	printf("%lld^%lld mod %lld=%lld",a,b,c,pow(a,b,c));
}
//Òª¼ÇµÃ×¢ÊÍµôopen

