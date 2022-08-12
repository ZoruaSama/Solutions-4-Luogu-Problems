#include <stdio.h>
#include <string.h>
int isDig(char a){
    return (a<='9' && a>='0');
}
int isAlp(char a){
    return (a<='z' && a>='a') || (a<='Z' && a>='A');
}
int main() {
    char a[10];
    int sum=0;
    gets(a);
    for(int i=0;i<strlen(a);i++){
        sum += isDig(a[i]) + isAlp(a[i]);
    }
    printf("%d",sum);
    return 0;
}
