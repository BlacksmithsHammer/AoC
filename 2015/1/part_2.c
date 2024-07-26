#include <stdio.h>
#define BUFF_SIZE 1024

int main(void) {
	char buff[BUFF_SIZE];
	int 	ans = 0,
	    	ind = 0,
		buff_ans = 0;

	FILE* file_ptr;
	file_ptr = fopen("data.txt", "r");
	while(fread(buff, sizeof(char), BUFF_SIZE, file_ptr))
	{
		for(int i = 0; i < BUFF_SIZE; i++)
		{
			if(ans < 0)
				break;
			else
				ind++;
			(buff[i] == 40) ? (ans++) : (ans--);
		}
		
	}

	printf("%d\n", ind);

	return 0;
}
