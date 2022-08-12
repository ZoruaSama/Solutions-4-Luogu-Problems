#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=2e4+10;
int t,n;
char c;
int par[maxn];
int main() {
    scanf("%d",&t);
    while(t--){
        int u,v;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            par[i]=i;
        }
        while(true){
            scanf("%c",&c);
            if(c=='I'){
                scanf("%d%d",&u,&v);
                par[u]=v;
            }else if(c=='E'){
                scanf("%d",&u);
                int ans=0;
                for(int i=u;i!=par[i];i=par[i]){
                    ans+=((abs(i-par[i]))%1000);
                }
                printf("%d\n",ans);
            }else{
                break;
            }
        }


    }


    return 0;
}
