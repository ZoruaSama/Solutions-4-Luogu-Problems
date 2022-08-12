#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a,b;
    int n;
    int res=-1;
    cin>>n;
    for(a=1;a<=n;a++){
        for(b=1;b<=n;b++){
           res=max(res,(a | b)+(a xor b));
        }
    }
    cout<<res;
    return 0;
}
