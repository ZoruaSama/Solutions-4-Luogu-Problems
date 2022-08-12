#include <iostream>
using namespace std;
int apples[100][4]={0};
// 0是节点数 1是1节点 2是2节点 3是3节点
int edge[101][101]={0};
// edge[i][j] 是节点i 和 节点j 的树枝上苹果数量
int f[101][101]={0};
// f[i][j] 表示 i 节点上 保留 j 个树枝的最大苹果数
// f[1][2] = max(f[3][1]+f[4][1],f[3][2]+f[4][0])
// f[1][3] = max(f[3][2]+f[4][1],f[3][1]+f[4][2],f[3][3]+f[4][0])
int n,q;
int dfs(int x,int y,int fa){
    int res=-1;
    if(apples[x][0]==1 || y<=0) return f[x][y]=0;
    if(f[x][y]!=-1) return f[x][y];
    int l,r;
    if(apples[x][1]==fa){
        l=apples[x][2];
        r=apples[x][3];
    }else if(apples[x][2]==fa){
        l=apples[x][1];
        r=apples[x][3];
    }else if(apples[x][3]==fa){
        l=apples[x][1];
        r=apples[x][2];
    }
    for(int j=0;j<=y;j++){ //分配方案
        int ls=(j>0)? edge[x][l] : 0;
        int rs=(y-j>0)? edge[x][r] : 0;
        res=max(res,dfs(l,j-1,x)+dfs(r,y-j-1,x)+ls+rs);
    }
    return f[x][y]=res;
}
int main() {
    cin>>n>>q;
    apples[1][3]=1;
    for(int i=0;i<n-1;++i){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a][b]=c;
        edge[b][a]=c;
        apples[a][apples[a][0]+1]=b;
        apples[b][apples[b][0]+1]=a;
        apples[a][0]++;
        apples[b][0]++;
    }
    for(int i=1;i<=100;++i){
        for(int j=1;j<=100;++j){
            f[i][j]=-1;
        }
    }
    dfs(1,q,1);
    cout<<f[1][q];
    return 0;
}

//5 2
//1 3 1
//1 4 10
//2 3 20
//3 5 20



/*
void dfs(int x,int y){
    if(y<=2 && y>0){
        f[x][1]=max(edge[x][apples[x][1]],edge[x][apples[x][2]]);
        f[x][2]=edge[x][apples[x][1]]+edge[x][apples[x][2]];
    }
    if(apples[x][0]==0 || y==0){
        return;
    }
    else{
        dfs(apples[x][1],y-1);
        dfs(apples[x][2],y-1);
        for(int i=y;i>=1;i--){ //背包总容量
            for(int j=0;j<=i-1;j++){ //分配方案
                f[x][i]=max(f[x][i],f[apples[x][1]][j]+f[apples[x][2]][i-j]+f[x][1]);
            }
        }
    }
//f[x][i]=max(max(f[x][i],f[x][i-1]+f[apples[x][2]][i]),f[x][i-1]+f[apples[x][3]]));
//    for(int i=0;i<=y;++i){
//        maxn=max(+dfs(apples[x][3],y-i),maxn);
//    }
//    return f[x][y]=maxn;
}
 */