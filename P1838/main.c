#include <stdio.h>
#include <string.h>
int main() {
    char steps[10];
    char heng[]={0,
    1,1,1,
    2,2,2,
    3,3,3
    };
    char shu[]={0,
    4,5,6,
    4,5,6,
    4,5,6};
    char xie1[]={0,
    7,0,0,
    0,7,0,
    0,0,7
    };
    char xie2[]={0,
    0,0,8,
    0,8,0,
    8,0,0
    };
    int place[2][9]={0};
    scanf("%s",steps);
    for(int i=0;i<strlen(steps);i++){
        place[i%2][heng[steps[i]-'0']]++;
        place[i%2][shu[steps[i]-'0']]++;
        place[i%2][xie1[steps[i]-'0']]++;
        place[i%2][xie2[steps[i]-'0']]++;
    } //i%2==0是xiaoa

    for(int a=1;a<=8;a++){
        if(place[0][a]==3){
            printf("xiaoa wins.");
            return 0;
        }
        else if(place[1][a]==3){
            printf("uim wins.");
            return 0;
        }
    }
    printf("drew.");
    return 0;
}
