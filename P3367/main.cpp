#include <iostream>
using namespace std;
int parents[10001]={0};
int find(int x){
    return x==parents[x] ? x : parents[x] = find(parents[x]);
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        parents[i]=i;
    }
    int x,y,z;
    while(m--){
        cin>>z;
        if(z==1){
            //合并两个集合为一个集合
            cin>>x>>y;
            parents[find(x)]=find(y);
        }else{
            //查找两个元素是否在一个集合里
            cin>>x>>y;
            int t1=find(x);
            int t2=find(y);
            if(t1==t2){
                cout<<'Y'<<endl;
            }else{
                cout<<'N'<<endl;
            }
        }
    }
    return 0;
}