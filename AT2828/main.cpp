#include <iostream>
using namespace std;
int n;
const int maxn=1e5+10;
int a[maxn];
int sum[maxn];
int ask(int x,int y){
    return sum[y]-sum[x-1];
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(ask(i,j)==n){
                cnt++;
            }else if(ask(i,j)>n){
                break;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
