//gaoshenbaoyou  ------ pass system test
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
#define MP(X, Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X, N) for(int X=0;X<N;X++)
#define REP2(X, L, R) for(int X=L;X<=R;X++)
#define DEP(X, R, L) for(int X=R;X>=L;X--)
#define CLR(A, X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int pig[1010];

//######################
//Dinic
//by fraud
//////////////////////
struct edge {
    int to, cap, rev;

    edge(int _to, int _cap, int _rev) {
        to = _to, cap = _cap, rev = _rev;
    }
};

const int MAX_V = 110;
vector<edge> G[MAX_V];
int level[MAX_V];
//���
int iter[MAX_V];//��ǰ��������֮ǰ�ı��Ѿ�û������

void add_edge(int from, int to, int cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));
}

void bfs(int s)//���
{
    CLR(level, -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t)return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    for (; ;) {
        bfs(s);
        if (level[t] < 0)return flow;
        CLR(iter, 0);
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int vis[1010];
bool cus[110];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> m >> n) {
        for (int i = 0; i < n + 3; i++)G[i].clear();
        for (int i = 1; i <= m; i++) {
            cin >> pig[i];
        }
        int s = n, t = s + 1;
        CLR(vis, 0);
        int num = 0, index;
        for (int i = 0; i < n; i++) {
            num = 0;
            int k;
            cin >> k;
            CLR(cus, 0);
            for (int j = 0; j < k; j++) {
                cin >> index;
                if (!vis[index]) {
                    num += pig[index];
                    vis[index] = i + 1;
                    //	vis[index]=1;
                }
                else {
                    if (!cus[vis[index] - 1]) {
                        add_edge(vis[index] - 1, i, INF);
                        cus[vis[index] - 1] = 1;
                    }
                }
            }
            add_edge(s, i, num);
            cin >> num;
            add_edge(i, t, num);
        }
        cout << max_flow(s, t) << endl;
    }

    return 0;
}



