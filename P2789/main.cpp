#include <iostream>
using namespace std;
int n;
bool m[25*25];
int ans;
void cal(int s,int now){
    if(s==0){
        if(!m[now]){
            ans++;
            m[now]=true;
        }
    }else {
        for(int i=1;i<=s;++i){
            cal(s-i,now+i*(n-i));
        }
    }
}
//对p条直线分情况讨论平行线的条数，已知在有r条平行线时有（p-r）条线与他们相交于p*（p-r）个交点，再加上对于这p-r条线的交点的相交组合即可！！！
int main() {
    cin>>n;
    cal(n,0);
    cout<<ans;
    return 0;
}
