#include <stdio.h>
#include <math.h>
int main() {
    int n,d,m,re[1000]={0};
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=n;i>1;--i){
        scanf("%d",&d);
        if(abs(m-d)>0 && abs(m-d)<1000)
        re[abs(m-d)]=1;
        m=d;
    }
    int j;
    for(j=1;j<n;j++){
        if(re[j]!=1){
            break;
        }
    }
    if(j==n){
        printf("Jolly");
        return 0;
    }
    printf("Not jolly");
    return 0;
}
