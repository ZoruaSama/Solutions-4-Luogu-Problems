#include <iostream>
#include <algorithm>
using namespace std;
int t,m;
int cost,value;
int f[1001]={0};
int main() {
    cin>>t>>m;
    for(int j=0;j<m;++j){
        cin>>cost>>value;
        for(int i=t;i>=0;--i){
            if(i>=cost){
                f[i] = max(f[i-cost]+value,f[i]);
            }
        }
    }
    cout<<f[t];
    return 0;
}
