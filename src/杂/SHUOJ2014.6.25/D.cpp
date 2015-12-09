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
#define MOD 19901014
#define N 10000005
using namespace std;
bool flag[N] = {0};
ll prime[N], cnt = 0;

void Prime() {
    for (int i = 2; i < N; i++) {
        if (flag[i]) continue;
        prime[cnt++] = i;
        for (int j = 2; j * i < N; j++)
            flag[i * j] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int m;
    ll a;
    bool mark;
    Prime();
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a;
        mark = 0;
        for (ll j = 0; j < cnt && prime[j] * prime[j] <= a; j++) {
            if (a % (prime[j] * prime[j]) == 0) {
                mark = 1;
            }
        }
        cout << "Case " << i << ": ";
        if (mark) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}


