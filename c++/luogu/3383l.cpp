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
		x=(x<<3)+(x<<1)+(ch-'0') ;
		ch=getchar();
	}
	return;
}
int n,m,q;
int v[(int)1e8+5];
int prime[5428700];
inline void getpri()
{
	for(int i=2;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=i;
			prime[++m]=i;
		}
		for(int j=1;j<=m;j++)
		{
			int p=prime[j];
			if(p>v[i]||p*i>n) break;
			v[i*p]=p;
		}
	}
	return;
}
int main()
{
 	//freopen("in.txt","r",stdin);
 	int k;
 	rd(n);rd(q);
 	getpri();
 	for(int i=1;i<=q;i++)
 	{
 		rd(k);
 		printf("%d\n",prime[k]);
 	}
}
//Òª¼ÇµÃ×¢ÊÍµôopen
