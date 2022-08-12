#include <stdio.h>

int main() {
    int a[3];
    char c1,c2;
    while (scanf("%c:=%c;",&c1,&c2)==2)
        a[c1-'a'] = c2 >='0' && c2<='9' ? c2-'0' : a[c2-'a'];
    printf("%d %d %d",a[0],a[1],a[2]);
    return 0;
}
