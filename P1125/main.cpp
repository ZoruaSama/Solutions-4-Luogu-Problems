#include <iostream>
#include <algorithm>
using namespace std;
bool zs(int x){
    if(x==0 || x==1) return false;
    for(int i=2;i<x/2;++i){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
int main() {
    char ch;
    int cnt[26]={0};
    int maxn=-1,minn=2e9;
    while(cin>>ch){
        cnt[ch-'a']++;
    }
    sort(cnt,cnt+26);
    for(int i=0;i<26;++i){
        if(cnt[i]>maxn){
            maxn=cnt[i];
        }
        if(cnt[i]<minn && cnt[i]!=0){
            minn=cnt[i];
        }
    }
    if(zs(maxn-minn)){
        cout<<"Lucky Word"<<endl<<maxn-minn;
    }else{
        cout<<"No Answer"<<endl<<0;
    }
    return 0;
}
