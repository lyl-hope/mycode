#include<iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long
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
ll T,x,y;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

int main()
{
 	freopen("in.txt","r",stdin);
 	ll a,b,c;
 	rd(T);
 	while(T--)
 	{
 		rd(a),rd(b),rd(c);
 		ll d=exgcd(a,b,x,y);
 		if(c%d!=0)
 		{
 			printf("-1\n");
 			continue;
 		}
 		x*=c/d,y*=c/d;
 		ll p=b/d;
 		ll q=a/d;
 		if(x<0)//调整x为最小正整数 
 		{
 			ll t=ceil((1.0-x)/p);
 			x=x+p*t,y=y-q*t;
 		}
 		else
 		{
 			ll t=(x-1)/p;
 			x-=p*t,y+=q*t;
 		}
 		if(y>0)
 		{
 			ll num=(y-1)/q+1;
 			printf("%lld %lld %lld %lld %lld\n",num,x,y-(y-1)/q*q,x+(y-1)/q*p,y);
		} 
		else
		{
			printf("%lld %lld\n",x,y+(ll)ceil((1.0-y)/q)*q);
		}
 	}
}
//要记得注释掉open

