#include <stdio.h>
#include <string.h>
int main() {
    int count[26]={0};
    char s[100];
    for(int i=0;i<4;++i){
        gets(s);
        for(int j=0;j<strlen(s);++j){
            count[s[j]-'A']++;
        }
    }
    int max=0;
    for(int i=0;i<26;++i){
        if(count[max]<count[i]){
            max=i;
        }
    }
    for(int i=count[max];i>0;--i){
        for(int j=0;j<26;++j){
            printf("%c",count[j]>=i ? '*':' ');
            if(j!=25) printf(" ");
        }
        printf("\n");
    }
    for(int j=0;j<26;++j){
        printf("%c",'A'+j);
        if(j!=25) printf(" ");
    }
    return 0;
}
