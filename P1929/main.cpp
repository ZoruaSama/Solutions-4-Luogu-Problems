#include <iostream>
#include <algorithm>
using namespace std;
int a[202]={0};
int n;

int main() {
    long long f[201]={0};
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    a[n+1]=1e9;
    f[1]=0;
    for(int i=2;i<=n;++i){
        long long res=2e9;
        for(int j=1;j<=i-1;j++){
            if(j==i-1 && a[i]-a[i-1]==1){
                res=min(res,f[i-1]+1);
            }else{
                int k;
                for(k=j-1;k>0;k--){
                    if(a[i]-a[k] <= (1<<(j-k))){ //NOLINT
                        break;
                    }
                }
                if(k!=0){
                    res=min(res,f[j]+j-k+1);
                }
            }
            f[i]=res;
        }
    }
    if(f[n]==(long long)2e9){
        cout<<-1;
        return 0;
    }
    cout<<f[n];
    return 0;
}



/*
#include <iostream>
using namespace std;
int a[202]={0};
int n;
int res=2e9;
void dfs(int s,int step,int k){
    if(s==n) {
        res=min(res,step);
        return;
    }
    if(step>res){
        return ;
    }
    if(a[s+1]-a[s]==1 && k==0){
        dfs(s+1,step+1,k);
    }else{
        if(s>1){
            dfs(s-1,step+1,k+1);
        }
        if(k!=0){
            int d=1;
               while(s+d<=n && a[s+d]-a[s]<=(1<<k)){
                d++;
            }
            dfs(s+d-1,step+1,0);
        }
    }
}
int main() {
    int f[201]={0};
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    a[n+1]=1e9;
    dfs(1,0,0);
    cout<<res;
    return 0;
}


 */