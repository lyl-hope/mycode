#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=1<<18;
int w[18+5],b[MAXN];
int f[MAXN],W,n;
int s[MAXN];
int main()
{
 	freopen("in.txt","r",stdin);
 	memset(f,0x3f,sizeof(f));
 	f[0]=0;
 	scanf("%d%d",&n,&W);
 	for(int i=0;i<n;i++)
 	{
 		scanf("%d",&w[i]);
 	}
 	for(int i=0;i<n;i++)//����ÿλ�±� 
 	{
 		b[1<<i]=i;
 	}
 	for(int i=1;i<(1<<n);i++)//(1<<n)-1 ��ʾ��n��1 
 	{
 		s[i]=w[b[ i & (-i) ]] + s[i ^ (i & (-i))];
 	}
 	for(int i=1;i<(1<<n);i++)
 	{
 		for(int j=i;j !=0;j=(j-1)&i)
 		{
 			if(s[j]<=W)
 				f[i]=min(f[i],f[i^j]+1);
 		}
 	}
 	printf("%d",f[(1<<n)-1]);
}
//Ҫ�ǵ�ע�͵�open
/*
ע��f[0]=0
s[0]=0->i��1��ʼ
*/ 
