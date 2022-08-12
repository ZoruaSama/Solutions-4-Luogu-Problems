#include <stdio.h>
#include <string.h>

int main() {
    char planet[6];
    char team[6];
    int a=1;
    int b=1;
    scanf("%s",planet);
    scanf("%s",team);
    for(int i=0;i<strlen(planet);++i){
        a*=planet[i]-'A'+1;
    }
    a%=47;
    for(int i=0;i<strlen(team);++i){
        b*=team[i]-'A'+1;
    }
    b%=47;
    if(a==b){
        printf("GO");
    }else{
        printf("STAY");
    }
    return 0;
}
