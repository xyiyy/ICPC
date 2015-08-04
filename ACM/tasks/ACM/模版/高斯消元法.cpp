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

const int num = 100;
double matrix[num][num + 1];   //ϵ�����󣬴�0��ʼ
double ans[num];               //�������
void exchange_col(int p1,int p2,int n)  //����p1�к�p2�е���������
{
	double t; int i;
    for(i=0;i<=n;i++)
    {
          t=matrix[p1][i];
		  matrix[p1][i]=matrix[p2][i];
		  matrix[p2][i]=t;
	}
}
bool gauss(int n)   //���ϵ������Ϊn�����Է�����
{
	int i,j,k;int p;double r;
    for(i=0;i<n-1;i++)
	{
		p=i;
        for(j=i+1;j<n;j++) 
		{   //Ѱ��i�����ֵλ��
        	if(fabs(matrix[j][i]) > fabs(matrix[p][i]))
				p=j;
		}
        if(fabs(matrix[p][i])<1e-7) 
			return false;
        if(p!=i)     
			exchange_col(i,p,n);
        for(j=i+1;j<n;j++) 
		{       //ʣ���н�����Ԫ
        	r=matrix[j][i]/matrix[i][i];
            for(k=i;k<=n;k++)
				matrix[j][k]-=r*matrix[i][k];
		}
	}
    for(i=n-1;i>=0;i--) 
	{   //��ý��
    	ans[i]=matrix[i][n];
        for(j=n-1;j>i;j--)
			ans[i]-=matrix[i][j]*ans[j];
		ans[i]/=matrix[i][i];
	}
    return true;
}// ���ϵ������Ϊn�����Է����飬�������޽ⷵ��false������true

int main()
{
	ios::sync_with_stdio(false);

	return 0;
}


