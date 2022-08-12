#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int map[10000];
    int count=0;
    for(int i=0;i<n;i++){
        scanf("%d",map+i);
    }
    for(int i=1;i<n-1;i++){
        if(map[i]<map[i-1] && map[i]<map[i+1]){
            count++;
        }
        else if(map[i]==map[i+1]){
            map[i]++;
        }
    }
    printf("%d",count);
    return 0;
}
