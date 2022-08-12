#include <iostream>
#include <math.h>
using namespace std;
int main() {
    unsigned long long n;
    cin>>n;
    if(n==1){
        cout<<1;
    }else{
        cout<<(unsigned long long)pow(2,(unsigned long long)log2(n)+2)-2;
    }
    return 0;
}
