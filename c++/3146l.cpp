#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=250;
int a[MAXN];
int f[MAXN][MAXN];
int n,maxx;
int main()
{
 	freopen("in.txt","r",stdin);
 	scanf("%d",&n);
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d",&a[i]);
 		f[i][i]=a[i];
 	}
 	for(int len=2;len<=n;len++)
 	{
 		for(int i=1;i<=n;i++)
 		{//len=j-i+1;
 			int j=len+i-1;
 			if(j>n) break;
 			for(int k=i;k<j;k++)
 			{
 				if(f[i][k]==f[k+1][j])
 					f[i][j]=max(f[i][j],f[i][k]+1);
 			}
 			maxx=max(maxx,f[i][j]); 
 		}
 	}
 	cout<<maxx;
}
//Òª¼ÇµÃ×¢ÊÍµôopen
