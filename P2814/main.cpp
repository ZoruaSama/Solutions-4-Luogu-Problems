#include <iostream>
#include <map>
using namespace std;
map<string,string> par;
string find(string x){
    if(par.count(x) > 0){
        return x==par[x] ? x : par[x]=find(par[x]) ;
    }else{
        return par[x]=x;
    }
}
int main() {
    char flag;
    string s1,s2;
    do{
        cin>>flag;
        if(flag=='#'){
            cin>>s1;
        }else if(flag=='+'){
            cin>>s2;
            par[find(s2)]=find(s1);
        }else if(flag=='?'){
            cin>>s2;
            cout<<s2<<' '<<find(s2)<<endl;
        }
    }while(flag!='$');

    return 0;
}
