#include <stdio.h>

int main() {
    int n,k;
    int a=0,b=0;
    int sum1=0,sum2=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        if(i%k==0){
            a++;
            sum1+=i;
        }else{
            b++;
            sum2+=i;
        }
    }
    printf("%.1lf %.1lf",sum1*1.0/a,sum2*1.0/b);
    return 0;
}
