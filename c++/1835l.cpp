#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=1e6+10;
int prime[4800];
int v1[46341];
int m;//4792
int l,r,cnt;
int v[MAXN];
int pri[MAXN];
int x1,y1,x2,y2;
inline void getpri()
{
	for(int i=2;i<=46340;i++)
	{
		if(v1[i]==0)
		{
			prime[++m]=i;
			v1[i]=i;
		}
		for(int j=1;j<=m;j++)
		{
			int p=prime[j];
			if(p>v1[i]||p*i>46340) break;
			v1[p*i]=p;
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&l,&r);
	getpri();
	memset(v,0,sizeof(v));
	if(l==1) v[0]=1;//1���������� 
	for(int i=1;i<=m&&prime[i]*prime[i]<=r;i++)
	{//prime[i]�����sqrt(R)������ 
		long long p=prime[i];
		long long start=max((l+p-1)/p*p,2*p);
		//start�Ǵ����������ܱ�p�����ĵ�һ����
		// (l+p-1)����������ȡ������������ 
		for(long long j=start;j<=r;j+=p)
		{
			v[j-l]=1;//j�Ƚϴ�������v[j-l]��ʾj�Ƿ񱻱�� 
		}
	}
	cnt=0;
	for(long long i=l;i<=r;i++)//�Է���int 
	{
		if(v[i-l]==0)
		{
			cnt++;//���������� 
		}
	}
	printf("%d",cnt);
}
//Ҫ�ǵ�ע�͵�open
