#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
//ǰ�沿���Ժ����Ϊģ��ʹ�� 
const int MAX_N=2000;

char a[MAX_N],b[MAX_N];
int aa[MAX_N],bb[MAX_N],cc[MAX_N];



int main()
{
	ios::sync_with_stdio(false);
	int N,k=1;
	cin>>N;
	while(N--)
	{
		
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		memset(cc,0,sizeof(cc));
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));//��ʼ������ 
		cin>>a>>b;
		cout<<"Case "<<k++<<":"<<endl;
		cout<<a<<" + "<<b<<" = ";
		int len1=strlen(a),len2=strlen(b);
		//for(int i=0;i>0;i++
		int len=max(len1,len2);
		for(int i=len;i>0;i--)//i>0����ΪҪ������ǰ��һλ��λ 
		{
			if(len1>0)
			aa[i]=a[--len1]-'0';
			else aa[i]=0;
			if(len2>0)
			bb[i]=b[--len2]-'0';
			else bb[i]=0;
			//bb[] 
		}
		int temp=0;
		for(int i=len;i>=0;i--)
		{
			cc[i]=(aa[i]+bb[i]+temp)%10;
			temp=(aa[i]+bb[i]+temp)/10;
		}
		int j=0;
		for(j=0;cc[j]==0;j++)
		{
			;
		}
		for(int i=j;i<len;i++)
		{
			cout<<cc[i];
		}
		cout<<cc[len]<<endl;
		if(N>0)
		cout<<endl;
	}
	return 0;
}

