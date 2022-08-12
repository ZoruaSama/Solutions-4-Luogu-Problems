#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct cube{
    int h,a,c;
}cubes[401];
bool vis[40001];
int f[401][40001];//到 j 高度需要多少个i类型的方块
//第 i 种方块只能在 ai 及以下的高度下使用，所以为了充分利用所有方块，需要以 ai 为关键字，从小到大排序。
bool cmp(cube &a,cube &b){
    return a.a<b.a;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>cubes[i].h>>cubes[i].a>>cubes[i].c;
    }
    sort(cubes+1,cubes+1+n,cmp);
    vis[0]=true;
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=cubes[i].h;j<=cubes[i].a;++j){
            if(vis[j-cubes[i].h] && f[i][j-cubes[i].h] < cubes[i].c && !vis[j]){
                f[i][j]=f[i][j-cubes[i].h]+1;
                vis[j]=vis[j-cubes[i].h];
                ans=max(ans,j);
            }
        }
    }
    cout<<ans;
    return 0;
}
