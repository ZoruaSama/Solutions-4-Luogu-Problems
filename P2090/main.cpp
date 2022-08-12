#include <iostream>
#include <queue>
using namespace std;
int n;
int res;
void dfs(int a,int b,int times){
    if(times>res){
        return ;
    }
    if(a<1||b<1){
        return ;
    }
    if(a==1 && b==1){
        res=min(times,res);
        return ;
    }else{
        if(a>b){
            dfs(a-b,b,times+1);
        }else{
            dfs(a,b-a,times+1);
        }
    }
}
int main() {
    cin>>n;
    res=n-1;
    for(int i=1;i<n;++i) dfs(n,i,0);
    cout<<res;
    return 0;
}
