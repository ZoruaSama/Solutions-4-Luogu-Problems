#include <stdio.h>

int main() {
    char a;
    char sum=0;
    for(int i=0;i<8;i++){
        a=getchar()-48;
        sum+=a;
    }
    printf("%d",sum);
    return 0;
}
