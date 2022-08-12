#include <stdio.h>

int main() {
    int x;
    scanf("%d",&x);
    printf("Today, I ate %d apple%s",x,(x - 1)&&(x) ? "s.":".");
    return 0;
}
