#include <iostream>
using namespace std;
int main() {
    int n,L,G;
    cin>>n>>L>>G;
    int w,h;
    while(n--){
        cin>>w>>h;
        while(w>G || h>G){
            w/=2;h/=2;
        }
        if(w<L || h<L){
            cout<<"Too Young"<<endl;
        }else if(w!=h){
            cout<<"Too Simple"<<endl;
        }else{
            cout<<"Sometimes Naive"<<endl;
        }
    }
    return 0;
}
