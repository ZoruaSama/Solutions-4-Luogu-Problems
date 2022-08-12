#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int x[31]; //集合列表
int m;
int ans=0;

void dfs(int mi,int mm,int sum,int selfi){
    if(mm==sum){
        ans++;
        return ;
    }
    if(mm>sum){
        return ;
    }
    for(int i=mi+1;i<selfi;++i){
        dfs(i,mm+x[i],sum,selfi);
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        ans=0;
        cin>>m; //集合元素个数
        for(int i=0;i<m;i++){
            cin>>x[i];
        }
        sort(x,x+m);
        for(int i=0;i<m;i++){ //枚举每个元素
            dfs(-1,0,x[i],i);
        }
        cout<<ans<<endl;
    }

    return 0;
}
