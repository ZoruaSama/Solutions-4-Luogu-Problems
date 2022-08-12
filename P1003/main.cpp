#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int x[100005],y[100005],a[100005],b[100005];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>a[i]>>b[i];
    }
    int nx,ny;
    cin>>nx>>ny;
    for(int i=n;i>=1;--i){
        if(nx>=x[i] && ny>=y[i] && nx<=x[i]+a[i] && ny<=y[i]+b[i]){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
