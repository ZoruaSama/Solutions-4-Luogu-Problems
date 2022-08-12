#include <iostream>
#include <vector>
using namespace std;
int x1,y1,x2,y2;
long long f[25][25]={0};
int a[25][25]={0};
void reset(){
    a[x2][y2]=1;
    if(x2>=2 && y2>=1)
        a[x2-2][y2-1]=1;
    if(x2>=1 && y2>=2)
        a[x2-1][y2-2]=1;
    if(x2>=2)
        a[x2-2][y2+1]=1;
    if(x2>=1)
        a[x2-1][y2+2]=1;
    if(y2>=2)
        a[x2+1][y2-2]=1;
    if(y2>=1)
        a[x2+2][y2-1]=1;
    a[x2+1][y2+2]=1;
    a[x2+2][y2+1]=1;
}
int main() {
    cin>>x1>>y1>>x2>>y2;
    reset();
    // f[i][j] = f[i-1][j]+f[i][j-1]
    // f[0][0] = 1
    for(int i=0;i<=x1;++i){
        for(int j=0;j<=y1;++j){
            if(a[i][j]){
                f[i][j] = 0;
            }
            else if(i==0 && j==0) {
                f[i][j] = 1;
            }
            else if(i==0) {
                f[i][j] = f[i][j-1];
            }
            else if(j==0) {
                f[i][j] = f[i-1][j];
            }
            else {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
    }

    cout<<f[x1][y1];

    return 0;
}


/*
 *
#include <iostream>
#include <vector>
using namespace std;
class Point{
private:
    int x;
    int y;
public:
    Point(int xx,int yy):x{xx},y{yy}{  }

    bool operator==(const Point &other){
        return this->x == other.x && this->y == other.y;
    }
};
int main() {
    int x1,y1,x2,y2;
    int f[21][21]={0};
    vector<Point> horse;
    cin>>x1>>y1>>x2>>y2;
    horse.emplace_back(x2,y2);
    horse.emplace_back(x2-1,y2+2);
    horse.emplace_back(x2-2,y2+1);
    horse.emplace_back(x2+1,y2+2);
    horse.emplace_back(x2+2,y2+1);
    horse.emplace_back(x2+1,y2-2);
    horse.emplace_back(x2+2,y2-1);
    horse.emplace_back(x2-1,y2-2);
    horse.emplace_back(x2-2,y2-1);

    // f[i][j] = f[i-1][j]+f[i][j-1]
    // f[x1][y1] = 1
    for(int i=0;i<=x1;++i){
        f[i][0]=1;
    }
    for(int j=1;j<=y1;++j) {
        f[0][j]=1;
    }
    int i,j;
    for(i=1;i<=x1;++i){
        for(j=1;j<=y1;++j){
            bool flag=false;
            for(auto x:horse){
                if(Point(i,j) == x)
                    flag=true;
            }
            if(!flag)
                f[i][j] = f[i-1][j]+f[i][j-1];
        }
    }

    cout<<f[x1][y1];

    return 0;
}

 *
 *
 *
 *
 * */