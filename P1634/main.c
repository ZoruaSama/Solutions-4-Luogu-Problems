#include <stdio.h>

int main() {
    long y=1,x,n;
    scanf("%ld%ld",&x,&n);
    for(long i=0;i<n;i++){
        y=y+y*x;
    }
    printf("%ld",y);
    return 0;
}
