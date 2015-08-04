//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
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
ll a[100010];
int dpl[100010];
int dpr[100010];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
        a[0] = -INF;
        a[n+1] = -INF;
        for(int i=0;i<=n+1;i++)dpl[i] = dpr[i] = i;
        for(int i=1;i<=n;i++){
            while(a[dpl[i]-1]>=a[i])dpl[i]=dpl[dpl[i]-1];
        }
        for(int i=n;i>=1;i--){
            while(a[dpr[i]+1]>=a[i])dpr[i]=dpr[dpr[i]+1];
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans,a[i]*(ll)(dpr[i]-dpl[i]+1));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
