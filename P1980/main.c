#include <stdio.h>

int main() {
    int n,x;
    int count[10]={0};
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        int a=i;
        while(a!=0){
            count[a%10]++;
            a/=10;
        }
    }
    printf("%d",count[x]);
    return 0;
}
