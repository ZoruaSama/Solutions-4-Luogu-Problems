#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * n;) {
        int a;
        scanf("%d", &a);
        for (int j = 0; j < a && i < n * n; j++) {
            printf("%d", 0);
            i += 1;
            if (i % n == 0 && i != n * n)
                printf("\n");
        }
        scanf("%d", &a);
        for (int j = 0; j < a && i < n * n; j++) {
            printf("%d", 1);
            i += 1;
            if (i % n == 0 && i != n * n)
                printf("\n");
        }
    }
    return 0;

}
