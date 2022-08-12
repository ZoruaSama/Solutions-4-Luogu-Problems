#include <iostream>
#include <cstring>
using namespace std;
void sub(char a[],char b[]){
    int lena=(int) strlen(a)-1;
    int lenb=(int) strlen(b)-1;
    char c[10086];
    char k=0;
    int lenc=lena;
    while(lena>=0){
        if(lenb>=0){
            c[lena] = a[lena] - b[lenb] - k;
        }
        else{
            c[lena] = a[lena] - '0' - k;
        }
        if(c[lena]<0){
            c[lena]+=10;
            k=1;
        }else{
            k=0;
        }
        lena--;
        lenb--;
    }
    bool flag=false;
    for(int i=0;i<=lenc;i++){
        while(c[i]==0 && i<lenc && !flag) i++;
        cout<<(char)(c[i]+48);
        flag=true;
    }
}
int main() {
    char a[10086];
    char b[10086];
    cin>>a>>b;
    if(strlen(a)>=strlen(b)){
        sub(a,b);
    }else{
        cout<<'-';
        sub(b,a);
    }
    return 0;
}
