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
ll dp[510][510];
ll a[510];

int main() {
    ios::sync_with_stdio(false);
    int n, m, b, MOD;
    cin >> n >> m >> b >> MOD;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= b; k++) {
                if (k >= a[i])
                    dp[j][k] += dp[j - 1][k - a[i]];
                dp[j][k] %= MOD;
            }
        }

    }
    ll ans = 0;
    for (int i = 0; i <= b; i++) {
        ans += dp[m][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}



