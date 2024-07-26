#include <iostream>
#include <fstream>
#include <set>
#include <utility>

#define BUFF_SIZE 1024

int main()
{
	std::pair<int, int> point[2];
	point[0] = {0, 0};
	point[1] = {0, 0};
	
	std::set<std::pair<int, int>> houses;

	char buff[BUFF_SIZE];
	std::ifstream file("data.txt");
	
	houses.insert(point[0]);
	houses.insert(point[1]);

	while(file.peek() != EOF)
	{
		file.read(buff, BUFF_SIZE);
		for (int i = 0; i < file.gcount(); i++)
		{
			if(buff[i] != 10)
			{
				switch(buff[i])
				{
					case '^':
					{
						point[i%2].first += 1;
						break;
					}
					case '<':
					{
						point[i%2].second += 1;
						break;
					}
					case 'v':
					{
						point[i%2].first -= 1;
						break;
					}
					case '>':
					{
						point[i%2].second -= 1;
						break;
					}
					default:
						std::cout << "unexpected case";
						return 1;
					
				}
				houses.insert(point[i%2]);
			}
		}
	}

	std::cout << houses.size() << '\n';

	return 0;
}
