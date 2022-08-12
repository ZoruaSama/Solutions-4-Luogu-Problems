#include <iostream>
#include <stack>
using namespace std;
const int maxn=2e4+10;
const int maxm=1e5+10;
int n,m;
struct e{
    int to,next;
}E[maxm*2];
int head[maxn];
int tot;
int dfn[maxn];
int low[maxn];
bool vis[maxn];
bool cut[maxn];
int t;
stack<int> s;
void addEdge(int u,int v){
    E[++tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
void tarjan(int x,int fa){
    dfn[x]=low[x]=++t;
    vis[x]=true;
    s.push(x);
    int kid=0;
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(dfn[y]==0){
            tarjan(y,fa);
            low[x]=min(low[x],low[y]);
            if(dfn[x]<=low[y] && x!=fa) cut[x]=true;
            if(x==fa) kid++;
        }else if(vis[y]){
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(kid>1&&x==fa) cut[x]=true;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
        addEdge(y,x);
    }
    for(int i=1;i<=n;++i){
        if(dfn[i]==0){
            tarjan(i,i);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(cut[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;++i){
        if(cut[i]){
            cout<<i<<' ';
        }
    }
    return 0;
}
