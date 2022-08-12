#include <iostream>
using namespace std;
int main() {
    int m,n,c;
    int f[1001]={1};
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>c;
          for(int j=m;j>=c;--j){
                f[j] += f[j-c];
        }
    }
    cout<<f[m];
    return 0;
}
