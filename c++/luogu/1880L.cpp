#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=105*2;
int n,minn=0x7fffffff,maxx;
int a[MAXN],f1[MAXN][MAXN],f2[MAXN][MAXN];
int s[MAXN];
int main()
{
 	freopen("in.txt","r",stdin);
 	scanf("%d",&n);
 	memset(f1,0x3f,sizeof(f1));
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d",&a[i]);
 		a[i+n]=a[i];
 	}
 	for(int i=1;i<=2*n;i++)
 	{
 		s[i]=s[i-1]+a[i];
 		f1[i][i]=0;
 	}
 	for(int len=2;len<=n;len++)
 	{
 		for(int i=1;i<=2*n;i++)
 		{//len=j-i+1
 			int j=len+i-1;
 			if(j>2*n) break;
 			for(int k=i;k<j;k++)
 			{
 				f1[i][j]=min(f1[i][j],f1[i][k]+f1[k+1][j]);
 				f2[i][j]=max(f2[i][j],f2[i][k]+f2[k+1][j]);
 			}
 			f1[i][j]+=s[j]-s[i-1];
 			f2[i][j]+=s[j]-s[i-1];
 		}
 	}
 	for(int i=1;i<=n;i++)
 	{
 		minn=min(minn,f1[i][n+i-1]);
 		maxx=max(maxx,f2[i][n+i-1]);
 	}
 	printf("%d\n%d",minn,maxx);
}
//Òª¼ÇµÃ×¢ÊÍµôopen

