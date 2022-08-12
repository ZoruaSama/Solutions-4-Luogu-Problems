#include <stdio.h>

int main() {
    int n;
    int min;
    scanf("%d",&n);
    scanf("%d",&min);
    for(int i=1;i<n;i++){
        int a;
        scanf("%d",&a);
        if(a<min){
            min=a;
        }
    }
    printf("%d",min);
    return 0;
}
