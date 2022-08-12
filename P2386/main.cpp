#include <iostream>
using namespace std;
void dfs(int k,int left,int last,int &res){
    if(left < last){
        return ;
    }
    if(k==0) {
        res++;
        return ;
    }
    for(int i=last;i<=left;++i){
        dfs(k-1,left-i,i,res);
    }

}
int main() {
    int t,m,n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        int res=0;
        dfs(n-1,m,0,res);
        cout<<res<<endl;
    }

    return 0;
}
