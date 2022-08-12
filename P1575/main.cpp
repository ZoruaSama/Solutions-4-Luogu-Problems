#include <iostream>
#include <stack>
using namespace std;
stack<int> op;   //NOLINT
stack<string> num;  //NOLINT
bool fail = false;

bool isOp(const string& x){
    return (x=="and" || x=="or" ||x=="not");
}
bool isNum(const string& x){
    return (x=="true" || x=="false");
}
string ufunc(const string& x,const string& y,int op){
    if(op==2){
        if(x=="true") return "false";
        else return "true";
    }else if(op==1){
        if(x=="true" && y=="true") return "true";
        else return "false";
    }else{
        if(x=="true" || y=="true") return "true";
        else return "false";
    }
}
void cal(){
    if(op.top()==2){
        if(num.size() < 1){
            cout<<"error";
            fail = true;
            return ;
        }
        string a = num.top();
        num.pop();
        num.push(ufunc(a,"",op.top()));
        op.pop();
    }else{
        if(num.size() < 2){
            cout<<"error";
            fail = true;
            return ;
        }
        string a = num.top();
        num.pop();
        string b = num.top();
        num.pop();
        num.push(ufunc(a,b,op.top()));
        op.pop();
    }
}
int main() {
    string exp;
    while(cin>>exp){
       if(isOp(exp)){
            int t = 0;
            if(exp=="or") {
                t=0;
            }else if(exp=="and"){
                t=1;
            }else if(exp=="not"){
                t=2;
            }
            while(!op.empty() && op.top() > t){
                cal();
                if(fail) return 0;
            }
            op.push(t);
        }else if(isNum(exp)){
            num.push(exp);
        }else{
            cout<<"error";
            return 0;
        }
    }
    while(!op.empty()){
        cal();
        if(fail) return 0;
    }
    if(num.size() == 1){
        cout<<num.top();
    }else{
        cout<<"error";
    }
    return 0;
}
