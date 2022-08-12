#include <iostream>
using namespace std;
int ss[100001]={0};
int pushed[100001];
int p = -1;
int q,n;
int main() {
    cin>>q;
    while(q--){
        p=-1;
        cin>>n;
        int a;
        for(int i=0;i<n;++i){
            cin>>pushed[i];
        }
        for(int i=0,j=0;i<n;++i){
            cin>>a;
            while(p==-1 || ss[p]!=a){
                if(j==n){
                    p++;
                    break ;
                }
                ss[++p]=pushed[j++];
            }
            p--;
        }
        if(p==-1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
