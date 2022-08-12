#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char x[101];
    char y[101];
    char z[101];
    scanf("%s", x);
    scanf("%s", z);
    int i;
    for (i = 0; i < n; i++) {
        if (z[i] == x[i]) {
            y[i] = (x[i] + z[i])/2;
            if (y[i] > 'z') {
                printf("-1");
                return 0;
            }
        } else {
            y[i] = z[i];
            if(y[i]>x[i]){
                printf("-1");
                return 0;
            }
        }

    }
    y[i] = '\0';
    printf("%s",y);
    return 0;
}
