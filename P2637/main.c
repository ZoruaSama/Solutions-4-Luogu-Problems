#include <stdio.h>

int main() {
    int n,m;
    int s[1001]={0};
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",s+i);
    }
    for(int i=0;i<m;i++){
        int k=i;
        for(int j=i+1;j<m;j++){
            if(s[j] < s[k]){
                k=j;
            }
        }
        if(k!=i){
            int temp=s[i];
            s[i]=s[k];
            s[k]=temp;
        }
    }
    int max =0;
    int a=0;
    for(int i=0;i<m;i++){
        if(s[i]*(m-i)>max){
            max = s[i]*(m-i);
            a = s[i];
        }

    }
    printf("%d %d",a,max);
    return 0;
}
