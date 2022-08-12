#include <iostream>
#include <vector>
using namespace std;
vector<int> num;
void dfs(int x,int last){
    if(x==0){
        if(num.size() == 1){
            return ;
        }
        for(int i=0;i<num.size();++i){
            cout<<num[i];
            if(i!=num.size()-1){
                cout<<'+';
            }
        }
        cout<<endl;
        return ;
    }else{
        for(int i=last;i<=x;i++){
            num.push_back(i);
            dfs(x-i,i);
            num.pop_back();
        }
    }

}
int main() {
    int n;
    cin>>n;
    dfs(n,1);
    return 0;
}
