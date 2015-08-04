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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define INF 0x3FFFFFFF
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
	int n,m,u,v,l;
	while(cin>>n>>m&&(n||m))
	{
		init();
		REP(i,m)
		{
			cin>>u>>v>>l;
			Map[u].PB(MP(v,l));
			Map[v].PB(MP(u,l));
		}
		dijkstra(1);
		cout<<dis[n]<<endl;
	}
		
		
	
	
	return 0;
}


