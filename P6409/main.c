#include <stdio.h>
#include <string.h>
int main() {
    char s[101];
    gets(s);
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            printf("%c",s[i]);
            i+=2;
        }else{
        printf("%c",s[i]);}
    }
    return 0;
}
