#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
map<int, bool> store;
int main() {
    int n;
    cin>>n;
    while(n--){
        int c,x;
        cin>>c;
        cin>>x;
        if(c==1){
            if(store.count(x)==1){
                cout<<"Already Exist"<<endl;
            }else{
                store[x]=true;
            }
        }else{
            if(store.empty()){
                cout<<"Empty"<<endl;
            }else{
                int delta=2e9;
                int re=0;
                for(map<int,bool>::iterator it=store.begin();it!=store.end();it++){
                    if(delta>abs(x-it->first)){
                        delta=abs(x-it->first);
                        re = it->first;
                    }
                }
                store.erase(re);
                cout<<re<<endl;
            }
        }
    }
    return 0;
}
