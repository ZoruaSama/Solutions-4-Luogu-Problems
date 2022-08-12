#include <iostream>
using namespace std;
int main() {
    int n,k;
    int barrel[30001]={0};
    cin>>n>>k;
    for(int i=0;i<n;++i){
        int d;
        cin>>d;
        barrel[d] = 1;
    }
    for(int i=0;i<=30000;++i){
        if(barrel[i]!=0){
            k--;
        }
        if(k==0){
            cout<<i;
            return 0;
        }
    }
    cout<<"NO RESULT";
    return 0;
}
