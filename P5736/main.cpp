#include <iostream>
using namespace std;
bool isPrime(int x){
    if(x<2) return false;
    else{
        for(int i=2;i<=x/2;++i){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
}
int main() {
    int n,d;
    cin>>n;
    while(n--){
        cin>>d;
        if(isPrime(d)) cout<<d<<' ';
    }
    return 0;
}
