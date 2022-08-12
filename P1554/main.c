#include <stdio.h>

int main() {
    int a,b;
    int count[10]={0};
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++){
        int x=i;
        while(x!=0){
            count[x%10]++;
            x/=10;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",count[i]);
    }
    return 0;
}
