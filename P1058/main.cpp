#include <iostream>
using namespace std;
char cube[10][10]={"  +---+",
                   " /   /|",
                   "+---+ |",
                   "|   | +",
                   "|   |/",
                   "+---+",};
int main() {
    int m,n;
    cin>>m>>n;
    int mp[51][51];
    int pic[551][551];
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
        }
    }


    return 0;
}
