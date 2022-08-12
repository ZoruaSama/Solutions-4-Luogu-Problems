#include <stdio.h>

int n;

int main() {
    scanf("%d", &n);
    printf("%s\n", (n * 5) > (n * 3 + 11) ? "Luogu" : "Local");
    return 0;
}