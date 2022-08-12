#include <stdio.h>

int main() {
    long long n;
    int i=0;
    scanf("%lld",&n);
    while(n!=1){
        if(n%2==1){
            n=n*3+1;
        }
        else{
            n/=2;
        }
        i++;
    }
    printf("%d",i);
    return 0;
}
