#include <stdio.h>

int main() {
    int sum;
    int n,k;
    scanf("%d%d",&n,&k);
    sum=n;
    while(n>=k){
        n-=k;
        n+=1;
        sum+=1;
    }
    printf("%d",sum);
    return 0;
}
