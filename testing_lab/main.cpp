#include <vector>
#include <iostream>

int		main()
{
	std::vector<int> temp;

	temp.pop_back();
	temp.pop_back();
	std::cout << "Temp = " << temp[0] << std::endl;
	return (0);
}
