#include <iostream>
using namespace std;
int n;
struct s{
    string name;
    int state; //0 UP 1DOWN 2SAME
}S[110],S_[110];
bool flag[110];
int s2i(string &x){
    if(x=="UP"){
        return 0;
    }else if(x=="DOWN"){
        return 1;
    }else{
        return 2;
    }
}
int main() {
    cin>>n;
    string ss;
    for(int i=1;i<=n;++i){
        cin>>S[i].name;
        cin>>ss;
        S[i].state=s2i(ss);
        if(S[i].state==2){
            S_[i]=S[i];
            flag[i]=true;
        }
    }
    for(int i=1;i<=n;++i){
        if(!flag[i]){
            if(S[i].state==0){
                for(int j=i+1;j<=n;++j){
                    if(!flag[j]){
                        S_[j]=S[i];
                        flag[j]=true;
                        break;
                    }
                }
            }else{
                for(int j=i-1;j>=1;--j){
                    if(!flag[j]){
                        S_[j]=S[i];
                        flag[j]=true;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        cout<<S_[i].name<<endl;
    }
    return 0;
}
