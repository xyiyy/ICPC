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
