#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n,dist;
    cin>>n>>dist;
    int p[100001];
    for(int i=1;i<=n;++i){
        cin>>p[i];
    }
    sort(p+1,p+1+n);
    int cnt=0;
    for(int i=2;i<=n-1;++i){
        if(p[i+1]-p[i-1]<=dist){
            cnt++;
            p[i]=p[i-1];
        }
    }
    cout<<cnt;
    return 0;
}
