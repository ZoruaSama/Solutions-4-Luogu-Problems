#include <stdio.h>

int main() {
    int i,sum=0,max=0,k,a;
    for(i=1;i<=5;++i){
        sum=0;
        for(int j=0;j<4;++j){
            scanf("%d",&a);
            sum+=a;
        }
        if(sum > max){
            max=sum;
            k=i;
        }
    }
    printf("%d %d",k,max);
    return 0;
}
