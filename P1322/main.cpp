#include <iostream>
using namespace std;
string s;  //NOLINT
int position=0;
void fd(){
    int d;
    cin>>d;
    position+=d;
}
void bk(){
    int d;
    cin>>d;
    position-=d;
}
void repeat(int time){
    if(time==0) return ;

    repeat(time-1);
}
int main() {
    cin>>s;

    return 0;
}
