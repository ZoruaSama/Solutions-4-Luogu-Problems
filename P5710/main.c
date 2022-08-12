#include <stdio.h>

int main() {
    int x;
    int r=0;
    scanf("%d",&x);
    if(x%2==0){
        r++;
    }
    if(x>4 && x<=12){
        r++;
    }
    printf("%d ",r==2);
    printf("%d ",r>=1);
    printf("%d ",r==1);
    printf("%d ",r==0);
    return 0;
}
