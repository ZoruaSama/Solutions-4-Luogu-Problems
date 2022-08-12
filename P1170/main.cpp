#include <iostream>
#include <cstdlib>
using namespace std;
bool isrp(int a, int b) {
    if( (a == 0 || b == 0)&&(a!=b)){
        return false;
    }
    if (a == 1 || b == 1)
        return true;
    while (true) {
        int t = a % b;
        if (t == 0) {
            break;
        } else {
            a = b;
            b = t;
        }
    }
    return b <= 1;
}

int main() {
    int n;
    int ax,ay,bx,by;
    cin>>n;
    while(n--){
        cin>>ax>>ay>>bx>>by;
        if(isrp(abs(ax-bx),abs(ay-by))){
            cout<<"no"<<endl;
        }else{
            cout<<"yes"<<endl;
        }

    }
    return 0;
}
