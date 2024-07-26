#include <stdio.h>

void swap(int* a, int* b);

void swap(int* a, int* b){
	if(*a != *b)
	{
		*a = *a^*b;
		*b = *a^*b;
		*a = *b^*a;
	}
}
int main() {
	FILE* file_ptr = fopen("data.txt", "r");

	int a, b, c, ans = 0;

	while (fscanf(file_ptr, "%dx%dx%d\n", &a, &b, &c) == 3) {
		if(a > b) swap(&a, &b);
		if(b > c) swap(&b, &c);
		if(a > b) swap(&a, &b);

		ans += a + a + b + b + a * b * c;
	}

	printf("%d\n", ans);

	return 0;
}
