#include <stdio.h>

int main() {
    int n,sum=0;
    int s[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",s+i);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(s[j]<s[i]){
                sum=sum+1;
            }
        }
    }
    printf("%d",sum);
    return 0;
}
