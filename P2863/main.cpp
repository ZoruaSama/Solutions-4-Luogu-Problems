#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n,m;
const int maxn=1e4+1;
vector<int> nodes[maxn];
stack<int> s;
bool vis[maxn];
int dfn[maxn];
int low[maxn];
int t=1;
int ans;
void dfs(int x){
    s.push(x);
    vis[x]=true;
    dfn[x]=low[x]=t++;
    int size=nodes[x].size();
    for(int i=0;i<size;++i){
        int y=nodes[x][i];
        if(dfn[y]==0){
            dfs(y);
            low[x]=min(low[x],low[y]);
        }else if(vis[y]){
            low[x]=min(low[x],low[y]);
        }
    }
    int cnt=0;
    if(dfn[x]==low[x]){
        while(s.top()!=x){
            cnt++;
            vis[s.top()]=false;
            s.pop();
        }
        cnt++;
        vis[s.top()]=false;
        s.pop();
        if(cnt>1){
            ans++;
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        nodes[a].push_back(b);
    }
    for(int i=1;i<=n;++i){
        if(dfn[i]==0){
            dfs(i);
        }
    }
    cout<<ans;
    return 0;
}
