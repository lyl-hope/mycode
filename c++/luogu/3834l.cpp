#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector> 
using namespace std;
template <class T>inline void rd(T &x) 
{
	x=0;
	char ch;
	int sign=1;
	while(ch=getchar())
	{
		if(ch=='-') sign=-1;
		if(ch>='0'&&ch<='9') break;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	x=x*sign;
	return;
}
const int MAXN=2e5+5; 
vector <int>v;
inline int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int a[MAXN];
int n,m,x,y,k,n1;
struct hjt{
	int lc,rc,w;
}tree[MAXN*40];
int cnt,root[MAXN];
//----------
void ins(int l,int r,int pre,int &now,const int &x)
{
	tree[++cnt]=tree[pre];
	now=cnt;
	tree[now].w++;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(x<=mid)//要插左边，左边变，左边要新开点 
	{
		ins(l,mid,tree[pre].lc,tree[now].lc,x);
	}
	else
	{
		ins(mid+1,r,tree[pre].rc,tree[now].rc,x);
	}
}
int query(int l,int r,int L,int R,int k)
{
	if(l==r) return l;
	int mid =(l+r)>>1;
	int temp=tree[tree[R].lc].w-tree[tree[L].lc].w;//新减出来的树->左子树上有几个点 
	if(k<=temp)//注意 
	{
		return query(l,mid,tree[L].lc,tree[R].lc,k);
	}
	else
	{
		return query(mid+1,r,tree[L].rc,tree[R].rc,k-temp);//这里是k-temp 
	}
}
int main()
{
 	freopen("in.txt","r",stdin);
 	//scanf("%d%d",&n,&m);
 	rd(n),rd(m);
 	for(int i=1;i<=n;i++)
 	{
 		//scanf("%d",&a[i]);
 		rd(a[i]);
 		v.push_back(a[i]);
 	}
 	sort(v.begin(),v.end());
 	v.erase(unique(v.begin(),v.end()),v.end());
 	//离散化
	n1=v.size();
	for(int i=1;i<=n;i++)
	{
		ins(1,n1,root[i-1],root[i],getid(a[i]));
	}
	while(m--)
	{
		//scanf("%d%d%d",&x,&y,&k);
		rd(x),rd(y),rd(k);
		printf("%d\n",v[query(1,n1,root[x-1],root[y],k)-1]);
	}
}
//要记得注释掉open

