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
int main()
{
	ios::sync_with_stdio(false);
	int t;
	double PI=acos(-1.0);
	cin>>t;
	while(t--){
        double r,h,d;
        cin>>r>>h>>d;
        double s1=PI*(r+d)*(r+d)*h+2.0*PI*r*r*d;
        double s2=2.0/3.0*PI*d*d*d+PI*r*d*d*PI/2.0;
        //cout<<s2<<endl;
        double ans1=s1+2.0*s2;
        s1=2*PI*(r+d)*h+2.0*PI*r*r;
        s2=2*PI*d*(d+r*PI/2.0);
        double ans2=s1+2.0*s2;
        cout<<fixed<<setprecision(12)<<ans1<<" "<<fixed<<setprecision(12)<<ans2<<endl;
	}
	return 0;
}


