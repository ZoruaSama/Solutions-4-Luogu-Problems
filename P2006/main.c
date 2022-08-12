#include <stdio.h>

int main() {
    int k,m,n;
    int a,b;
    char beat=0;
    scanf("%d%d%d",&k,&m,&n);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        if(a == 0){
            printf("%d ",i+1);
            beat = 1;
        }
        else if(k/a*b>=n){
            printf("%d ",i+1);
            beat = 1;
        }
    }
    if(beat == 0)
        printf("-1");
    return 0;
}
