#include <iostream>
using namespace std;
int n,s;
const int maxn=1e5+10;
int a[maxn];
struct e{
    int to,next;
}E[maxn<<1];
int tot;
int head[maxn];
void addEdge(int u,int v){
    ++tot;
    E[tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
void dfs(int x,int fa,int s_){

}
int main() {
    cin>>n>>s;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;++i){
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
        addEdge(y,x);
    }
    return 0;
}
