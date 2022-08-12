#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int i;
    stringstream ss;
    cin>>i;
    while(i--){
        string a;
        char m;
        cin>>a;
        if(isalpha(a[0])){
            m=a[0];
            int x,y;
            if(a[0]=='a'){
                cin>>x>>y;
                ss<<x<<'+'<<y<<'='<<x+y;

            }else if(a[0]=='b'){
                cin>>x>>y;
                ss<<x<<'-'<<y<<'='<<x-y;

            }else if(a[0]=='c'){
                cin>>x>>y;
                ss<<x<<'*'<<y<<'='<<x*y;
            }
        }else{
            int x,y;
            cin>>y;
            stringstream xx;
            xx<<a;
            xx>>x;
            if(m=='a'){
                ss<<x<<'+'<<y<<'='<<x+y;
            }else if(m=='b'){
                ss<<x<<'-'<<y<<'='<<x-y;
            }else if(m=='c'){
                ss<<x<<'*'<<y<<'='<<x*y;
            }
        }
        cout<<ss.str()<<endl;
        cout<<ss.str().length()<<endl;
        ss.clear();
        ss.str("");
    }

    return 0;
}
