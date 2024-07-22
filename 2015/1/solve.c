#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char 	buff[40];
	int 	ans = 0,
		buff_ans = 0,
		len = 0;

	FILE* file_ptr;
	file_ptr = fopen("data.txt", "r");
	while (len = fread(buff, sizeof(char), 40, file_ptr))
	{
		buff_ans = 0;

		for (int i = 0; i < len; i++)
			buff_ans += buff[i];

		ans = ans + len - buff_ans % 40 - buff_ans % 40;
	}

	printf("%d", ans);

	return 0;
}
