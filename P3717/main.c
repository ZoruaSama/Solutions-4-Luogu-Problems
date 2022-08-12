#include <stdio.h>
#include <math.h>

int main() {
    int n,m,r;
    char map[101][101]={0};
    scanf("%d%d%d",&n,&m,&r);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        for(int xi=0;xi<=n;xi++){
            for(int yi=0;yi<=n;yi++){
                double r1 = sqrt(pow(x-xi,2)+pow(y-yi,2));
                if(r1<=r){
                    map[xi][yi]=1;
                }
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
                sum+=map[i][j];
        }
    }
    printf("%d",sum);
    return 0;
}
