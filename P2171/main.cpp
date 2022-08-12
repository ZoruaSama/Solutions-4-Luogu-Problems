#include <iostream>
#include <vector>
using namespace std;
struct node{
    int v;
    int l;
    int r;
};
vector<node> tree;
int deepest = 0;
void insert(int x){
    int deep=0;
    int now=0;
    if(tree.empty()){
        tree.push_back(node{x,-1,-1});
    }else{
        do{
            deep++;
            deepest=max(deepest,deep);
            if(x>tree[now].v){
                if(tree[now].r==-1){
                    tree.push_back(node{x,-1,-1});
                    tree[now].r=(int)tree.size()-1;
                    break;
                }else{
                    now=tree[now].r;
                }
            }else{
                if(tree[now].l==-1){
                    tree.push_back(node{x,-1,-1});
                    tree[now].l=(int)tree.size()-1;
                    break;
                }else{
                    now=tree[now].l;
                }
            }
        }while(true);
    }
}
void visit(int x){
    if(tree[x].l!=-1){
        visit(tree[x].l);
    }
    if(tree[x].r!=-1){
        visit(tree[x].r);
    }
    cout<<tree[x].v<<endl;
}
int main() {
    int n;
    cin>>n;
    int sz;
    for(int i=1;i<=n;++i){
        cin>>sz;
        insert(sz);
    }
    cout<<"deep="<<deepest+1<<endl;
    visit(0);
    return 0;
}
