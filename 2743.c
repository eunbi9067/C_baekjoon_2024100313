#include <stdio.h>
#include <string.h>
int main() {
	char s[101];
	scanf_s("%s", s);
	printf("%d", strlen(s));
	return 0;
}