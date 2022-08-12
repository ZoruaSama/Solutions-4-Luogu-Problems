#include <iostream>
#include <vector>
using namespace std;
struct file{
    string name;
    int tm;
    bool exi;
};
vector <file> files;
int find_f(string name){
    for(int i=0;i<files.size();++i){
        if(files[i].name == name){
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    string cm;
    string p;
    cin>>n;
    for(int t=1;t<=n;t++){
        cin>>cm;
        if(cm=="touch"){
            cin>>p;
            if(find_f(p)==-1){
                files.push_back(file{p,t,true});
            }
        }else if(cm=="rm"){
            cin>>p;
            int res = find_f(p);
            if(res!=-1){
                files[res].exi=false;
            }
        }else if(cm=="ls"){
            for(int i=0;i<files.size();++i){
                if(files[i].exi) cout<<files[i].name<<endl;
            }
        }else if(cm=="rename"){
            cin>>p;
            int res=find_f(p);
            if(res==-1){
                cin>>p;
                continue;
            }
            cin>>p;
            int res_=find_f(p);
            if(res_!=-1) continue;
            files[res].name=p;
        }else{
            t--;
        }
    }

    return 0;
}
