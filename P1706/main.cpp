#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int a[10]={0};
void dfs(int n,vector<int> &ans,int level){
    if(ans.size()==n){
        for(int i=0;i<ans.size();++i){
            cout<<setw(5)<<ans[i];
        }
        cout<<endl;
        return;
    }else{
        for(int i=1;i<=n;++i){
            if(a[i]!=-1){
                ans.push_back(i);
                a[i]=-1;
                dfs(n,ans,level+1);
                ans.pop_back();
                a[i]=0;
            }
        }
    }
}
int main() {
    int n;
    vector<int> ans;
    cin>>n;
    dfs(n,ans,0);
    return 0;
}
