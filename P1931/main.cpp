#include <iostream>
#include <queue>
#include <map>
#include <cstdio>
using namespace std;

const int maxn=31;
int n,m,k;
double dis[maxn];
int vis[maxn];
int cnt[maxn];
struct e{
    int to,next;
    double w;
}E[maxn*maxn];
int head[maxn];
int tot;
int num;
void addEdge(int u,int v,double w){
    ++tot;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].next=head[u];
    head[u]=tot;
}
bool spfa(int x){
    queue<int> q;
    for(int i=1;i<=n;++i){
        dis[i]=0;
        vis[i]=0;
        cnt[i]=0;
    }
    dis[x]=1;
    vis[x]=1;
    cnt[x]++;
    q.push(x);
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            double w=E[i].w;
            if(dis[v]<dis[u]*w){
                dis[v]=dis[u]*w;
                if(!vis[v]){
                    cnt[v]++;
                    vis[v]=1;
                    q.push(v);
                    if(cnt[v]==n+1) return true;
                }
            }
        }
    }
    return false;
}
int main() {
    while(true){
        map<string,int> mp;
        cin>>n;
        if(n==0) break;
        for(int i=1;i<=n;++i){
            string s;
            cin>>s;
            mp[s]=++num;
        }
        cin>>m;
        for(int i=1;i<=m;++i){
            string s1,s2;
            double w;
            cin>>s1>>w>>s2;
            addEdge(mp[s1],mp[s2],w);
        }
        printf("Case %d: ",++k);
        printf("%s\n",spfa(1) ? "Yes":"No");
        tot=0;
        num=0;
        for(int i=1;i<=n;++i){
            head[i]=0;
        }
    }
    return 0;
}
