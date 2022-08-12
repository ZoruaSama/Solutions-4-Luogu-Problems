#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,m;
const int maxn=1e6+1;
const int maxe=2e6+1;
struct e{
    int v,w,next;
}edge[maxe];
int tot;
int head[maxn];
bool vis[maxn];
int f[maxn];
int ans[maxn];
const int mod = 100003;
void addEdge(int u,int v){
    tot++;
    edge[tot].v=v;
    edge[tot].next=head[u];
    head[u] = tot;
}

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
int main() {
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        f[i]=2e9;
    }
    for(int i=1;i<=m;++i){
        int x,y;
        x=read();
        y=read();
        addEdge(x,y);
        addEdge(y,x);
    }
    queue<int> q;
    q.push(1);
    vis[1]=true;
    f[1]=0;
    ans[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        vis[u] = false;
        for(int i=head[u];i;i=edge[i].next){
            int v = edge[i].v;
            if(f[v] > f[u]+1){
                f[v]=f[u]+1;
                ans[v]=ans[u];
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }else if(f[v]==f[u]+1){
                ans[v]+=ans[u];
                ans[v]%=mod;
            }
        }
    }
    for(int i=1;i<=n;++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}
