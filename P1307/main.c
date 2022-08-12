#include <stdio.h>

int main() {
    int a;
    int sum=0;
    scanf("%d",&a);
    if(a<0){
        printf("-");
        a=-a;
    }
    while(a!=0){
        sum*=10;
        sum+=a % 10;
        a/=10;
    }
    printf("%d", sum );
    return 0;
}
