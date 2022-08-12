#include <iostream>
using namespace std;
int n;
string strs[20];
int mp[20][20]={0};
int vis[20]={0};
int res=0;
void dfs(int x,int sum){
    res = max(sum,res);
    for(int i=0;i<n;i++){
        if(mp[x][i] && vis[i]<2){
            vis[i]++;
            dfs(i,sum+(int)strs[i].length()-mp[x][i]);
            vis[i]--;
        }
    }
}
int main() {
    cin>>n;
    char first;

    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string a=strs[i];
            string b=strs[j];
            int k=1;
            while(k<min(a.length(),b.length())){
                if(a.substr(a.length()-k)==b.substr(0,k)){
                    mp[i][j]=k;
                    break;
                }
                k++;
            }

        }
    }
    cin>>first;
    for(int i=0;i<n;i++){
        if(strs[i].at(0) == first){
            vis[i]++;
            dfs(i,strs[i].length());
            vis[i]--;
        }
    }
    cout<<res;
    return 0;
}
