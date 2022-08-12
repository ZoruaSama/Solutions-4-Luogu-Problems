#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
#include <cstdio>
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
struct edge{
    int v;
    int w;
    bool operator< (const edge &x) const{
        return w>x.w;
    }
};
bool vis[2501]={false};
int dis[2501]={0};
vector<edge> nodes[2501];
priority_queue<edge> q;
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        dis[i]=2e9;
    }
    dis[1]=0;
    for(int i=1;i<=m;++i){
        int a,b,c;
        a=read();b=read();c=read();
        nodes[a].push_back(edge{b,c});
    }
    q.push(edge{1,0});
    while(!q.empty()){
        int now=q.top().v;q.pop();
        if(vis[now]) continue;
        vis[now]=true;
        for(int i=0;i<nodes[now].size();++i){
            int nv = nodes[now][i].v;
            int nw = nodes[now][i].w;
            if(dis[now] + nw < dis[nv]){
                dis[nv] = dis[now] + nw;
                q.push(edge{nv,dis[nv]});
            }
        }
    }

    cout<<dis[n];
    return 0;
}
