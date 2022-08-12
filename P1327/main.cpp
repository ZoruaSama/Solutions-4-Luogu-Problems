#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> F;
int cnt=0;
int main() {
    int n;
    int a[100001];
    int b[100001];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        b[i]=a[i];
        F[a[i]]=i;  //记录每个元素当前位置
    }
    sort(b,b+n);
    for(int i=0;i<n;++i){
        if(a[i]!=b[i]){
             cnt++;
             int x=F[b[i]]; //被替换元素所处的位置
             F[a[i]]=x;     //换成被替换元素所处的位置
             a[x]=a[i];     //被替换的元素挪到对应位置
        }
    }
    cout<<cnt;
    return 0;
}