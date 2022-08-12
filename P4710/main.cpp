#include <iostream>
#include <cmath>
using namespace std;
int main() {
    const double g = 10.0;
    double v,theta,t,x,y;
    cin>> v>>theta;
    t = v*cos(theta)/g;
    x = v*sin(theta)*t;
    y = 0.5*g*pow(t,2.0);
    cout << x<< " "<<y << endl;
    return 0;
}
