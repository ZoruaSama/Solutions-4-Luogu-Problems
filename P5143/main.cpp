#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;
struct point{
    double x;
    double y;
    double z;
}points[50000];
double distance(struct point a,struct point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
bool cmp(struct point a,struct point b){
    return a.z < b.z;
}
inline int read()
{
    char c=(char)getchar();
    int x=0,fs=1;
    while(!isdigit(c)){if(c=='-')fs=-1;c=(char)getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=(char)getchar(); //NOLINT
    return x*fs;
}

void write(int a)
{
    if(a<0) putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar(a%10+48);
}
int main() {
    int n;
    double sum=0;
    n=read();
    for(int i=0;i<n;++i){
        points[i].x = read();
        points[i].y = read();
        points[i].z = read();
    }
    sort(points,points+n,cmp);
    for(int i=0;i<n-1;++i){
        sum+=distance(points[i+1],points[i]);
    }
    cout<<setprecision(3)<<fixed<<sum;
    return 0;
}
