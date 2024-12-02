# include <stdio.h>

int main() {
	int A, B;
	scanf_s("%d %d", &A, &B);
	int a = A + B;
	int b = A - B;
	int c = A * B;
	int d = A / B;
	int e = A % B;
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);
}