#include <stdio.h>
#include <string.h>

int main() {
    char a[201];
    int n=0;
    char m = '0';
    int sum=0;
    int j = 1;
    do{
        gets(a);
        if(n==0){
            n = strlen(a);
            printf("%d ",n);
        }

        for (int i = 0; i < n; i++) {
            if (a[i] != m) {
                printf("%d ",sum);
                sum = 1;
                m = a[i];
            }
            else {
                sum++;
            }
        }

    }while(j++ < n);
    printf("%d ",sum);
    return 0;
}