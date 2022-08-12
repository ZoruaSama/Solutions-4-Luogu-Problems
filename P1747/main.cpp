#include <iostream>
#include <queue>
using namespace std;
queue<int> xp;   // NOLINT
queue<int> yp;   // NOLINT
queue<int> t; // NOLINT
bool vis[21][21]={false};
int main() {
    int ox,oy;
    for(int k=1;k<=2;++k){
        cin>>ox>>oy;
        int xx[]={+2,+2,+1,+1,-2,-2,-1,-1,+2,-2,+2,-2};
        int yy[]={+1,-1,+2,-2,+1,-1,+2,-2,+2,-2,-2,+2};
        xp.push(ox);
        yp.push(oy);
        t.push(0);
        while(!xp.empty()){
            if(xp.front()==1 && yp.front()==1){
                cout<<t.front()<<endl;
                while (!xp.empty()) xp.pop();
                while (!yp.empty()) yp.pop();
                while (!t.empty()) t.pop();
                for(int i=1;i<=20;i++){
                    for(int j=1;j<=20;j++){
                        vis[i][j]=false;
                    }
                }
                break;
            }
            for(int i=0;i<12;++i){ //NOLINT
                int nx=xp.front()+xx[i];
                int ny=yp.front()+yy[i];
                int nt=t.front()+1;
                if(nx>0 && ny>0 && nx<=20 && ny<=20 && !vis[nx][ny]){
                    vis[nx][ny]=true;
                    xp.push(nx);
                    yp.push(ny);
                    t.push(nt);
                }
            }
            xp.pop();
            yp.pop();
            t.pop();
        }
    }
    return 0;
}
