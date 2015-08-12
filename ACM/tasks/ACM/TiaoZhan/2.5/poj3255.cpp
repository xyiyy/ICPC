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
#define MAXN 5010
vector<PII> Map[MAXN];

//����ڽӱ� 
void init() { REP(i,MAXN) Map[i].clear(); }

//����sΪԴ������· ���������dis�� 
int dis[MAXN];
int dis1[MAXN];
void dijkstra(int s)
{
	REP(i,MAXN){dis[i]=i==s?0:INF;}
	REP(i,MAXN){dis1[i]=INF;}
	int vis[MAXN] = {0};
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(MP(0,s));
	while(!q.empty())
	{
		PII p = q.top(); q.pop();
		int x = p.second;
		int d1=p.first;
		if(dis1[x]<d1)continue;
		for(vector<PII>::iterator it = Map[x].begin(); it != Map[x].end(); it++)
		{
			int y = it->first;
			int d = it->second+d1;
			if( dis[y] > d)
			{
				swap(dis[y],d);
				q.push(MP(dis[y],y));
			}
			if(dis1[y]>d&&dis[y]<d)
			{
				dis1[y]=d;
				q.push(MP(dis1[y],y));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n,r;
	while(cin>>n>>r)
	{
		init();
		int u,v,l;
		for(int i=0;i<r;i++)
		{
			cin>>u>>v>>l;
			u--;v--;
			Map[u].PB(MP(v,l));
			Map[v].PB(MP(u,l));
		}
		dijkstra(0);
		cout<<dis1[n-1]<<endl;
	}
	return 0;
}


