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
#define ll long long
const int MAXN=5e6+5;
int n,p,k,inv_s,inv_k,k1;
int a[MAXN],inv[MAXN];
ll s[MAXN],ans;
inline int power(int a,int b)
{
	int ans=1,base=a;
	while(b)
	{
		if(b&1)
		{
			ans=(ll)ans*base%p;
		}
		base=(ll)base*base%p;
		b>>=1;
	}
	return ans%p;
}
int main()
{
 	freopen("in.txt","r",stdin);
 	rd(n),rd(p),rd(k);
 	s[0]=1;
 	for(int i=1;i<=n;i++)
 	{
 		rd(a[i]);
 		s[i]=(ll)s[i-1]*a[i]%p;
 	}
 	inv_s=power(s[n],p-2);
 	/*inv_k=power(k,p-2);
 	k=power(k,n);
 	for(int i=n;i>=1;i--)//=k^i * a[i]^-1
 	{//a[i]^-1=s[i-1] * invs[i]
 		ans=(ans+(ll)k*(s[i-1]*inv_s)%p)%p;
 		//inv_s[i-1]=inv_s[i] * a[i]
 		inv_s=(ll)inv_s *a[i]%p;
 		//k^(i-1)=k^i * inv_k
 		k=(ll)k*inv_k%p;
 	}*/
 	for(int i=n;i>=1;i--)
	{
	 	inv[i]=(ll)s[i-1]*inv_s%p;
	 	inv_s=(ll)inv_s *a[i]%p;
	} 
	k1=k;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+(ll)inv[i]*k1%p)%p;
		k1=(ll)k1*k%p;
	}
 	printf("%lld",ans);
}
//Òª¼ÇµÃ×¢ÊÍµôopen

