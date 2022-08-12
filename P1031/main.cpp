#include <iostream>
using namespace std;
int n;
int p[101];
int avrg=0;
int ans=0;
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>p[i];
        avrg+=p[i];
    }
    avrg/=n;
    for(int i=1;i<n;++i){
        int d = p[i]-avrg;
        if(d!=0){
            p[i+1]+=d;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
