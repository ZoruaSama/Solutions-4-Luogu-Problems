#include <iostream>
#include <cstdio>
using namespace std;
typedef __int128 ll;
ll f[1001];
void print(ll num){
    if(num/10!=0){
        print(num/10);
    }
    printf("%d",num%10);
}
int main() {
    int k,n;
    cin>>n>>k;
    f[0]=1;
    for(int i=1;i<=k;++i){
        for(int j=i;j<=n;++j){
            f[j]+=f[j-i];
        }
    }
    print(f[n]);
    return 0;
}
