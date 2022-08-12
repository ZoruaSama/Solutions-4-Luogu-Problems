#include <stdio.h>

int main() {
    int n,sum=0;
    scanf("%d",&n);
    while(n!=1){
        n/=2;
        sum+=1;
    }
    printf("%d",sum+1);
    return 0;
}
