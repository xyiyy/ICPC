//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
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

#define MAXN 100010
ll a[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	ll n;
	while(cin>>n){
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		ll tx=0;
		ll ty=0,s=0;
		for(ll i=0,j=n-1;i<n;i++,j--){
			tx+=i*a[i];
			ty+=j*a[i];
			s+=a[i];
		}
		s+=(tx-ty)*2LL;
		ll tmp=__gcd(s,n);
		cout<<s/tmp<<" "<<n/tmp<<endl;
	}
			
	return 0;
}



