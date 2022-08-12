#include <iostream>
#include <math.h>
#include <queue>
#include <map>
using namespace std;
char mp[3][3]={0};
int sw[]={-1,+1,-3,+3};
//变化规则有误
queue<int> state; //NOLINT
queue<int> position; //NOLINT
queue<int> t; //NOLINT
map<int,int> record; //NOLINT
int zero(int num){
    int a=1;
    while(num!=0){
        if(num%10==0){
            return a;
        }
        a++;
        num/=10;
    }
    return a;
}
int change(int num,int a,int b){
    int n=((num/(int)pow(10,a-1))%10);
    num-= n*(int)pow(10,a-1);
    num+= n*(int)pow(10,b-1);
    return num;
}
int s;
void prt(int num){
    if(num==s){return ;}
    prt(record[num]);
    cout<<record[num]<<endl;
}
int main() {

    cin>>s;
    state.push(s);
    position.push(zero(s));
    t.push(0);
    record[s]=true;
    while(!state.empty()){
        if(state.front()==123804765){
            //prt(123804765);
            cout<<t.front();
            return 0;
        }
        for(int i=0;i<4;++i){  //NOLINT
            int np = position.front()+sw[i];
            if(i==0||i==1){
                if((np-1)/3 != (position.front()-1)/3){
                    continue;
                }
            }
            if(np>=1 && np<=9){
                int ns = change(state.front(),np,position.front());
                if(!record.count(ns)){
                    record[ns]=state.front();
                    state.push(ns);
                    position.push(np);
                    t.push(t.front()+1);
                }
            }
        }
        state.pop();
        position.pop();
        t.pop();
    }
    return 0;
}
