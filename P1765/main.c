#include <stdio.h>

int main() {
    char s[201];
    char b[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    gets(s);
    int i = -1;
    int sum = 0;
    while (s[++i] != '\0') {
        if (s[i] - 'a' >= 0) {
            sum += b[s[i] - 'a'];
        }
        if (s[i] == ' ') {
            sum++;
        }

    }
    printf("%d", sum);
    return 0;
}
