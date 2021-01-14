#include<iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define ll long long
template <class T>inline void rd(T &x) 
{
	x=0;
	int sign=1;char ch;
	while(ch=getchar())
	{
		if(ch=='-') sign=-1;
		if(ch>='0'&&ch<='9') break;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	x=x*sign;
	return;
}
const int MAXN=1e6+5;
int n;
int a[2][MAXN],b[2][MAXN];
int f[MAXN*2];
struct POS{
	int i,j;
}seat[MAXN*2];
inline void judge()
{
	for(int i=1;i<=n;i++)
	{
		f[a[0][i]]=a[1][i];
		f[a[1][i]]=a[0][i];
	}
	for(int i=1;i<=n;i++)//判断不在同一列 
	{
		if(f[b[0][i]]!=b[1][i]||f[b[1][i]]!=b[0][i])
		{
			printf("dldsgay!!1");
			exit(0);
		}
	}
	//---------
	for(int i=1;i<=n;i++)
	{
		seat[a[0][i]].j=1;
		seat[a[0][i]].i=i;
		seat[a[1][i]].j=2;
		seat[a[1][i]].i=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(((seat[b[0][i]].i+seat[b[0][i]].j)&1)!=((i+1)&1))
		{
			puts("dldsgay!!1");
			exit(0);
		}
		if(((seat[b[1][i]].i+seat[b[1][i]].j)&1)!=((i+2)&1))
		{
			puts("dldsgay!!1");
			exit(0);
		}
	}
	return;
}
struct Tree{
	ll c[MAXN*2];
	int lowbit(int n){return n&(-n);}
	inline void change(int pos)
	{
		while(pos<=n)
		{
			c[pos]++;
			pos+=lowbit(pos);
		}
	}
	inline ll query(int pos)
	{
		ll res=0;
		while(pos>0)
		{
			res+=(ll)c[pos];
			pos-=lowbit(pos);
		}
		return res;
	}
}T;
int main()
{
 	freopen("in.txt","r",stdin);
 	freopen("me.txt","w",stdout);
 	rd(n);
 	for(int i=1;i<=n;i++)  rd(a[0][i]);
 	for(int i=1;i<=n;i++)  rd(a[1][i]);
 	for(int i=1;i<=n;i++)  rd(b[0][i]);
 	for(int i=1;i<=n;i++)  rd(b[1][i]);
 	judge();
 	memset(f,0,sizeof(f));
 	for(int i=1;i<=n;i++)f[a[0][i]]=i;
	for(int i=1;i<=n;i++)b[0][i]=f[b[0][i]]+f[b[1][i]];
	long long ans=0;
	for(int i=n;i>=1;i--){
		ans+=(ll)T.query(b[0][i]);
		T.change(b[0][i]);
	}
	printf("%lld",ans);
}
//要记得注释掉open

