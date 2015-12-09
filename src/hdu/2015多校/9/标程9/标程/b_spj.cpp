#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>

using namespace std;
#define rep(i, a, n) for (int i=a;i<n;i++)
#define per(i, a, n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x, y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) cout<<"Case #"<<++__<<": "<<x<<endl
#define POP(x) (__builtin_popcount(x))
#define POPL(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf = 0x20202020;
const ll mod = 1000000007;
const double eps = 1e-9;
const double pi = 3.1415926535897932384626;
const int DX[] = {1, 0, -1, 0}, DY[] = {0, 1, 0, -1};

ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

ll powmod(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head

ll p, q, r, base, pw[10100];
char a[101000], b[101000];
int n, m;

ll mul(ll a, ll b, ll mod = r) {
    ll c = a * b - mod * ll((LD) a * b / mod);
    while (c < 0) c += mod;
    while (c >= mod) c -= mod;
    return c;
}

void check(int x, string info) {
    if (x == 0) {
        printf("wa");
        exit(0);
    }
}

void success() {
    puts("AC!");
}

ll hv(char *s, int l) {
    ll ans = 0;
    rep(i, 0, l) if (s[i] == '(') ans = (ans + mul(p, pw[i])) % r; else ans = (ans + mul(q, pw[i])) % r;
    return ans;
}

int main(int argc, char **argv) {
    FILE *fin = fopen(argv[1], "r"), *fout = stdin;
    while (fscanf(fin, "%lld%lld%lld%lld", &p, &q, &r, &base) != EOF) {
        pw[0] = 1;
        p %= r;
        q %= r;
        base %= r;
        fscanf(fout, "%s%s", a, b);
        n = strlen(a);
        m = strlen(b);
        check(n == m, "长度不同");
        check(n <= 10000, "长度过长");
        bool sm = 1;
        rep(i, 0, n) sm &= a[i] == b[i];
        check(!sm, "a==b");
        rep(i, 1, n + 1) pw[i] = mul(pw[i - 1], base);
        check(hv(a, n) == hv(b, n), "hash不同");
    }
    success();
}