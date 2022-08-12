#include <stdio.h>
int gcd(int a,int b){
    int c;
    c=a%b;
    while(c!=0){
        a=b;b=c;
        c=a%b;
    }
    return b;
}
int max(int a,int b){
    return a>b ? a : b;
}
int min(int a,int b){
    return a<b ? a : b;
}
int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int j = min(min(a,b),c);
    int k = max(max(a,b),c);
    printf("%d/%d\n",j/gcd(j,k),k/gcd(j,k));
    return 0;
}
