
const int maxn;
int perm[maxn];
bool vis[maxn];
int num;//�û��ڸ���
 
int polya(int n)//n��ʾҪ���Ϊ0~n-1��һ���û�
{
	num=0;
	int j,p;
	CLR(vis,0);
	int ret=1;//�����û���С���� 
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			num++;
			for(j=0,p=i;!vis[p=perm[p]];j++)
			{
				vis[p]=1;
			}
			ret*=j/__gcd(ret,j);
		}
	}
	return ret;
}

