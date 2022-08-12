#include <iostream>
#include <stack>
#include <vector>

using namespace std;
const int maxn=3e3+10;
const int maxp=2e4+10;
const int maxr=8e3+10;
int n,p,r;
int g[maxp],g_[maxp];
struct e{
    int to,next;
}E[maxr];
int tot;
int head[maxn];
int t;
int dfn[maxn],low[maxn],vis[maxn];
int colorcnt;
int color[maxn];
int minid[maxn];
stack<int> s;
int in[maxn];

void addLine(int u,int v){
    E[++tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
void tarjan(int x){
    dfn[x]=low[x]=++t;
    vis[x]=1;
    s.push(x);
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }else if(vis[y]){
            low[x]=min(low[x],low[y]);
        }
    }
    if(dfn[x]==low[x]){
        ++colorcnt;
        minid[colorcnt]=2e9;
        g_[colorcnt]=2e9;
        while(s.top()!=x){
            vis[s.top()]=false;
            color[s.top()]=colorcnt;
            g_[colorcnt]=min(g_[colorcnt],g[s.top()]);
            minid[colorcnt]=min(minid[colorcnt],s.top());
            s.pop();
        }
        vis[s.top()]=false;
        color[s.top()]=colorcnt;
        minid[colorcnt]=min(minid[colorcnt],s.top());
        g_[colorcnt]=min(g_[colorcnt],g[s.top()]);
        s.pop();
    }
}
int main() {
    cin>>n>>p;
    int a,b;
    for(int i=1;i<=n;++i){
        g[i]=2e9;
    }
    for(int i=1;i<=p;++i){
        cin>>a>>b;
        g[a]=b;
    }
    cin>>r;
    for(int i=1;i<=r;++i){
        cin>>a>>b;
        addLine(a,b);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int u=1;u<=n;++u){
        for(int i=head[u];i;i=E[i].next){
            int v=E[i].to;
            if(color[u]!=color[v]){
                in[color[v]]++;
            }
        }
    }
    int id=2e9;
    int res=0;
    bool f=false;
    for(int i=1;i<=colorcnt;++i){
        if(!in[i]){
            if(g_[i]!=2e9){
                res+=g_[i];
            }else{
                f=true;
                id=min(id,minid[i]);
            }
        }
    }
    if(!f){
        cout<<"YES"<<endl;
        cout<<res;
    }else{
        cout<<"NO"<<endl;
        cout<<id;
    }
    return 0;
}
