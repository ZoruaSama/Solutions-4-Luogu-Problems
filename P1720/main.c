#include <stdio.h>
#include <math.h>
#define gh5 2.2360679774998
int main() {
    int n;
    scanf("%d",&n);
    printf("%.2lf",(pow((1+gh5)/2,n)-pow((1-gh5)/2,n))/gh5);
    return 0;
}
