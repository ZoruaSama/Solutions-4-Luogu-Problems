#include <stdio.h>

int main() {
    int n;
    double a=0;
    double b=0;
    int d;
    double sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&d);
        a+=d*1.0;
    }
    for(int i=0;i<n;++i){
        scanf("%d",&d);
        b+=d*1.0;
    }
    sum = (a*3-b*2) * 1.0 / (a-b);
    printf("%.6lf",sum);
    return 0;
}
