#include <iostream>
using namespace std;
int t,n;
int main() {
    cin>>t;
    while(t--){
        cin>>n;
        if(n<2){
            cout<<0<<endl;
        }else{
            cout<<n-2<<endl;
        }
    }
    return 0;
}
