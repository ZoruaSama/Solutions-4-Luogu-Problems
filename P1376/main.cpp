#include <iostream>
using namespace std;
int n,s;
int main() {
    cin>>n>>s;
    int lw;
    long long ans=0;
    for(int i=1;i<=n;++i){
        int c,y;
        cin>>c>>y;
        if(i==1){
            lw=c;
        }else{
            lw=min(lw+s,c);
        }
        ans+=lw*y;
    }
    cout<<ans;
    return 0;
}
