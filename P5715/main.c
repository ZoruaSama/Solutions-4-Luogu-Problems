#include <stdio.h>
int* min(int* a,int* b,int* c){
    if(*a<=*b && *a<=*c){
        return a;
    }
    else if(*b<=*a && *b<=*c){
        return b;
    }
    else if(*c<=*a && *c<=*b){
        return c;
    }
}
int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d ",*(min(&a,&b,&c)));
    *(min(&a,&b,&c)) = 101;
    printf("%d ",*(min(&a,&b,&c)));
    *(min(&a,&b,&c)) = 101;
    printf("%d ",*(min(&a,&b,&c)));
    *(min(&a,&b,&c)) = 101;
    return 0;
}
