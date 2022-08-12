#include <iostream>
bool r[10][10]={0};
bool c[10][10]={0};
bool z[10][10]={0};
int mp[10][10]={0};
using namespace std;
void dfs(int x,int y){
    if(x==9){
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                cout<<mp[i][j]<<' ';
            }
            cout<<endl;
        }
        return ;
    }
    if(y==9){
        dfs(x+1,0);
        return;
    }
    if(mp[x][y]){
        dfs(x,y+1);
    }else{
        for(int i=1;i<=9;++i){
            if(!r[x][i] && !c[y][i] && !z[x/3*3+y/3][i]){
                r[x][i] = true;
                c[y][i] =true;
                z[x/3*3+y/3][i]=true;
                mp[x][y]=i;
                dfs(x,y+1);
                mp[x][y]=0;
                r[x][i] = false;
                c[y][i] = false;
                z[x/3*3+y/3][i]=false;
            }
        }
    }

}
int main() {
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cin>>mp[i][j];
            r[i][mp[i][j]]= true;
            c[j][mp[i][j]]= true;
            z[i/3*3+j/3][mp[i][j]] = true;
        }
    }
    dfs(0,0);
    system("pause");
    return 0;
}
