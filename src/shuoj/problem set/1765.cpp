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
//#include <strstream>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define IT iterator
#define CLR(A,X) memset(A,X,sizeof(A))
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
char a[10010]="1-2-1 1-2-1 1 1 1-2-1";
char b[10010]="1 2 3 4 1-2-3 4";
int main()
{
    ios::sync_with_stdio(false);
    int T;
    int m,n;
    int cas=1;
    int t=0;
    cin>>T;
    while(T--)
    {
        cout<<"Case "<<cas++<<":"<<endl;
        cin>>n>>m;
        if(m==1)t=1;
        else t=0;
        for(int i=1;i<=n;i++)
        {
            if(t==0)
            {  
                cout<<b<<endl;
                t=1;
            }
            else
            {
                cout<<a<<endl;
                t=0;
            }
             
        }
    }
         
    return 0;
}
