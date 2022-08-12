#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=5e4+11;
const int mod=19491001;
int key[maxn];
int v[maxn];
int hash_(int x,int k){
    int y = (x+k)%maxn;
    if(key[y]==-1){
        key[y]=x;
        return y;
    }else if(key[y]==x){
        return y;
    }else{
        return hash_(x,k+mod);
    }
}
int T,n;

int main() {
    scanf("%d",&T);
    for(int t=1;t<=T;++t){
        for(int i=0;i<maxn;++i){
            key[i]=-1;
            v[i]=0;
        }
        scanf("%d",&n);
        int l;
        for(int i=1;i<=n;++i){
            scanf("%d",&l);
            if(v[hash_(l,0)]==0){
                printf("%d ",l);
                v[hash_(l,0)]=1;
            }
        }
        cout<<endl;
    }
    return 0;
}
