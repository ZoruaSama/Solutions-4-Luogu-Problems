#include <stdio.h>
#include <string.h>
int main() {
    int a;
    char b[1000];
    scanf("%d%s",&a,b);
    for(int i=0,num = (int)strlen(b)-1;i < strlen(b);i++,num--){
        if(b[i] != '0'){
            printf("%c*%d^%d",b[i],a,num);
        }
        if(b[i+1] != '0' && b[i+1] != '\0') printf("+");

    }
    return 0;
}
