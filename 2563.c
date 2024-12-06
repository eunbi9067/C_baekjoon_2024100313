#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int paper[100][100] = { 0, };
    int n, x, y = 0;
    int cnt = 0;

    scanf_s("%d", &n); 

    for (int i = 0; i < n; i++) {
        scanf_s("%d %d", &x, &y); 
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                paper[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (paper[i][j] == 1) {
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}