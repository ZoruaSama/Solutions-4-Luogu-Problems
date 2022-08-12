#include <stdio.h>

int main() {
    int n;
    int max=0;
    scanf("%d",&n);
    int d=0,m=-1,sum=1; //m设置为-1 以免与输入的第一个1连号
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        if(d-m == 1){
            sum += 1;
        }
        else{
            if(max<sum){
                max = sum;
            }
            sum = 1;
        }
        m = d;
    }
    printf("%d\n",max);
    return 0;
}
