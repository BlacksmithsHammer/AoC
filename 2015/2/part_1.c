#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* file_ptr = fopen("data.txt", "r");

	int a, b, c, s1, s2, s3, ans = 0;

	while (fscanf(file_ptr, "%dx%dx%d\n", &a, &b, &c) == 3) {
		s1 = 2 * a * b;
		s2 = 2 * b * c;
		s3 = 2 * a * c;
		ans += s1 + s2 + s3;

		if (s1 <= s2 && s1 <= s3)
			ans = ans + s1 / 2;
		else
			if (s2 <= s1 && s2 <= s3)
				ans = ans + s2 / 2;
			else
				if (s3 <= s1 && s3 <= s2)
					ans = ans + s3 / 2;
	}

	printf("%d", ans);

	return 0;
}