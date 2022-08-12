#include <stdio.h>
void num(int i){
    if(i==0)
        return;
    int a;
    scanf("%d",&a);
    num(a);
    printf("%d ",i);
}
int main() {
    int a;
    scanf("%d",&a);
    num(a);
    return 0;
}
