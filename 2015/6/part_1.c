#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFF_SIZE 1024

void parse_nums(FILE* file_ptr, 
	        char* buff,     
		int* x1,
		int* y1, 
		int* x2, 
		int* y2)
{
    // read x1 y1
    fscanf(file_ptr, "%d,%d", x1, y1);
    // skip "through"
    fscanf(file_ptr, "%s", buff);
    // read x2 y2
    fscanf(file_ptr, "%d,%d", x2, y2);
}

int main(void)
{
    FILE* file_ptr;
    file_ptr = fopen("data.txt", "r");
    
    int field[1000][1000];
    memset(field, 0, sizeof field);
    
    char buff[1024];
    int x1, y1, x2, y2;

    int ans = 0;
    
    while (fscanf(file_ptr, "%s", buff) != EOF)
    {
	// if toggle
        if (strlen(buff) == 6)
	{
	    parse_nums(file_ptr, buff, &x1, &y1, &x2, &y2);
	    for(; x1 <= x2; x1++)
	        for(int _y = y1; _y <= y2; _y++)
                    field[x1][_y] = !field[x1][_y];

	}
	else
	{
	    fscanf(file_ptr, "%s", buff);
	    
	    if (strlen(buff) == 2)
            {
	        //ON
                parse_nums(file_ptr, buff, &x1, &y1, &x2, &y2);
		for(; x1 <= x2; x1++)
		    for(int _y = y1; _y <= y2; _y++)
		        field[x1][_y] = 1;
	    }
	    else
            {
	        //OFF
                parse_nums(file_ptr, buff, &x1, &y1, &x2, &y2);
		for(; x1 <= x2; x1++)
		    for(int _y = y1; _y <= y2; _y++)
                        field[x1][_y] = 0;
	    }
	}
    }
  
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
	    ans += field[i][j];

    printf("%d\n", ans);

    return 0;
}
