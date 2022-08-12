#include <stdio.h>
#include <string.h>
int main() {
    char s[51];
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){

        if(s[i] +  n%26 >122){
            s[i] = (s[i]+n%26) % 122+96;
        }
        else{
            s[i]=s[i] + n%26;
        }
    }
    printf("%s",s);
    return 0;
}
