#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxnn=200000;
int a[maxnn]={0};
int re[maxnn]={0};
int m[maxnn]={0};
int n;
int hashf(int x){
    int k=0;
    while(re[(x+k)%maxnn]!=0 && re[(x+k)%maxnn]!=x){
        k+=1;
    }
    re[(x+k)%maxnn]=x;
    return (x+k)%maxnn;
}
int main() {
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>m[i];
//        cout<<"hash posi:"<<hashf(m[i])<<endl;
        a[hashf(m[i])]++;
    }
    sort(m,m+n);
    for(int i=0;i<n;++i){
        if(a[hashf(m[i])]!=0){
           cout<<m[i]<<' '<<a[hashf(m[i])]<<endl;
           a[hashf(m[i])]=0;
        }

        //cout<<hashf(m[i]);
    }
    return 0;
}
