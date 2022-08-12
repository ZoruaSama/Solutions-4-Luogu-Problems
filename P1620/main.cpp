#include <iostream>
using namespace std;
int main() {
    int CountO,CountX,maxO,maxX;
    while(cin>>CountO>>CountX>>maxO>>maxX){
        if(maxO==0){
            cout<<maxX;
        }else if(maxX==0){
            cout<<maxO;
        }
    }
    return 0;
}
