#include <iostream>
using namespace std;
int main() {
    int n,k,t,xl,yd,xr,yu;
    int x,y,cntk;
    bool flag=false;
    bool flag2=false;
    int cnt1=0,cnt2=0;
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    for(int i=0;i<n;++i){
        flag=false;flag2=false;cntk=0;
        for(int j=0;j<t;++j){
            cin>>x>>y;
            if(x>=xl && x<=xr && y>=yd && y<=yu){
                flag=true;
                cntk++;
                if(cntk==k){
                    flag2=true;
                }
            }else{
                cntk=0;
            }
        }
        if(flag){
            //cout<<i+1<<"pass"<<endl;
            cnt1++;
        }
        if(flag2){
            cnt2++;
        }
    }
    cout<<cnt1<<endl<<cnt2;
    return 0;
}
