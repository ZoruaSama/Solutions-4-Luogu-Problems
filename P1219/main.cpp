#include <iostream>


using namespace std;
int n,count=0;
bool column[15]={0},u[30]={0},v[30]={0};
int path[20];
void dfs(int level){
    if(level > n)
    {
        if(count < 3){
            for(int i=1;i<=n;++i){
                cout<<path[i]<<' ';
            }
            cout<<endl;
        }
        count++;
        return ;
    }
    else{
        for(int j=1;j<=n;++j){
            if(!column[j] && !u[j-level+n] && !v[j+level]){
                column[j]=true;
                u[j-level+n]=true;
                v[j+level]=true;
                path[level]=j;
                dfs(level+1);
                column[j]=false;
                u[j-level+n]=false;
                v[j+level]=false;
            }

        }
    }

}
int main() {
    cin>>n;
    dfs(1);
    cout<<count;
    return 0;
}