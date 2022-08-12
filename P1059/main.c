#include <stdio.h>

int main() {
    int n;
    int a[100]={0};
    int count = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(int i=0;i<n;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[k])
                k=j;
            else if(a[j]==a[k]){
                a[j] = 1001;
            }


        }
        if(k!=i){
            int temp = a[k];
            a[k]=a[i];
            a[i]=temp;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i] != 1001)
            break;
        count++;
    }
    printf("%d\n",n-count);
    for(int i=0;i<n;i++){
        if(a[i]==1001)
            break;
        printf("%d ",a[i]);
    }

    return 0;
}
