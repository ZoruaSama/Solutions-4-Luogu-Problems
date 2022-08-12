#include <iostream>
using namespace std;
int index;
int study;
int extra;
double total;
int main() {
    int n;
    cin>>n;
    while(n--){
        cin>>index>>study>>extra;
        total = 0.7*study+0.3*extra;
        if(study + extra>140 && total >=80){
            cout<<"Excellent"<<endl;
    }else{
            cout<<"Not excellent"<<endl;
        }
    }
    return 0;
}
