#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,k;
struct book{
    int w;
    int h;
}books[101];
bool cmp(book a,book b){
    return a.h<b.h;
}
int cost(int a,int b){
    return abs(books[a].w-books[b].w);
}
int f[101][101]={0}; //从第i本前面选j本书时的最小不复杂度
/*
状态转移
f[5][3] 5本里面选了3本且最后一本是5号
f[4][3] 4本里面选了3本且最后一本是4号
         5本里面选了3本且最后一本是4号 不选5号
f[0][*]=0
f[*][0]=0
f[*][1]=0
f[7][5]=min(f[4][4]+cost(4,7),f[5][4]+cost[5,7],f[6][4]+cost[6,7]...
f[4][3]={1,2,4 1,3,4 2,3,4} min(f[2][2]+cost(2,4)//f[3][2]+cost(3,4))
f[3][2]={1,3 2,3} min(f[2][1]+cost(2,3) // f[1][1]+cost(1,3))
f[2][2]={1,2}  min(f[1][1]+cost(2,1)
f[2][1]={2} 0
f[2][2]=f[1][1]
*/

int main() {
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>books[i].h>>books[i].w;
    }
    sort(books+1,books+1+n,cmp);
    int p=n-k; //取p本书
    for(int i=2;i<=n;++i){
        for(int j=2;j<=p;j++){
           f[i][j]=2e9;
           for(int l=j-1;l<=i-1;l++){
               f[i][j]=min(f[i][j],f[l][j-1]+cost(l,i));
           }
        }
    }
    int ans=2e9;
    for(int i=p;i<=n;++i){
        ans=min(ans,f[i][p]);
    }
    cout<<ans;
    return 0;
}
