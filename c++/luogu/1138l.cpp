#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10001];
int c[30001];
int k,n,cnt=0;
int main()
{
 	freopen("in.txt","r",stdin);
 	int x;
 	scanf("%d%d",&n,&k);
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d",&x);
 		if(!c[x]) a[++cnt]=x,c[x]=1;
 	}
 	if(k>cnt) 
	{
 		puts("NO RESULT");
		return 0;	
 	}
 	sort(a+1,a+1+cnt);
 	printf("%d",a[k]);
}
//Òª¼ÇµÃ×¢ÊÍµôopen

