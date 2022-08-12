#include <stdio.h>

int main() {
    char s[255];
    char kh=0;
    char amount=0;
    scanf("%s",s);
    int i=-1;
    while(s[++i] != '@'){
        if(s[i] == '('){
            amount +=1;
            kh +=1;
        }
        else if(s[i] == ')'){
            amount -=1;
            if(kh>0) kh -=1;
        }
    }
    if(kh==0 && amount ==0){
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}
