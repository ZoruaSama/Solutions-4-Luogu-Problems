#include <iostream>
using namespace std;
int n;
char c[110];
string s1[]={"XXX","..X","XXX","XXX","X.X","XXX","XXX","XXX","XXX","XXX"};
string s2[]={"X.X","..X","..X","..X","X.X","X..","X..","..X","X.X","X.X"};
string s3[]={"X.X","..X","XXX","XXX","XXX","XXX","XXX","..X","XXX","XXX"};
string s4[]={"X.X","..X","X..","..X","..X","..X","X.X","..X","X.X","..X"};
string s5[]={"XXX","..X","XXX","XXX","..X","XXX","XXX","..X","XXX","XXX"};
string* s[]={s1,s2,s3,s4,s5};
int main() {
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>c[i];
    }
    for(int i=0;i<=4;++i){
        for(int j=1;j<=n;++j){
            cout<<s[i][c[j]-'0'];
            if(j!=n) cout<<".";
        }
        cout<<endl;
    }
    return 0;
}
