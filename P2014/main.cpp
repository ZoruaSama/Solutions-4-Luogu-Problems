#include <iostream>
#include <vector>
using namespace std;
vector<int> k[302];
int s[302]={0};
int f[302][302]={0};
int n,m;
// f[i][j] 表示 从i门课起后修j门课
// f[0][M] 表示 最终答案
int dfs(int x){
    for(int i=1;i<=m;++i){
        f[x][i]=s[x];
    }
    for(int i=0;i<k[x].size();++i){
        dfs(k[x][i]);
        for(int j=m;j>=1;--j){
            for(int l=0;l<=j-1;++l){
                f[x][j]=max(f[x][j],f[x][j-l]+f[k[x][i]][l]);
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a>>s[i];
        k[a].push_back(i);
    }
    m=m+1;
    dfs(0);
    cout<<f[0][m];
    return 0;
}
/*
for(int i=1;i<=m;++i){ //先对当前这个节点进行处理 只要容量大于当前课的消耗 就可选
        f[x][i]=s[x];   //边界条件
    }
    for(int i=0;i<k[x].size();++i){ //物品
        dfs(k[x][i]); //遍历这个节点的子节点
        for(int j=m;j>=1;j--){ //体积    01背包的特性
            for(int l=0;l<=j-1;++l){ //决策   给这个儿子l个空间分配 最多分配j-1 因为父节点需要
               f[x][j]=max(f[x][j],f[x][j-l]+f[k[x][i]][l]);
            }
        }
    }
 */