#include <iostream>
using namespace std;
struct point{
    int x;
    int y;
    char type;
}points[1000];
int n,m;
string solve(int a,int b,int c){
    char fs='X';
    for(int i=0;i<n;++i){
        int x=points[i].x;
        int y=points[i].y;
        char type=points[i].type;
        if(fs=='X'){
            if(a+b*x+c*y<0){
                fs=type;
            }else{
                fs = (type=='A' ? 'B' : 'A');
            }
        }else{
            if(a+b*x+c*y<0 && fs=='B' && type=='A'){
                return "No";
            }else if(a+b*x+c*y<0 && fs=='A' && type=='B'){
                return "No";
            }else if(a+b*x+c*y>0 && fs=='A' && type=='A'){
                return "No";
            }else if(a+b*x+c*y>0 && fs=='B' && type=='B'){
                return "No";
            }
        }
    }
    return "Yes";
}
int main() {
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>points[i].x>>points[i].y>>points[i].type;
    }
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<solve(a,b,c)<<endl;
    }
    return 0;
}
