#include <iostream>
using namespace std;
int is_prime(int integer){
    int i;
    for(i=2;i*i<=integer;++i)
    {
        if(integer%i==0)
            return 1;
    }
    return 0;
}
int main() {
    int n;
    cin>>n;
    for(int i=4;i<=n;i+=2){
        for(int j=2;j<i;++j){
            if(is_prime(j)+is_prime(i-j)==0){
                cout<<i<<'='<<j<<'+'<<i-j<<endl;
                break;
            }
        }
    }
    return 0;
}
