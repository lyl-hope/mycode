#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
const int MAXN=5e5+5;
struct aa{
	int val,num;
}a[MAXN];
inline bool cmp(aa x,aa y)
{//考虑相同元素情况，序号大的要先进，否则会统计到序号小的 
	return x.val==y.val? x.num>y.num:x.val>y.val;
}
int n;
ll ans;
//--------------

int c[MAXN];
int lowbit(int n){return n&(-n);}
inline void change(int pos)
{
	while(pos<=n)
	{
		c[pos]++;
		pos+=lowbit(pos);
	}
}
inline int query(int pos)
{
	int res=0;
	while(pos>0)
	{
		res+=c[pos];
		pos-=lowbit(pos);
	}
	return res;
}
int main()
{
 	//freopen("in.txt","r",stdin);
 	scanf("%d",&n);
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d",&a[i].val);
 		a[i].num=i;
 	}
 	sort(a+1,a+1+n,cmp);
 	for(int i=1;i<=n;i++)
 	{
 		change(a[i].num);
 		ans+=query(a[i].num-1);
 	}
 	printf("%lld",ans);
}
//要记得注释掉open

