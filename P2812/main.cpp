#include <iostream>
#include <stack>
using namespace std;
const int maxn=10010;
int n;
struct e{
    int to,next;
}E[maxn*maxn];
int head[maxn];
int tot;
int dfn[maxn];
int low[maxn];
int t;
int vis[maxn];
int colorcnt;
int color[maxn];
int in[maxn];
int out[maxn];
stack<int> s;
void addEdge(int u,int v){
    E[++tot].to=v;
    E[tot].next=head[u];
    head[u]=tot;
}
void tarjan(int x){
    vis[x]=true;
    s.push(x);
    dfn[x]=low[x]=++t;
    for(int i=head[x];i;i=E[i].next){
        int y=E[i].to;
        if(dfn[y]==0){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }else if(vis[y]){
            low[x]=min(low[x],low[y]);
        }
    }
    if(dfn[x]==low[x]){
        colorcnt++;
        while(s.top()!=x){
            vis[s.top()]=false;
            color[s.top()]=colorcnt;
            s.pop();
        }
        vis[s.top()]=false;
        color[s.top()]=colorcnt;
        s.pop();
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        int c=0;
        do{
            cin>>c;
            if(c!=0){
                addEdge(i,c);
            }
        }while(c!=0);
    }
    //A任务就是tarjan缩点后的点数量
    //B任务就是强联通
    for(int i=1;i<=n;++i){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=head[i];j;j=E[j].next){
            int v=E[j].to;
            if(color[i]!=color[v]){
                //cout<<color[i]<<"->"<<color[v]<<endl;
                out[color[i]]++;
                in[color[v]]++;
            }
        }
    }
    int ans=0,ans_=0;
    for(int i=1;i<=colorcnt;++i){
        if(in[i]==0){
            ans++;
        }
        if(out[i]==0){
            ans_++;
        }
    }
    cout<<ans<<endl;
    if(colorcnt==1){
        cout<<0;
    }else{
        cout<<max(ans,ans_);
    }
    return 0;
}