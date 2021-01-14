#include<bits/stdc++.h>
using namespace std;
char s[1000];
char s1[1000];
char s2[1000];
int cnt,pos,len;
bool f;
void solve_n()
{//0?
	bool f=0;
	for(int i=len;i>=1;i--)
	{
		if(f==1)
		{
			printf("%c",s[i]);
			continue;
		}
		if(s[i]!='0')
		{
			printf("%c",s[i]);
			f=1;
		}
	}
	if(f==0) cout<<0;
	exit(0);
}
void solve_d()//0/1?
{
	bool f=0;
	for(int i=pos-1;i>=1;i--)
	{
		if(f==1)
		{
			printf("%c",s[i]);
			continue;
		}
		if(s[i]!='0')
		{
			printf("%c",s[i]);
			f=1;
		}
	}
	if(f==0) cout<<0;
	f=0;
	cout<<"/";
	for(int i=len;i>pos;i--)
	{
		if(f==1)
		{
			printf("%c",s[i]);
			continue;
		}
		if(s[i]!='0')
		{
			printf("%c",s[i]);
			f=1;
		}
	}
	exit(0);
}
void solve_p()
{//0.0?1.0?0.1
	bool f1=0;
	for(int i=pos-1;i>=1;i--)
	{
		if(f1==1)
		{
			printf("%c",s[i]);
			continue;
		}
		if(s[i]!='0')
		{
			printf("%c",s[i]);
			f1=1;
		}
	}
	if(f1==0) cout<<0;
	cout<<".";
	f1=0;
	bool f2=0;
	int pos1=pos+1;
	for(int i=pos+1;i<=len;i++)
	{
		if(s[i]=='0')
		{
			pos1++;
		}
		else
		{
			break;
		}
	}
	for(int i=len;i>=pos1;i--)
	{
		printf("%c",s[i]);
		f1=1;
	}
	if(f1==0) cout<<0;
	exit(0);
}
void solve_b()
{//0%
	bool f=0;
	for(int i=len-1;i>=1;i--)
	{
		if(f==1)
		{
			printf("%c",s[i]);
			continue;
		}
		if(s[i]!='0')
		{
			printf("%c",s[i]);
			f=1;
		}
	}
	if(f==0) cout<<0;
	cout<<"%";
	exit(0);
}
int main(){
	freopen("in.txt", "r", stdin);
	//freopen(".out", "w", stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=len;i>=1;i--)
	{
		if(s[i]=='/')
		pos=i,solve_d();
		else if(s[i]=='.')
		pos=i,solve_p();
		else if(s[i]=='%')
		pos=i,solve_b();
	}
	solve_n();
	return 0;
}
