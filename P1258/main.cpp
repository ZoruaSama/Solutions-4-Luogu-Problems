#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double s,a,b;
    cin>>s>>a>>b;
    double x=(b+a)*s/(b+3*a);
    cout<<fixed<<setprecision(6)<<x/b+(s-x)/a;
    return 0;
}
