#include <stdio.h>

int main() {
    unsigned long long sum;
    unsigned long long n;
    scanf("%d",&n);
    sum = n*(n-1)/2*(n-2)/3*(n-3)/4;
    printf("%lld",sum);
    return 0;
}