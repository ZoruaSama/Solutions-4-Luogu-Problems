#include <iostream>
using namespace std;
int main() {
    int k;
    int n=1;
    cin>>k;
    double sum=0.00000;
    while(sum<=k){
        sum+=1.0/(n++);
    }
    cout<<n-1;
    return 0;
}
