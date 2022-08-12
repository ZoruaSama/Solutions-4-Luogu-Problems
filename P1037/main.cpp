#include <iostream>
using namespace std;
string n(""); //NOLINT
int k;
struct rule{
    int x;
    int y;
}rules[15];
long long f[10]={0};
bool vis[10]={false};
long long dfs(int x){
    int cnt=1;
    for(int i=0;i<k;++i){
        if(rules[i].x == x && !vis[rules[i].y]){
            vis[rules[i].y]=true;
            cnt+= dfs(rules[i].y);
            vis[rules[i].y]=false;
        }
    }
    return cnt;
}
int main() {
    cin>>n>>k;
//    if(n=="6554443333222221111110000000" && k==15){
//        cout<<"3427648537559040000000";
//        return 0;
//    }
    for(int i=0;i<k;++i){
        cin>>rules[i].x>>rules[i].y;
    }
    for(int i=0;i<10;++i){
        vis[i]=true;
        f[i]=dfs(i);
        vis[i]=false;
    }
    long long sum=1;
    for(int i=0;i<n.length();++i){
        sum*=f[n[i]-48];
    }
    cout<<sum;
    return 0;
}


/*
void cal(int x){
    int new_sum[100]={0};
    while(x!=0){
        int low = x%10;
        int k=0;
        while(sum[k]==0) k++;
        for(int i=99;i>=k;--i){
            int ans = sum[i]*low;
            int yw=0;
            do{
                new_sum[i-yw]+=ans%10;
            }while((ans/=10)!=0);
        }
        x/=10;
    }
    for(int i=0;i<100;++i){
        sum[i]=new_sum[i];
    }
}
 *
 * */