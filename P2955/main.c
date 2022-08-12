#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();    //清空掉缓存
    char a=0,b=0;
    for (int i = 0; i < n; i++) {
        do{
            b = a;
            a = getchar();
        }while(a!=10);


        printf("%s\n", (b-48)%2==0 ? "even" : "odd");
    }
    return 0;
}
