#include <stdio.h>

int main() {
    int n,a,max=-1,min=1001;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(a>max){max=a;}
        if(a<min){min=a;}
    }
    printf("%d",max-min);
    return 0;
}
