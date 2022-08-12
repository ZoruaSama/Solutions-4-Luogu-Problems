#include <iostream>
#include <algorithm>
using namespace std;
int s[3];

int main() {
    for(int i=0;i<3;++i){
        cin>>s[i];
    }
    sort(s,s+3);
    if(s[0]+s[1]>s[2]){
        if(s[0]*s[0]+s[1]*s[1]>s[2]*s[2]){
            cout<<"Acute triangle"<<endl;
        }else if(s[0]*s[0]+s[1]*s[1]==s[2]*s[2]){
            cout<<"Right triangle"<<endl;
        }else{
            cout<<"Obtuse triangle"<<endl;
        }
        if(s[0]==s[1] || s[1]==s[2]){
            cout<<"Isosceles triangle"<<endl;
        }
        if(s[0]==s[1] && s[1]==s[2]){
            cout<<"Equilateral triangle"<<endl;
        }
    }else{
        cout<<"Not triangle"<<endl;
    }

    return 0;
}
