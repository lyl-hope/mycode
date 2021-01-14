#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int gcd(int a,int b)
{
	return b==0? a:gcd(b,a%b);
}
int n,x,ans;
int main()
{
 	freopen("in.txt","r",stdin);
 	scanf("%d",&n);
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%d",&x);
 		ans=gcd(ans,x<0 ? -x : x);
 	}
 	printf("%d",ans);
}
//Òª¼ÇµÃ×¢ÊÍµôopen

