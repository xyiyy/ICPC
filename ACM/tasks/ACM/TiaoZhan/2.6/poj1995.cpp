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
ll MOD;
ll fast_mod(ll n,ll m)
{
	ll ans=1;
	ll temp=m;
	while(n)
	{
		if(n&1)ans=(ans*temp)%MOD;
		temp=(temp*temp)%MOD;
		n>>=1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>MOD;
		cin>>n;
		ll p,m;
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>p>>m;
			ans=(ans+fast_mod(m,p))%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}


