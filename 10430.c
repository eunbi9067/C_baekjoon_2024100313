#include <stdio.h>

int main() {
    int A, B, C;
    scanf_s("%d %d %d", &A, &B, &C);

    if (A >= 2 && A <= 10000 && B >= 2 && B <= 10000 && C >= 2 && C <= 10000) {
        int a = (A + B) % C;
        int b = ((A % C) + (B % C)) % C;
        int c = (A * B) % C;
        int d = ((A % C) * (B % C)) % C;
        printf("%d\n%d\n%d\n%d\n", a, b, c, d);
    }
    else {
        printf("A, B, C는 2 이상 10000 이하의 값이어야 합니다.\n");
    }

    return 0;
}