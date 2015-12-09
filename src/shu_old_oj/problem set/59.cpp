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
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
/***********************************
	Dijkstra ��Դ���·
	�ڽӱ� + ���ȶ��� �Ż� 
	2014.3.1
***********************************/

#define MAXN 1000
vector<PII> Map[MAXN];

//����ڽӱ� 
void init() { REP(i,MAXN) Map[i].clear(); }

//����sΪԴ������· ���������dis�� 
int dis[MAXN];
void dijkstra(int s)
{
	REP(i,MAXN){dis[i]=i==s?0:INF;}
	int vis[MAXN] = {0};
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(MP(0,s));
	while(!q.empty())
	{
		PII p = q.top(); q.pop();
		int x = p.second;
		if(vis[x])continue;
		vis[x] = 1;
		for(vector<PII>::iterator it = Map[x].begin(); it != Map[x].end(); it++)
		{
			int y = it->first;
			int d = it->second;
			if(!vis[y] && dis[y] > dis[x] + d)
			{
				dis[y] = dis[x] + d;
				q.push(MP(dis[y],y));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	int v,s,t,cas=1;
	while(cin>>n)
	{
		cout<<"Case "<<cas++<<endl;
		init();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>v;
				if(v<0)v=INF;
				Map[i].PB(MP(j,v));
			}
		}
		cin>>s>>t;
		dijkstra(s-1);
		cout<<dis[t-1]<<endl;
	}
	return 0;
}


