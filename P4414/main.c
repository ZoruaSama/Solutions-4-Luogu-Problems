#include <stdio.h>
int max(int a,int b,int c){
    if(a>b && a>c){
        return 0;
    }
    if(b>a && b>c){
        return 1;
    }
    if(c>a && c>b){
        return 2;
    }
}
int main() {
    int n[3];
    int b[3];
    for(int i=0;i<3;i++){
        scanf("%d",n+i);
    }
    char a[4];
    for(int i=0;i<3;i++){
        b[2-i] = n[max(n[0],n[1],n[2])];
        n[max(n[0],n[1],n[2])] = -2147483648;
    }

    scanf("%s",a);

    for(int i=0;i<3;i++){
        printf("%d ",b[a[i]-'A']);
    }
    return 0;
}
