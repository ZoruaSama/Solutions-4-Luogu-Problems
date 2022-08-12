#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int x[101];
int cost(int i,int k){
    if(i!=k){
        return abs(x[i]-x[k])*(k-i+1);
    }else{
        return x[i];
    }

}
int f[101][101]={0};
int dfs(int a,int b){
    int maxn=cost(a,b);
    if(f[a][b]!=-1){
        return f[a][b];
    }
    for(int k=a;k<b;++k){
        maxn = max(maxn,dfs(a,k)+dfs(k+1,b));
    }
    return f[a][b]=maxn;
}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) {
            f[i][j]=-1;
        }
    }
    for(int i=1;i<=n;++i){
        cin>>x[i];
        f[i][i]=x[i];
    }
    cout<<dfs(1,n);
    return 0;
}
