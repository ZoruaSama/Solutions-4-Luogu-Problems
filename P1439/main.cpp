#include <iostream>
#include <vector>
using namespace std;
int me[100001]={0};
int rs[100001]={0};

int main() {
    int n,ch;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>ch;
        me[ch]=i;
    }
    for(int i=1;i<=n;++i){
        cin>>ch;
        rs[i]=me[ch];
    }
    // 贪心+二分 解LIS
    // 对于一个上升子序列，其结尾元素越小，越有利于在后面接其他的元素，也就越可能变得更长。
    vector<int> tail(n+1,0); //表示长度为i的所有最长子序列结尾的最小值
    //具体地，每次来一个新的数num，利用二分找到最后一个小于num的位置l，然后让tail[l+1]=num，
    // 这样新的数有更多可能性接在tail[l+1]的后面
    for(int i=1;i<=n;++i){
        cout<<rs[i]<<' ';
    }
    cout<<endl;
    int len=0;
    for(int i=1;i<=n;++i){

        int x=rs[i];
        int l=0,r=len;
        while(l<r){  //二分查找最后一个小于num的位置
            int mid = (l+r+1)>>1; //NOLINT
            if(tail[mid] < x) l=mid; //这里是mid
            else r=mid-1; //注意这里是mid-1
        }
        tail[l+1]=x; //tail[l+1]>=x 更新成x
        len=max(len,l+1);
        for(int j=1;j<=n;++j){
            cout<<tail[j]<<' ';
        }
        cout<<endl;
    }



    cout<<len;
    return 0;
}


/*
int n;
    cin>>n;
    int ch;
    for(int i=0;i<n;++i){
        cin>>ch;
        a.push_back(ch);
    }
    for(int i=0;i<n;++i){
        cin>>ch;
        b.push_back(ch);
    }
    for(int i=0;i<a.size();++i){
        for(int j=0;j<b.size();++j){
            if(a[i]==b[j]){
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            }else{
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    cout<<f[a.size()-1][b.size()-1];
*/