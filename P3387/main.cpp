#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
const int maxn=10001;
int n,m;
int t=1;
int value[maxn];
bool vis[maxn];
int dfn[maxn];
int low[maxn];
int color[maxn];
int colorcnt=1;
vector<int> nodes[maxn];
vector<int> nnodes[maxn];
int nvalue[maxn];
int in[maxn];
stack<int> s;
queue<int> q;
int f[maxn];
int ans;
void tarjan(int x){
    vis[x]=true;
    s.push(x);
    dfn[x]=low[x]=t++;
    int size = nodes[x].size();
    for(int i=0;i<size;++i){
        int y = nodes[x][i];
        if(dfn[y]==0){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }else if(vis[y]){
            low[x]=min(low[x],low[y]);
        }
    }
    if(dfn[x]==low[x]){
        while(s.top()!=x){
            vis[s.top()]=false;
            color[s.top()] = colorcnt;
            s.pop();
        }
        vis[s.top()]=false;
        color[s.top()] = colorcnt;
        s.pop();
        colorcnt++;
    }

}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>value[i];
    }
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        nodes[u].push_back(v);
    }
    for(int i=1;i<=n;++i){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<nodes[i].size();++j){
            int y = nodes[i][j];
            // addEdge color[i] color[y]
            if(color[i]!=color[y]){
                nnodes[color[i]].push_back(color[y]);
                in[color[y]]++;
            }
        }
        nvalue[color[i]]+=value[i];
    }
    for(int i=1;i<colorcnt;++i){
        if(in[i]==0){
            q.push(i);
            f[i]=nvalue[i];
        }
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<nnodes[now].size();++i){
            int v=nnodes[now][i];
            in[v]--;
            f[v]=max(f[v],f[now]+nvalue[v]);
            if(in[v]==0){
                q.push(v);
            }
        }
    }
    for(int i=1;i<colorcnt;++i){
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}
