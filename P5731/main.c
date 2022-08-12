#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int map[10][10]={0};
    map[1][1]=1;
    for(int i=1,j=1,num=1;num < n * n;){
        while(++j<=n && !map[i][j])
            map[i][j]=++num;
        --j;
        while(++i<=n && !map[i][j]) map[i][j]=++num;--i;
        while(--j>0 && !map[i][j]) map[i][j]=++num;++j;
        while(--i>0 && !map[i][j]) map[i][j]=++num;++i;
    }
    for(int i=1;i<=n;i++,printf("\n"))
        for(int j=1;j<=n;j++)
            printf("%3d",map[i][j]);
    return 0;
}
