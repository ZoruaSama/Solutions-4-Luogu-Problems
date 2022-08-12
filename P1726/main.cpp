#include <iostream>
#include <stack>
using namespace std;
const int maxn=5e3+10;
const int maxm=5e4+10;
int n,m;
struct e{
    int to,next;
}E[maxm];
int head[maxn];
int tot;
int t;
int dfn[maxn],low[maxn],vis[maxn];
int colorcnt;
int color[maxn];
int colors[maxn];
stack<int> s;
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
        while(s.top()!=x){
            vis[s.top()]=false;
            color[s.top()]=colorcnt;
            s.pop();
            colors[colorcnt]++;
        }
        vis[s.top()]=false;
        color[s.top()]=colorcnt;
        s.pop();
        colors[colorcnt]++;
    }
}
void addLine(int u,int v){
    E[++tot].to = v;
    E[tot].next=head[u];
    head[u] = tot;
}

int main() {
    cin>>n>>m;
    int a,b,t;
    for(int i=1;i<=m;++i){
        cin>>a>>b>>t;
        if(t==1){
            addLine(a,b);
        }else{
            addLine(a,b);
            addLine(b,a);
        }
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    int maxi=0;
    int maxc=0;
    for(int i=1;i<=n;++i){
        if(colors[i]>maxc){
            maxi=i;
            maxc=colors[i];
        }
    }
    cout<<maxc<<endl;
    for(int i=1;i<=n;++i){
        if(color[i]==maxi){
            cout<<i<<' ';
        }
    }
    return 0;
}
