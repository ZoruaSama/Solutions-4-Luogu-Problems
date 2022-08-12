#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
int main(){
    for(int i=1;i<=100;++i){
        system("data.exe > in.txt");
        system("code.exe < in.txt > stdout.txt");
        system("P5788.exe < in.txt > myout.txt");
        if(system("fc stdout.txt myout.txt")){
            cout<<"WA"<<endl;
            system("pause");
        }else{
            cout<<"AC"<<endl;
        }
    }
    system("pause");
    return 0;
}