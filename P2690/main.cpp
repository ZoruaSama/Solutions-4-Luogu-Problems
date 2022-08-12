#include <iostream>
using namespace std;
const int maxn=1e3+10;
int t,w;
int a[maxn];
int f[3][maxn][31]; //t时刻在0/1棵树下
int dfs(int x,int t_,int w_){
    if(f[x][t_][w_]!=0){
        return f[x][t_][w_];
    }
    if(t_>t || w_<0){
        return 0;
    }
    int f1 = dfs(3-x,t_+1,w_-1);
    int f2 = dfs(x,t_+1,w_);
    if(x==a[t_]){
       return f[x][t_][w_] = 1+max(f1,f2);
    }else{
       return f[x][t_][w_] = 0+max(f1,f2);
    }

}
int main() {
    cin>>t>>w;
    for(int i=1;i<=t;++i){
        cin>>a[i];
    }
    cout<<dfs(1,0,w);
    return 0;
}
