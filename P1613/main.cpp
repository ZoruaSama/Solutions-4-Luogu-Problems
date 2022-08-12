#include <iostream>
#include <cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=50+10;
const int maxm=1e4+10;
int n,m;
bool f[maxn][maxn][74];
int dis[maxn][maxn];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dis[i][j]=1e9;
        }
    }
    for(int i=1;i<=n;++i){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        f[u][v][0]=true;
        dis[u][v]=1;
    }
    for(int k=1;k<=64;++k){
        for(int l=1;l<=n;++l){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    if(f[i][l][k-1] && f[l][j][k-1]){
                        f[i][j][k]=true;
                        dis[i][j]=1;
                    }
                }
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    cout<<dis[1][n];
    return 0;
}