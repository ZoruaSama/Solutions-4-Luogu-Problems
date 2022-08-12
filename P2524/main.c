#include <stdio.h>
#include <string.h>

void cal(char *array);

int main() {
    char a;  //1<=N<=9
    char b[11];
    int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    scanf("%d", &a);
    scanf("%s", b);
    int rank = 0;
    for (int i = 0; i < strlen(b); i++) {
        //康托展开
        int count = 0;
        for (int j = i + 1; j < strlen(b); j++) {
            if (b[j] < b[i]) {
                count += 1;
            }
        }
        rank += count * fac[strlen(b) - i - 1];
    }

    printf("%d", rank+1);
    return 0;
}