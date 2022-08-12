#include <stdio.h>

int main() {
    int a,b,max=0,day=0;
    for(int i=1;i<=7;i++){
        scanf("%d%d",&a,&b);
        if(a+b>max){
            max = a+b;
            day = i;
        }
    }
    printf("%d",day);
    return 0;
}
