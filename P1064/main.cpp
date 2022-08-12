#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 32e3+10;
const int maxm = 3e2+10;
int n,m;
struct item{
    int v,p,q;
    int f1;
    int f2;
}Q[maxn];
int f[maxm][maxn];
int ff[maxn];
int tot;
int v[maxm],w[maxm],g[maxm];
//树形DP [后面几个点会TLE]
//Record:  https://www.luogu.com.cn/record/46529702

//int dfs(int x){
//    for(int i=v[x];i<=n;i+=10){
//        f[x][i]=v[x]*p[x];
//    }
//    for(int i=head[x];i;i=E[i].next){
//        int y=E[i].to;
//        dfs(y);
//        for(int j=n;j>=1;--j){
//            for(int l=v[x];l<j;l+=10){
//                f[x][j]=max(f[x][j],f[x][l]+f[y][j-l]);
//            }
//        }
//    }
//}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&Q[i].v,&Q[i].p,&Q[i].q);
        if(Q[i].q){
           if(!Q[Q[i].q].f1){
               Q[Q[i].q].f1=i;
           }else if(!Q[Q[i].q].f2){
               Q[Q[i].q].f2=i;
           }
        }
    }
    int grp=0;
    for(int i=1;i<=m;++i){
        if(!Q[i].q){
            ++grp;
            ++tot;
            v[tot]=0;
            w[tot]=0;
            g[tot]=grp;

            ++tot;
            v[tot]=Q[i].p * Q[i].v;
            w[tot]=Q[i].v;
            g[tot]=grp;

            ++tot;
            v[tot]=Q[i].p * Q[i].v + Q[Q[i].f1].p * Q[Q[i].f1].v;
            w[tot]=Q[i].v + Q[Q[i].f1].v;
            g[tot]=grp;

            ++tot;
            v[tot]=Q[i].p * Q[i].v + Q[Q[i].f2].p * Q[Q[i].f2].v;
            w[tot]=Q[i].v + Q[Q[i].f2].v;
            g[tot]=grp;

            ++tot;
            v[tot]=Q[i].p * Q[i].v + Q[Q[i].f1].p * Q[Q[i].f1].v + Q[Q[i].f2].p * Q[Q[i].f2].v;
            w[tot]=Q[i].v + Q[Q[i].f1].v + Q[Q[i].f2].v;
            g[tot]=grp;
        }
    }
    for(int i=1;i<=tot;++i){
        for(int j=n;j>=w[i];j-=10){
            f[g[i]][j]=max(f[g[i]][j],v[i]);
        }
    }
    for(int i=1;i<=m;++i){
        for(int j=n;j>=0;j-=10){
            for(int k=0;k<=j;k+=10){
                ff[j]=max(ff[j],ff[j-k]+f[i][k]);
            }
        }
    }
    printf("%d",ff[n]);
    return 0;
}
