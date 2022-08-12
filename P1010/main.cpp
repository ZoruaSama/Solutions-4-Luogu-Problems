#include <iostream>
using namespace std;

string bin(int x){
    int a=0;
    unsigned int b = 1;
    string res("");  //NOLINT
    string opplus="+";   //NOLINT
    bool flag = false;
    if(x==0) return "0";
    else if(x==1) return "";
    else {
            while(x>=b){
                if(res.empty()){
                    opplus="";
                }else{
                    opplus="+";
                }
                if((x&b)==b){  //NOLINT
                    if(a!=1){
                            res="2("+bin(a)+")"+opplus+res;  //NOLINT
                    }
                    else{
                            res="2"+opplus+res;  //NOLINT
                    }
                }
                b=b<<1; //NOLINT
                a++;
            }
        }
        return res;
}

int main() {
    int n;
    cin>>n;
    cout<<bin(n);
    return 0;
}
