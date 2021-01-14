#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=3e6+5;
int inv[MAXN],p,n;
int main()
{
 	//freopen("in.txt","r",stdin);
 	scanf("%d%d",&n,&p);
 	inv[1]=1;
 	printf("1\n");
 	for(int i=2;i<=n;i++)
 	{
 		inv[i]=(long long)(p-p/i)*inv[p%i]%p;
		printf("%d\n",inv[i]);
 	}
 	
}
//Òª¼ÇµÃ×¢ÊÍµôopen

