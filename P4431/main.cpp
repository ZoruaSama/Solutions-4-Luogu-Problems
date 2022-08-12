#include <iostream>
using namespace std;
int k,n,m;
int main() {
    cin>>k;
    while(k--){
        cin>>n>>m;
        cout<<min(n,m)*2-2<<endl;
    }
    return 0;
}
