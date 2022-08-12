#include <iostream>
using namespace std;
const int maxn=1e5+10;
const int maxm=2e5+10;
int n,m;
struct e{
    int to,next;
}E[maxm];
int head[maxn];
int tot;
int in[maxn];
int out[maxn];
int f[maxn];
void addEdge(int u,int v){
    E[++tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
int dfs(int x){
    if(f[x]){
        return f[x];
    }
    if(out[x]==0){
        return f[x]=1;
    }else{
        int res=0;
        for(int i=head[x];i;i=E[i].next){
            res+=dfs(E[i].to);
        }
        return f[x]=res;
    }
}
int main() {
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>a>>b;
        addEdge(a,b);
        out[a]++;
        in[b]++;
    }
    int res=0;
    for(int i=1;i<=n;++i){
        if(!in[i] && out[i]){
            res+=dfs(i);
        }
    }
    cout<<res;
    return 0;
}
