#include <stdio.h>

int main() {
    int x,y;
    int sum=0;
    int re[1418],r=0;
    scanf("%d%d",&x,&y);
    while(x&3)++x;
    for(int i=x;i<=y;i+=4){
        sum+=1;
        re[r++]=i;
        if(i % 100 ==0 && i%400 != 0){
            sum--;
            r--;
        }
    }
    printf("%d\n",sum);
    for(int i=0;i<r;i++){
        printf("%d ",re[i]);
    }
    return 0;
}
