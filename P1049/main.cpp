#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int v,n,d,s[20001]={0};
    cin>>v>>n;
    for(int i=0;i<n;++i){
        cin>>d;
        for(int j=v;j>=d;--j){
            s[j]=max(s[j],s[j-d]+d);
        }
    }
    cout<<v-s[v];
    return 0;
}
