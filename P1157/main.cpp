#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<int> v;
int n,r;
void dfs(int x){
    if(v.size() == r){
        for(int i=0;i<v.size();i++){
            cout<<setw(3)<<v[i];
        }
        cout<<endl;
    }else{
        for(int i=x+1;i<=n;i++){
         v.push_back(i);
         dfs(i);
         v.pop_back();
        }
    }
}
int main() {
    cin>>n>>r;
    dfs(0);
    return 0;
}
