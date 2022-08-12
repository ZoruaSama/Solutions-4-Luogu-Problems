#include <stdio.h>

int main() {
    int n;
    int sum=1;
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        sum+=1;
        sum*=2;
    }
    printf("%d",sum);
    return 0;
}
