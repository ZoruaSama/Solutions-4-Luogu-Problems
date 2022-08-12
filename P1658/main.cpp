#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int c[1002];
bool cmp(int a,int b){
    return a>b;
}
int main() {
    int x,n;
    int res=1;
    int cnt=1;
    cin>>x>>n;
    for(int i=1;i<=n;++i){
        cin>>c[i];
    }
    sort(c+1,c+1+n,cmp);
    if(c[n]!=1){
        cout<<-1;
        return 0;
    }else{
        while(res<x){
            for(int i=1;i<=n;++i){
                if(c[i]<=res+1){
                    res+=c[i];
                    break;
                }
            }
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}


/*
int x,n;
    int s[10];
    int re[1001]={0};
    cin>>x>>n;
    for(int i=0;i<n;++i){
        cin>>s[i];
    }
    for(int i=0;i<1001;++i){
        re[i]=-1;
    }
    sort(s,s+n,greater<int>());
    int res=-1;
    for(int i=1;i<=x;++i){
        int cnt=0;
        int c=i;
        cout<<c<<':';
        while(c!=0){
            int j;
            for(j=0;j<n;++j){
                if(s[j]<=c){
                    cout<<s[j]<<' ';
                    c-=s[j];
                    cnt++;
                    break;
                }
            }

            if(j==n){
                cout<<-1;
                return 0;
            }
        }
        cout<<endl;
        re[i]=cnt;
        res=max(cnt,res);
    }
    //cout<<res;
*/