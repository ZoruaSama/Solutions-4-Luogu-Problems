#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int a=1;n>0;n--){
        for(int i=1;i<=n;i++,a++){
            printf("%02d",a);
        }
        printf("\n");
    }


    return 0;
}
