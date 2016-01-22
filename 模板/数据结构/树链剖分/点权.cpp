//#####################
//Author:fraud
//Blog: http://www.cnblogs.com/fraud/
//#####################
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;

//���ڵ�Ȩ����ѯ����ֵ���޸�·���ϵĵ�Ȩ��HDU 3966�����ʷ� + ��״���飩

const int MAXN = 50010;
struct edge{
    int to,Next;
}edge[MAXN<<1];
int head[MAXN],tot;
int top[MAXN];//top[v]��ʾv���ڵ������Ķ��˽ڵ�
int fa[MAXN];//���׽��
int deep[MAXN];//���
int num[MAXN];//num[v]��ʾ��vΪ��������Ľڵ���
int p[MAXN];//p[v]��ʾv��Ӧ��λ��
int fp[MAXN];//fp��p�����෴
int son[MAXN];//�ض���
int pos;
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 1;//ʹ����״���飬��Ŵ�ͷ1��ʼ
    memset(son,-1,sizeof(son));
}
void addedge(int u,int v){
    edge[tot].to = v;
    edge[tot].Next = head[u];
    head[u] = tot++;
}
void dfs1(int u,int f,int d){
    deep[u] = d;
    fa[u] = f;
    num[u] = 1;
    for(int i = head[u];i != -1; i = edge[i].Next){
        int v = edge[i].to;
        if(v == f)continue;
        dfs1(v,u,d+1);
        num[u] += num[v];
        if(son[u] == -1 || num[v] > num[son[u]])
            son[u] = v;
    }
}
void getpos(int u,int sp){
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if(son[u] == -1)return;
    getpos(son[u],sp);
    for(int i = head[u]; i != -1; i = edge[i].Next){
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v,v);
    }
}
//��״����
struct BIT{
    long long bit[MAXN];
    int sz;
    void init(int n){
        sz = n;
        for(int i = 0; i <= n; i++)bit[i] = 0;
    }
    long long sum(int i){
        long long ret = 0;
        while(i){
            ret += bit[i];
            i -= i & -i;
        }
        return ret;
    }
    void add(int i,long long x){
        while(i <= sz){
            bit[i] += x;
            i += i & -i;
        }
    }
}T;
//u->v ��·���ϵ��Ȩֵ�ı�val
void Change(int u,int v,int val){
    int f1 = top[u],f2 = top[v];
    while(f1 != f2){
        if(deep[f1] < deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        T.add(p[f1],val);
        T.add(p[u]+1,-val);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v])swap(u,v);
    T.add(p[u],val);
    T.add(p[v]+1,-val);
}
int a[MAXN];
int main(){
    int n,m,P;
    while(scanf("%d%d%d",&n,&m,&P)!=EOF){
        int u,v;
        int C1,C2,K;
        char op[10];
        init();
        for(int i = 1; i <= n; i++)scanf("%d",&a[i]);
        while(m--){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,0);
        getpos(1,1);
        T.init(n);
        for(int i = 1; i <= n; i++){
            T.add(p[i],a[i]);
            T.add(p[i]+1,-a[i]);
        }
        while(P--){
            scanf("%s",op);
            if(op[0]=='Q'){
                scanf("%d",&u);
                printf("%d\n",T.sum(p[u]));
            }else{
                scanf("%d%d%d",&C1,&C2,&K);
                if(op[0] == 'D') K = -K;
                Change(C1,C2,K);
            }
        }
    }
    return 0;
}
