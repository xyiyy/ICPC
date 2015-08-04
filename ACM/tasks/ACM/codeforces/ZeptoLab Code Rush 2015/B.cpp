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
int a[100010];
int b[100010];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int tot=(1<<(n+1))-2;
	for(int i=0;i<tot;i++){
		cin>>a[2+i];
		b[2+i]=a[2+i];
	}
	int t=tot+1;
	for(int i=t;i;i--){
		a[i]=max(a[i<<1],a[i<<1|1])+a[i];
	}
	int x=a[1];
	int ans=0;
	for(int i=2;i<=t;i++){
		ans+=a[i>>1]-a[i]-b[i>>1];
	}
	cout<<ans<<endl;
	
	return 0;
}



