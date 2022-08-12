#include <stdio.h>

int main() {
    char symbol = 43;
    char msymbol =43;
    int s;
    long long sum=0;
    while(1){
        s=0;
        scanf("%d%c",&s,&symbol);
        if(symbol=='+' || symbol=='-'){
            sum += s * (44-msymbol);
            msymbol = symbol;
        }
        else {
            sum += s * (44-msymbol);
            break;
        }
    }
    printf("%lld",sum);
    return 0;
}
