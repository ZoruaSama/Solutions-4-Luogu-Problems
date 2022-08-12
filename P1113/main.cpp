#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;
const int maxn=10010;
int n;
struct edge{
    int u;
    int v;
};
vector<int> nodes[maxn];
vector<edge> edges;
int cost[maxn];
int f[maxn]={0}; //f[i]表示完成前i个杂务所需要的最短时间(具有不减性)
int in[maxn]={0}; //节点的入度

inline int read()
{
    char c=(char)getchar();
    int x=0,fs=1;
    while(!isdigit(c)){if(c=='-')fs=-1;c=(char)getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=(char)getchar(); //NOLINT
    return x*fs;
}

void write(int a)
{
    if(a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar(a%10+48);
}
bool cmp(edge a,edge b){
    // 先按终点排序 再按起点排序
    return a.v < b.v || (a.v==b.v&&a.u<b.u);
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        int u,v;
        v=read();
        cost[i]=read();
        while(true){
            u=read();
            if(u==0){
                break;
            }
            edges.push_back(edge{u,v});
            in[v]++;
        }
    }
    sort(edges.begin(),edges.end(),cmp);
    for(int i=0;i<edges.size();++i){
        nodes[edges[i].u].push_back(i); //存储边的边号
        //cout<<edges[i].u<<' '<<i<<'='<<edges[i].v<<endl;
    }
    queue<int> q;
    for(int i=1;i<=n;++i){
        if(in[i]==0){
            //cout<<i<<endl;
            q.push(i);
            f[i]=cost[i]; //对于这个题而言只有1没有前驱节点
        }
    }
    int ans=f[1];
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<nodes[now].size();++i){
            //edges[nodes[now][i]].v //边对应的下一个点
            int nnode=edges[nodes[now][i]].v;
            f[nnode]=max(f[nnode],f[now]+cost[nnode]);
            //递推公式 当前点的所需时间等于前面所有指向该点的前驱结点的时间+当前结点的花费时间
            in[nnode]--;
            if(in[nnode]==0){
                q.push(nnode);
            }
        }
        ans=max(ans,f[now]);
    }
    cout<<ans;
    return 0;
}
