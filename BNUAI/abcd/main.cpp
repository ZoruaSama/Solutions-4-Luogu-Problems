#include <iostream>
using namespace std;
int id=0;
int bsum(int n){//返回二进制一的个数 注意类型
    int count=0;
    unsigned int flag=1;//flag从1开始 每次循环左移一位 与n做&运算 判断该位是否为1
    while(flag<=n){  //flag大于n 退出循环
        if(n&flag)
            count++;
        flag=flag<<1;
    }
    return count;
}

void f(string s,int n,int a,int b,int c,int d,int as,int bs,int cs,int ds,int last,int rep,bool mst_chg,int grp){
    if(as>6 || bs>6 || cs>6 || ds>6 || rep > 3){
        return ;
    }
    if(n!=1 && n%5==1){
        s+=" ";
//        mst_chg=true;
        if(bsum(grp)<3) return;
    }
    if(n==21){
        cout<<++id<<"  "<<s<<endl;
    }
    if(!(mst_chg && last=='A')) f(s+"A",n+1,a-1,b,c,d,as+1,bs,cs,ds,'A',rep+(last=='A'),last=='A',grp|1);
    if(!(mst_chg && last=='B')) f(s+"B",n+1,a,b-1,c,d,as,bs+1,cs,ds,'B',rep+(last=='B'),last=='B',grp|2);
    if(!(mst_chg && last=='C')) f(s+"C",n+1,a,b,c-1,d,as,bs,cs+1,ds,'C',rep+(last=='C'),last=='C',grp|4);
    if(!(mst_chg && last=='D')) f(s+"D",n+1,a,b,c,d-1,as,bs,cs,ds+1,'D',rep+(last=='D'),last=='D',grp|8);
}
int main() {
    f("",1,6,6,6,6,0,0,0,0,0,0,false,0);
//    f("ADCBD DCAAB",11,3,4,4,3,3,2,2,3,0,1,false,100);
    return 0;
}
