#include <stdio.h>
int main(){
    long long ans=0;
    int n=0,a;
    while(scanf("%d",&a)!=EOF){
        ans+=a;
        n++;
    }
    for(int i=1;i<n;i++) {
        ans=ans<<1;
    }
    printf("%lld",ans);
    return 0;
}