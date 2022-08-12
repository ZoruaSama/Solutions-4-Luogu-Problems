#include <iostream>
using namespace std;
int main(){
    int n;
    int cn=1;
    cin>>n;
    cout<<n<<endl;
    for(int i=0;i<n;++i){
        cn=1-cn;
        for(int j=0;j<=i;++j)
            cout<<cn;
        for(int j=i+1;j<n;++j)
            cout<<1-cn;

        cout<<endl;
    }
    return 0;
}