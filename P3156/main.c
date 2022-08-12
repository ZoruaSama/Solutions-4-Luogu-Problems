#include <stdio.h>

int main() {
    int n,m;
    int s[2000001];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&s[i]);
    }
    for(int i=0;i<m;++i){
        int a;
        scanf("%d",&a);
        printf("%d\n",*(s+a-1));
    }
    return 0;
}
