#include <stdio.h>
#include <string.h>

#include <string>
#include <unordered_map>

#define MAX_LINE_LENGTH 1000

int main(void) {
    FILE *file_ptr;
    file_ptr = fopen("data.txt", "r");
    
    char buff[MAX_LINE_LENGTH];
    
    int ans = 0;

    int good_triple, good_twice;

    std::unordered_map<std::string, int> tw_mp;
    std::string tw_s;

    while (fscanf(file_ptr, "%s", buff) != EOF)
    {
	tw_mp = {};
	good_triple = good_twice = 0;
        for(size_t i = 0; i < strlen(buff); i++)
	{
	    if (i < strlen(buff) - 2 && buff[i] == buff[i + 2])
	        good_triple = good_triple + 1;
            
	    if (i < strlen(buff) - 1)
            {
	        tw_s = std::string() + buff[i] + buff[i + 1];
		
		if (tw_mp.find(tw_s) == tw_mp.end())
		    tw_mp[tw_s] = i;
		else
		    if (tw_mp[tw_s] < i - 1)
		    {
		        tw_mp[tw_s] = i;
			good_twice = good_twice + 1;
		    }
	    }
	    
	}
        
	if (good_triple > 0 && good_twice > 0)
	    ans = ans + 1;
    }

    printf("%d\n", ans);

    return 0;
}
