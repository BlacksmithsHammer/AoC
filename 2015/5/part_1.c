#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(void) {
    FILE *file_ptr;
    file_ptr = fopen("data.txt", "r");
    
    char buff[MAX_LINE_LENGTH];
    
    int ans = 0;

    int vowels, good_twice, bad_twice;

    while (fscanf(file_ptr, "%s", buff) != EOF)
    {
	vowels = good_twice = bad_twice = 0;
        for(size_t i = 0; i < strlen(buff); i++)
	{
            if (buff[i] == 'a' || 
	        buff[i] == 'e' || 
		buff[i] == 'i' || 
		buff[i] == 'o' || 
		buff[i] == 'u')
            {
	        vowels = vowels + 1;
	    }

	    if (i < strlen(buff) - 1)
            {
	        if (buff[i] == buff[i + 1])
		    good_twice = good_twice + 1;
	    
	        if (buff[i] == 'a' && buff[i + 1] == 'b' ||
                    buff[i] == 'c' && buff[i + 1] == 'd' ||
		    buff[i] == 'p' && buff[i + 1] == 'q' ||
                    buff[i] == 'x' && buff[i + 1] == 'y')
		    bad_twice = bad_twice + 1;
	    }
	}
        
	if (vowels > 2 && good_twice > 0 && bad_twice == 0)
	    ans = ans + 1;
    }

    printf("%d\n", ans);

    return 0;
}
