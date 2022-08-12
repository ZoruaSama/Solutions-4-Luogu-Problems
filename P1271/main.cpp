#include <iostream>
using namespace std;
int main() {
    int n,m;
    int a[1000]={0};
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>n;
        a[n]++;
    }
    for(int i=0;i<1000;i++){
        while(a[i]--){
            cout<<i<<' ';
        }
    }
    return 0;
}
