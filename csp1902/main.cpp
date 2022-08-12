#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<int, int> u;

int main() {
    int n,a,b;
    long long  sum=0;
    cin>>n>>a>>b;
    for(int i=0;i<a;++i){
        int index,value;
        cin>>index>>value;
        u[index]=value;
    }
    for(int i=0;i<b;++i){
        int index,value;
        cin>>index>>value;
        if(u.count(index)==1){
            sum+=value*u[index];
        }
    }
    cout<<sum;
    return 0;
}
