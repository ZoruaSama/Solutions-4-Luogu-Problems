#include <stdio.h>

int main() {
    int n, m, x, y;
    int map[101][101][2] = {0};
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (register int i = 1; i <= x; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int xi = x1; xi <= x2; xi++) {
            for (int yi = y1; yi <= y2; yi++) {
                map[xi][yi][0]++;
                map[xi][yi][1] = i;
            }
        }
    }
    for (register int i = 1; i <= y; i++) {
        int xs, ys;
        scanf("%d%d", &xs, &ys);
        printf("%c ", map[xs][ys][0] > 0 ? 'Y' : 'N');
        if (map[xs][ys][0] > 0) {
            printf("%d %d", map[xs][ys][0], map[xs][ys][1]);
        }
        printf("\n");
    }
    return 0;
}
