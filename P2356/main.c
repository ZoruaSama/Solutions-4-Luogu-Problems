#include <stdio.h>

int main() {
    int map[1000][1000];
    int n;
    int safe[20000]={-1};
    int a = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",map[i][j]);
            if(map[i][j] != 0){
                safe[a] = i;
                safe[a+10000] =j ;
                a++;
            }
        }
    }
    if(safe[0] == -1){
        printf("Bad Game!");
        return 0;
    }
    a = 0;
    int sum = 0;
    int max = 0;
    while(safe[a] != -1){
        for(int i=0;i<n;i++){
            sum+=map[safe[a]][i];
        }
        for(int i=0;i<n;i++){
            sum+=map[i][safe[a+10000]];
        }
        if(sum > max){
            max = sum;
        }
        a++;
    }
    return 0;
}
