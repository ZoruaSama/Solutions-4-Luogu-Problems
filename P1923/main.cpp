#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5000000;
int a[maxn];
int partition(int p,int r,int x){
    int i=p,j=r+1;
    int u = a[x];
    while(true){
        while(a[++i]<u&&i<r);
        while(a[--j]>u);
        if(i>=j){
            break;
        }
        swap(a[i],a[j]);
    }
    a[p]=a[j];
    a[j]=a[x];
    return j;
}
int select(int p,int r,int k){
    if(r-p<75){
        sort(a+p,a+r);
        return a[p+k];
    }else{
        for(int z=0;z<=(r-p-4)/5;z++){
            int x = select(p,p+(r-p-4)/5,(r-p-4)/10);
            int i=partition(p,r,x);
            int j=i-p+1;
            if(k<=j){
                return select(p,i,k);
            }
            else{
                return select(i+1,r,k-j);
            }
        }
    }
    return 0;
}
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    cout<<select(0,n-1,k);
    return 0;
}