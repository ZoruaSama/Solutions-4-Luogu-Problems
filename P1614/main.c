#include <stdio.h>

int main() {
    int n,m;
    int a[3000];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int min = -1;

    for(int i=0;i<=n-m;i++){
        int sum = 0;
        for(int j=i;j<i+m;j++){
            sum+=a[j];
        }
        if(sum<min){
            min = sum;
        }
        else if(min == -1){
            min = sum;
        }
    }
    printf("%d",min);
    return 0;
}
