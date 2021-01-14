#include <iostream>
#include <cstdio>
#include <cstring>
//#pragma comment(linker, "/STACK:1073741824")
using namespace std;
#define ll long long
template <class T> inline void rd(T &x)
{
	x=0;
	int flag=1;
	char ch;
	while(ch=getchar())
	{
		if(ch=='-') flag=-1;
		if(ch>='0'&&ch<='9') break;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x=x*flag;
}
const int MAXN=1e5+5;
struct aa{
	int next,to;
}node[MAXN*2];
int head[MAXN],cnt;
int n,m;
inline void add(int from,int to)
{
	node[++cnt].to=to;
	node[cnt].next=head[from];
	head[from]=cnt;
}
int a[MAXN],k;
ll sans;
//-----------------
struct bb{
	int dep;
	#define dep(x) msg[x].dep
	int fa;
	int wson;
	#define wson(u) (msg[u].wson)
	int size;
	int top;
	#define top(u) msg[u].top
}msg[MAXN];
int dfn[MAXN],org[MAXN];
void dfs1(int u,int fa)
{
	msg[u].fa=fa;
	msg[u].size=1;
	for(int i=head[u];i;i=node[i].next)
	{
		int v=node[i].to;
		if(v==fa) continue;
		dep(v)=dep(u)+1;
		dfs1(v,u);
		msg[u].size+=msg[v].size;
		if(msg[wson(u)].size<msg[v].size)
			wson(u)=v;
	}
}
void dfs2(int u,int fa)
{
	if(wson(u))
	{
		//printf("%d\n",wson(u));
		dfn[wson(u)]=++cnt;
		org[cnt]=wson(u);
		top(wson(u))=top(u);//this is top[u
		dfs2(wson(u),u);
	}
	for(int i=head[u];i;i=node[i].next)
	{
		int v=node[i].to;
		
		if(!top(v))
		{//printf("%d\n",v);
			top(v)=v;
			dfn[v]=++cnt;
			org[cnt]=v;
			dfs2(v,u);
		}
	}
}
//-------------------
struct tree{
	ll l,r;
	ll sum;
	ll lz;
	//#define l(x) t[x].l
	//#define r(x) t[x].r
}t[MAXN*4];
#define lson id<<1
#define rson id<<1|1
inline void updata(int id)
{
	t[id].sum=t[lson].sum+t[rson].sum;
}
inline void down(const int &id,const ll &mid)
{
	if(t[id].lz==0) return;
	ll lazy=t[id].lz;
	t[lson].lz+=lazy;
	t[rson].lz+=lazy;
	t[id].lz=0;
	t[lson].sum+=lazy*(mid-t[id].l+1);//mid-l+1....不是l-mid 
	t[rson].sum+=lazy*(t[id].r-mid);
}
void build(int id,int l,int r)
{
	t[id].l=l;
	t[id].r=r;
	if(l==r)
	{
		t[id].sum=a[org[l]];
		return;
	}
	ll mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	updata(id);
}
void modify1(int id,const int &x)
{
	if(x<t[id].l||x>t[id].r) return;
	if(t[id].l==t[id].r)
	{
		t[id].sum+=k;
		return;
	}
	ll mid=t[id].l+t[id].r>>1;
	down(id,mid);
	modify1(lson,x);
	modify1(rson,x);
	updata(id);
}
void modify2(int id,const int &x,const int &y)
{// x l r y
	if(y<t[id].l||t[id].r<x) return;
	if(x<=t[id].l&&t[id].r<=y)
	{
		t[id].lz+=k;
		t[id].sum+=(t[id].r-t[id].l+1)*k;
		return;
	}
	ll mid=(t[id].l+t[id].r)>>1;
	down(id,mid);
	modify2(lson,x,y);
	modify2(rson,x,y);
	updata(id);
}
void query(int id,const int &x,const int &y)
{
	if(y<t[id].l||t[id].r<x) return;
	if(x<=t[id].l&&t[id].r<=y)
	{
		sans+=t[id].sum;
		return;
	}
	int mid=(t[id].l+t[id].r)>>1;
	down(id,mid);
	query(lson,x,y);
	query(rson,x,y);
}
inline ll ask(int x,int y)
{
	int fx=top(x);
	int fy=top(y);
	while(fx!=fy)
	{
		if(dep(fx)<dep(fy))
		{
			swap(fx,fy);
			swap(x,y);
		}
		query(1,dfn[fx],dfn[x]);
		x=msg[fx].fa;//是fx的父亲  呜呜呜... 
		fx=top(x);
	}
	if(dep(x)>dep(y))
	{
		swap(x,y);
	}
	query(1,dfn[x],dfn[y]);
}
int main()
{
	freopen("6.in","r",stdin);
	freopen("out.txt","w",stdout);
	int x,y,opt;
	rd(n),rd(m);
	for(int i=1;i<=n;i++)
	{
		rd(a[i]);
	}
	for(int i=1;i<n;i++)
	{
		rd(x),rd(y);
		add(x,y);
		add(y,x);
	}
	cnt=1;
	msg[1].dep=org[1]=dfn[1]=msg[1].top=1;
	dfs1(1,0);
	dfs2(1,0);
	build(1,1,cnt);
	/*for(int i=1;i<=n;i++)
	{
		printf("%d\n",wson(i));
	}*/
	while(m--)
	{
		rd(opt);
		if(opt==1)
		{
			rd(x),rd(k);
			modify1(1,dfn[x]);
		}
		else if(opt==2)
		{
			rd(x),rd(k);
			modify2(1, dfn[x] , dfn[x]+msg[x].size-1);
		}
		else
		{
			rd(x);
			sans=0;
			ask(1,x);
			printf("%lld\n",sans);
		}
	}
}

