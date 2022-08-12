#include <stdio.h>
#include <string.h>

int main() {
    char s[51];
    int aj[8]={0};
    int kb[]={0,1,2,3,3,4,4,5,6,7,7,7,
              0,1,2,3,3,4,4,5,6,7,7,7,
              0,1,2,3,3,4,4,5,6,7,7,
              0,1,2,3,3,4,4,5,6,7};
    char zm[]="1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
    scanf("%s",s);
    for(int i=0;i<strlen(s);++i){
        int j;
        for(j=0;j<strlen(zm);++j){
            if(zm[j] == s[i]){
                break;
            }
        }
        aj[kb[j]]++;
    }
    for(int i=0;i<8;i++){
        printf("%d\n",aj[i]);
    }
    return 0;
}