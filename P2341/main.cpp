#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
const int maxn=1e4+5;
const int maxm=5e4+5;
struct e{
    int to,w,next;
}edge[maxm];
int n,m;
int head[maxn];
int tot;
int dfn[maxn];
int low[maxn];
bool vis[maxn];
int t;
int color[maxn];
int colornum[maxn];
int colorcnt;
int out[maxn];
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
void addEdge(int u,int v,int w){
    edge[++tot].w=w;
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}
stack<int> s;
void tarjan(int x){
    vis[x]=true;
    s.push(x);
    dfn[x]=low[x]=++t;
    for(int i=head[x];i;i=edge[i].next){
        int y=edge[i].to;
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
            colornum[colorcnt]++;
            s.pop();
        }
        vis[s.top()]=false;
        color[s.top()]=colorcnt;
        colornum[colorcnt]++;
        s.pop();
    }
}

int main() {
    n=read();
    m=read();
    for(int i=1;i<=m;++i){
        int a,b;
        a=read();
        b=read();
        addEdge(a,b,1);
    }
    for(int i=1;i<=n;++i){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
    for(int u=1;u<=n;++u){
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(color[u]!=color[v]){
                out[color[u]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=colorcnt;++i){
        if(out[i]==0){
            if(ans!=0){
                ans=-1;
                break;
            }
            ans=i;
        }
    }
    if(ans==-1){
        write(0);
    }else{
        write(colornum[ans]);
    }
    return 0;
}
