#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn=1e3+10;
const int maxm=1e3+10;
int n,m;
int E[maxn][maxn];
int in[maxn];
int stop[maxn];
int lv[maxn];
void addEdge(int u,int v){
    if(E[u][v]!=1){
        E[u][v]=1;
        in[v]++;
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int s;
        int list[maxn];
        scanf("%d",&s);
        for(int j=1;j<=n;++j){
            stop[j]=false;
        }
        for(int j=1;j<=s;++j){
            scanf("%d",&list[j]);
            stop[list[j]]=true;
        }
        for(int j=list[1];j<=list[s];++j){
            if(!stop[j]){
                for(int k=1;k<=s;++k){
                    addEdge(j,list[k]);
                }
            }
        }
    }

    queue<int> q;
    for(int i=1;i<=n;++i){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v=1;v<=n;++v){
            if(E[u][v]==1){
                in[v]--;
                lv[v]=max(lv[v],lv[u]+1);
                if(in[v]==0){
                    q.push(v);
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans, lv[i]);
    }
    printf("%d",ans+1);
    return 0;
}
