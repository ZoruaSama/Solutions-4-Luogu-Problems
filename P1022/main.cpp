#include <iostream>
#include <cstdio>
using namespace std;
bool isOp(char x){
    return x=='+' || x=='=' || x=='-'|| x=='$';
}
int main() {
    char ch;
    char m='a';
    char last='+';
    int a=0,b=0;
    int tmp=0;
    int opeq=1;
    bool opsub=false;
    while(cin>>ch){
        if(isalpha(ch)){
            if(isOp(last)){
                tmp=1;
            }
            if(opsub){
                tmp=-tmp;
                opsub=false;
            }
            a+=tmp*opeq;
            tmp=0;
            m = ch;
        }
        else if(isOp(ch)){
            if(opsub){
                tmp=-tmp;
                opsub=false;
            }
            b+=tmp*opeq*-1;
            tmp=0;
            if(ch=='-') opsub=true;
            else if(ch=='=') opeq=-1;
            else if(ch=='$') break;
        }
        else if(isdigit(ch)){
            tmp*=10;
            tmp+=ch-48;
        }
        last=ch;
    }
    if(opsub){
        tmp=-tmp;
    }
    b+=tmp*opeq*-1;
    if(b*1.0/a==0.000){
        cout<<m<<'='<<"0.000";
    }else{
        printf("%c=%.3lf",m,b*1.0/a);
    }

    return 0;
}
