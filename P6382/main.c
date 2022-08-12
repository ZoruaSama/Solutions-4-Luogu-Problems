#include <stdio.h>

int main() {
    char s[8];
    scanf("%s",s);
    if(s[0]=='M' && s[1]=='D' && s[2] =='A'){
        int i=7;
        while(s[i--]>'9');++i;
        switch(s[i]-'0'){
            case 1:
            case 9:
                printf("1 0 0 0 0");
                break;
            case 2:
            case 8:
                printf("0 1 0 0 0");
                break;
            case 3:
            case 7:
                printf("0 0 1 0 0");
                break;
            case 4:
            case 6:
                printf("0 0 0 1 0");
                break;
            case 5:
            case 0:
                printf("0 0 0 0 1");
                break;
        }
    }else{
        printf("1 1 1 1 1");
    }
    return 0;
}
