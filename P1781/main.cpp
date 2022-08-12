#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    string maxn;
    string t;
    int res;
    cin>>maxn;
    for(int i=1;i<n;++i){
        cin>>t;
        if(t.length() > maxn.length()){
            maxn=t;
            res=i;
        }else if(t.length() == maxn.length() && t > maxn){
            maxn=t;
            res=i;
        }
    }
    cout<<res+1<<endl;
    cout<<maxn;
    return 0;
}
