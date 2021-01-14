#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
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
const int MAXM=200005;
int n,m;
struct Block{
	int len,k;
	int a[MAXN];
	int f[MAXN];
	inline void build()
	{
		len=sqrt(n);
		k=n/len;
		if(n%len!=0) k++;
		for(int i=1;i<=n;i++)
		{
			rd(a[i]);
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=(i-1)*len+1;j<=i*len;j++)
			{
				f[j]=i;
			}
		}
	}
}B;

struct Query{
	int l,r;
	int num;
}q[MAXM];
inline bool cmp(Query x,Query y)
{
	return (B.f[x.l] ^ B.f[y.l]) ? B.f[x.l]<B.f[y.l] : (B.f[x.l] & 1) ? x.r < y.r : x.r > y.r;
}
int c[MAXN],ans[MAXM];
int res;
struct MoDui{
	inline void add(int pos)
	{
		if(c[B.a[pos]]==0) res++;
		c[B.a[pos]]++;
	}
	inline void del(int pos)
	{
		c[B.a[pos]]--;
		if(c[B.a[pos]]==0) res--;
	}
	inline void solve()
	{
		int l=1,r=0;
		for(int i=1;i<=m;i++)
		{
			int ql=q[i].l;
			int qr=q[i].r;
			while(l<ql)//l往右,删去之前记录 
			{
				del(l),l++;
			}
			while(l>ql)
			{
				l--,add(l);
			}
			while(r<qr)
			{
				r++,add(r);
			}
			while(r>qr)
			{
				del(r),r--;
			}
			ans[q[i].num]=res;
		}
	}
}S;

int main()
{
 	freopen("in.txt","r",stdin);
 	rd(n);
 	B.build();
 	rd(m);
 	for(int i=1;i<=m;i++)
 	{
 		rd(q[i].l),rd(q[i].r);
 		q[i].num=i;
 	}
 	sort(q+1,q+1+m,cmp);
 	S.solve();
 	for(int i=1;i<=m;i++)
 	{
 		printf("%d\n",ans[i]);
 	}
}
//要记得注释掉open

