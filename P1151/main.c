#include <stdio.h>
#include <stdlib.h>

int main() {
    int k;
    int m = 0;
    scanf("%d", &k);
    int sub1, sub2, sub3;
    for (int i = 10000; i <= 30000; ++i) {
        sub1 = i / 100;
        sub2 = i % 10000 / 10;
        sub3 = i % 1000;
        if(!(sub1%k+sub2%k+sub3%k)){
            m = 1;
            printf("%d\n",i);
        }
    }
    if(m == 0){
        printf("No");
    }
    return 0;
}
