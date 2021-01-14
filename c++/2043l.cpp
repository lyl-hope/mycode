#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=10000+5;
int n,m,p1;
int v[MAXN];
int prime[MAXN];
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
}
int main()
{
 	freopen("in.txt","r",stdin);
 	scanf("%d",&n);
 	getpri();
 	for(int i=1;i<=m;i++)
 	{
 		int p=prime[i];
 		int c=0;
 		p1=p;
 		while(p1<=n)
 		{
 			c+=n/p1;
 			p1*=p;
 		}
 		printf("%d %d\n",p,c);
 	}
}
//Òª¼ÇµÃ×¢ÊÍµôopen

