#include <stdio.h>

int main() {
    int n,d,m=1000001,max=0,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&d);
        if(d>m){
            sum++;
        }
        else{
            if(sum>max){
                max=sum;
            }
            sum=0;
        }
        m=d;
    }
    if(sum>max){
        max=sum;
    }
    sum=0;
    printf("%d",max+1);
    return 0;
}
