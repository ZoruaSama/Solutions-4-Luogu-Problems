#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n,M,T;
int f[1010][1010];
int m[1010],t[1010];
int main(){
    scanf("%d%d%d",&n,&M,&T);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&m[i],&t[i]);
        for(int j=M;j>=m[i];--j){
            for(int k=T;k>=t[i];--k){
                f[j][k]=max(f[j][k],f[j-m[i]][k-t[i]]+1);
            }
        }
    }
    printf("%d",f[M][T]);
}