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

//*****************by fraud
//���ȫ����С��
//ÿ�δ�0�㿪ʼ������һ������������������Ĳ�����
//Ψһ����������������������ѡ����ĸ���ӽ�����ʱ��
//���Ǹ����������ıߵĳ��ȣ����Ǹ��������������бߵĳ��Ⱥ͡�
//Ȼ���¼������������ĵ�ϲ������㣩�������������ĸ���������Сֵ��
//Ȼ�󲻶��ظ��˲����������������㡢��Сֵ����ֱ�����е㶼��Ϊ1�㡣 
//*************************
const int MAX_V=510;
int vis[MAX_V];
int wet[MAX_V];
int combine[MAX_V];
int Map[MAX_V][MAX_V];
int S, T, minCut;
void Search(int n){
     int i, j, Max, tmp;
     CLR(vis,0);
     CLR(wet,0);
     S = T = -1;
     for (i = 0; i < n; i++){
         Max = -INF;
         for (j = 0; j < n; j++){
             if (!combine[j] && !vis[j] && wet[j] > Max){
                tmp = j;
                Max = wet[j];
             }
         }
         if (T == tmp) return;
         S = T; T = tmp;
         minCut = Max;
         vis[tmp] = 1;
         for (j = 0; j < n; j++){
             if (!combine[j] && !vis[j]){
                wet[j] += Map[tmp][j];
             }
         }
     }
}
int Stoer_Wagner(int n){
    int i, j;
    CLR(combine,0);
    int ans = INF;
    for (i = 0; i < n - 1; i++){
        Search(n);
        if (minCut < ans) ans = minCut;
        if (ans == 0) return 0;
        combine[T] = 1;
        for (j = 0; j < n; j++){
            if (!combine[j]){
               Map[S][j] += Map[T][j];
               Map[j][S] += Map[j][T];
            }
        }
    }
    return ans;
}
int main()
{
//	ios::sync_with_stdio(false);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int u,v,c;
		CLR(Map,0);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			Map[u][v]+=c;
			Map[v][u]+=c;
		}
	//	printf("ok\n");
		printf("%d\n",Stoer_Wagner(n));
	}
	return 0;
}



