#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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
const int MAXN=200200;
const int MAXM=100000+5;
struct aa{
	int to,next;
}node[MAXN];
int head[MAXN],cnt;
inline void add(int from,int to)
{
	node[++cnt].to=to;
	node[cnt].next=head[from];
	head[from]=cnt;
}
int a[MAXN];
vector <int> v;
int n,m;
//-------------------------------
int dep[MAXN],f[MAXN][25],dfn[MAXN],ncnt,first[MAXN],last[MAXN];
void dfs(int u,int fa)
{
	dfn[++ncnt]=u;
	f[u][0]=fa;
	first[u]=ncnt;
	for(int i=head[u];i;i=node[i].next)
	{
		int v=node[i].to;
		if(v==fa) continue;//printf("%d %d\n",u,v);
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
	dfn[++ncnt]=u;
	last[u]=ncnt;
	return;
}
inline int Lca(int u,int v)
{
	if(dep[u]>dep[v]) swap(u,v);
	for(int i=21;i>=0;i--)
	{
		if(dep[f[v][i]]>=dep[u])
		{
			v=f[v][i];
		}
	}
	if(u==v) return v;
	for(int i=21;i>=0;i--)
	{
		if(f[u][i]!=f[v][i])
		{
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}

//------------------------------
int bf[MAXN];
int len,k;
void build()
{
	len=sqrt(ncnt);
	k=ncnt/len;
	if(ncnt%len!=0) k++;
	for(int i=1;i<=k;i++)
	{
		for(int j=(i-1)*len+1;j<=i*len;j++)
		{
			bf[j]=i;
		}
	}
}
//------------------------------
struct Q{
	int num;
	int l,r,lca;
}q[MAXM];
inline bool cmp(const Q &a,const Q &b)
{
	return (bf[a.l] ^ bf[b.l]) ? (bf[a.l] < bf[b.l]) : ((bf[a.l] & 1) ? a.r < b.r : a.r > b.r);
	//return (bf[x.l] ^bf[y.l]) ? bf[x.l] < bf[y.l] :( (bf[x.l] & 1 ) ? x.r < y.r : x.r > y.r); 
}
//-------------------
bool vis[MAXN];
int ccnt[MAXN],now;
inline void del(int val)
{
	ccnt[a[val]]--;
	if(ccnt[a[val]]==0) now--;
}
inline void addc(int val)
{
	if(ccnt[a[val]]==0) now++;
	ccnt[a[val]]++;
}
inline void updata(int val)
{
	if(vis[val])
	{
		del(val);
		//now -= !--ccnt[a[val]];
	}
	else
	{
		addc(val);
		//now += !ccnt[a[val]]++;
	}
	vis[val]^=1;
}

int ans[MAXM];
int main()
{
	freopen("data6.in","r",stdin);
	freopen("out.txt","w",stdout);
	int x,y;
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
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	for(int i=1;i<n;i++)
	{
		//scanf("%d%d",&x,&y);
		rd(x),rd(y);
		add(x,y);
		add(y,x);
	}
	dep[1]=1;
	dfs(1,0);
	for(int j=1;j<=21;j++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	build();
	for(int i=1;i<=m;i++)
	{
		//scanf("%d%d",&x,&y);
		rd(x),rd(y);
		if(first[x]>first[y]) swap(x,y);
		int lca=Lca(x,y);
		q[i].num=i;
		if(x==lca)
		{
			q[i].l=first[x];
			q[i].r=first[y];
		}
		else
		{
			q[i].l=last[x];
			q[i].r=first[y];
			q[i].lca=lca;
		}
	}
	cout<<1;
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		int ql=q[i].l,qr=q[i].r,lca=q[i].lca;
		while(l<ql)
		{
			updata(dfn[l++]);
		}
		while(l>ql)
		{
			updata(dfn[--l]);
		}
		while(r<qr)
		{
			updata(dfn[++r]);
		}
		while(r>qr)
		{
			updata(dfn[r--]);
		}
		if(lca!=0) updata(lca);//¼Ó 
		ans[q[i].num]=now;
		if(lca!=0) updata(lca);//É¾ 
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d\n",ans[i]) ;
	}
 	return 0;
}
