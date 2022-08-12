#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
int r[6001];
short mp[6001][6001]={0};
bool sub[6001]={false};
int f[6001][2]={0};

void dfs(int x){
    f[x][1]=r[x];
    for(int i=1;i<=mp[x][0];++i){
        dfs(mp[x][i]);
        f[x][1]+=f[mp[x][i]][0];
        f[x][0]+=max(f[mp[x][i]][0],f[mp[x][i]][1]);
    }
}
int main() {
    // f[u][1]表示 以u为根结点的子树并且包括u的总快乐指数
    // f[u][0]表示 以u为根结点的子树并且不包括u的总快乐指数
    // f[u][1] = sum(f[s][0])+r[u] s是u的子
    // f[u][0] = sum(max(f[s][0],f[s][1])
    // 从根到叶深搜 用叶到根返回时 做dp
//    cin>>n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
//        cin>>r[i];
        scanf("%d",r+i);
    }
    for(int i=1;i<=n-1;++i){
        short l,k;
        //cin>>l>>k;
        scanf("%hd%hd",&l,&k);
        mp[k][0]++;
        mp[k][mp[k][0]]=l;
        sub[l]=true;
    }
    for(int i=1;i<=n;++i){
        if(!sub[i]){
            dfs(i);
            //cout<<max(f[i][0],f[i][1]);
            printf("%d",max(f[i][0],f[i][1]));
            break;
        }
    }
    return 0;
}
