
#define MAXN 200

VI Map[MAXN];

struct Edge{
	int u, v;
	int c, f;
	Edge* rev;
	Edge(){};
	Edge(int _u, int _v, int _c, int _f, Edge* r):u(_u),v(_v),c(_c),f(_f),rev(r){}
}edge[MAXN*2];

int n_edge;

void addEdge(int u, int v, int c, int f)
{
	Map[u].PB(n_edge);
	Map[v].PB(n_edge+1);
	Edge l(u,v,c,f,&edge[n_edge+1]);
	Edge r(v,u,0,-f,&edge[n_edge]);
	edge[n_edge] = l;
	edge[n_edge+1] = r;
	n_edge += 2;
}

//EK�㷨 �� Ford-Fulkerson �� BFS ʵ��
//���ڽӱ��Ż�
//��ͼ��ʾҪ��:
//ÿ���� <u,v> ��Ҫ�������� flow[u][v] = f ������ cap[u][v] = c 
//ͬʱ��Ҫ�������� cap[v][u] = 0 ���� flow[v][u] = -f
//Map[u].PB(v) �� Map[v].PB(u) 
int Edmonds_Karp(int s, int t)
{
	bool end = false;
	while(!end)
	{
		end = true;
		queue<int> q;
		q.push(s);
		int sgn[MAXN] = {0}; //�ɸĽ����Ĵ�С 
		sgn[s] = INF;
		Edge* fa[MAXN];  //��һ�λ� 
		fa[s] = NULL;
		while(!q.empty())
		{
			int u = q.front();
			for(VI::iterator it = Map[u].begin(); it != Map[u].end(); it++)
			{
				Edge &l = edge[*it];
				int v = l.v;
				if(!sgn[v])
				{
					sgn[v] = min(sgn[u], l.c-l.f);
					if(sgn[v])
					{
						fa[v] = &l;
						q.push(v);
						if(v == t)
						{
							Edge* r;
							while((r = fa[v])!=NULL)
							{
								r->f += sgn[t];
								r->rev->f -= sgn[t];
								v = r->u;
							}
							end = false;
							break; 
						}
					}
				}
			}
			if(!end) break;
			q.pop();
		}
	}
	int sumf = 0;
	for(VI::iterator it = Map[s].begin(); it != Map[s].end(); it++)
	{
		int fl = edge[*it].f;
		sumf += fl>0?fl:0;
	}
	return sumf;
}

int main()
{
	int n,m;
	int u,v,c;
	while(cin>>n>>m)
	{
		for(int i = 0; i < MAXN; i++)
			Map[i].clear();
		n_edge=0;
		for(int i = 0; i < n; i++)
		{
			cin>>u>>v>>c; u--; v--;
			if(c>0)
				addEdge(u,v,c,0);
		}
		cout<<Edmonds_Karp(0,m-1)<<endl;
	}
	return 0;
}
