#include <stdio.h>

int main() {
    int n,m,k;
    int map[101][101]={0};
    int fire[][2]={{0,0},{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1},{0,-2},{0,2},{2,0},{-2,0}};
    int stone[][2]={{0,0},{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1},{0,-2},{0,2},{2,0},{-2,0},
                    {-2,1},{-2,2},{-1,2},{1,2},{2,1},{2,2},{-1,-2},{-2,-2},{-2,-1},{2,-2},{2,-1},{1,-2}};
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        for(int j=0;j<13;j++){
            int xc = x+fire[j][0];
            int yc = y+fire[j][1];
            if(xc > 0 && xc < 101 && yc > 0 && yc < 101)
            map[xc][yc]=1;
        }
    }
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        for(int j=0;j<25;j++){
            int xc = x+stone[j][0];
            int yc = y+stone[j][1];
            if(xc > 0 && xc < 101 && yc > 0 && yc < 101)
                map[xc][yc]=1;
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++){
//            printf("%d ",map[i][j]);
//        }
//        printf("\n");
        for(int j=1;j<=n;j++){
            sum += (1-map[i][j]);
        }
    }
    printf("%d",sum);
    return 0;
}
