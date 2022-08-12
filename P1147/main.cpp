#include <iostream>
using namespace std;

int main() {
    int m;
    cin>>m;
    // (a+b)(b-a+1)=2m
    for(int i=0;i<=m/2+1;++i){
        for(int j=i+1;j<=m/2+1;++j){
            int sum =(i+j)*(j-i+1);
            if(sum==2*m){
                cout<<i<<' '<<j<<endl;
            }else if(sum>2*m){
                break;
            }
        }
    }
    return 0;
}
