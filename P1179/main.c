#include <stdio.h>

int main() {
    int a,b,count=0;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;++i){
        int d=i;
        while(d!=0){
            if(d%10 == 2){
                count++;
            }
            d/=10;
        }
    }
    printf("%d",count);
    return 0;
}
