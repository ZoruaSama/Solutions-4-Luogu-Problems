#include <stdio.h>

int main() {
    int a,b,c,d;
    int p;
    int r=0;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(int i=0;i<3;++i){
        r=0;
        scanf("%d",&p);
        if(p % (a+b)<=a && p != a+b){
            r++;
        }
        if(p % (c+d)<=c &&  p != c+d){
            r++;
        }
        if(r==2){
            printf("both\n");
        }
        else if(r==1){
            printf("one\n");
        }
        else if(r==0){
            printf("none\n");
        }
    }
    return 0;
}
