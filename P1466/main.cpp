#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e3;
int n;
//bool vis[maxn];
long long f[maxn];
//int dfs(int x,int a){
//    if(x==0){
//        return 1;
//    }
//    int res=0;
//    for(int i=a;i<=n;++i){
//        if(!vis[i]){
//            vis[i]=true;
//            res+=dfs(x-i,i+1);
//            vis[i]=false;
//        }
//    }
//    return res;
//}
int main() {
    scanf("%d",&n);
    if((n*(n+1)/2) %2){
        printf("0");
        return 0;
    }
    int m=n*(n+1)/4;
    f[0]=1;
    for(int i=1;i<=n;++i){
        for(int j=m;j>=i;--j){
            f[j]+=f[j-i];
        }
    }
    printf("%lld",f[m]/2);
//    printf("%d",dfs(n*(n+1)/4,1)/2);
    return 0;
}
