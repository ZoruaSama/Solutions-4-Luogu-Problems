#include <iostream>
using namespace std;
int cnt=0;
//把 i 分成 x 份
// f[7][3]=f[6][2]+f[4][3]
//         ①有1的 ②没有1的
//f[i][x]=f[i-1][x-1]+f[i-x][x]
void dfs(int n,int k,int last){
    if(last>n){
        return ;
    }
    if(k==1){
        cnt++;
        return ;
    }else{
        for(int i=last;i<n;i++){
            dfs(n-i,k-1,i);
        }
    }
}
int main() {
    int n,k;
    cin>>n>>k;
    dfs(n,k,1);
    cout<<cnt;
    return 0;
}
