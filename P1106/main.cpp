#include <iostream>
#include <algorithm>
using namespace std;
string n; //NOLINT
bool flag[251]={false};
int k;
int main() {
    cin>>n>>k;
    k=(int)n.length()-k;
    int mini=0;
    while(k--){
        int minn=58;
        //8
        //3
        //[123456]78 8-2
        //[1234567]8 8-1
        for(int i=mini;i<n.length()-k;++i){
            if(minn>n[i] && !flag[i]){
                minn=n[i];
                mini=i;
            }
        }
        flag[mini]=true;
    }
    int zero=0;
    for(zero=0;zero<(int)n.length();++zero){
        if(flag[zero] && n[zero]!='0'){
            break;
        }
    }
    if(!flag[zero]){
        cout<<0;
        return 0;
    }
    for(int i=zero;i<(int)n.length();++i){
        if(flag[i]){
            cout<<n[i];
        }
    }
    return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;
string n; //NOLINT

bool flag[251]={false};
int weight[251];
int k;
int main() {
    cin>>n>>k;
    for(int i=0;i<n.length();++i){
        int num = n[i]-48;
        weight[i]=((int)n.length()-i+1)*(num)*(num);
    }
    while(k--){
        int maxn=0;
        int maxi=0;
        for(int i=0;i<n.length();++i){
            if(weight[i]>maxn){
                maxn=weight[i];
                maxi=i;
                weight[i]=0;
            }
        }
        flag[maxi]=true;
    }
    for(int i=0;i<n.length();++i){
        if(!flag[i]){
            cout<<n[i];
        }
    }
    return 0;
}



 */