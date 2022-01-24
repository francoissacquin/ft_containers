#include <vector>
#include <iostream>

int		main()
{
	std::vector<int> temp;
	std::allocator<int> temp_alloc;

	std::cout << temp_alloc.max_size() << std::endl;
	temp.push_back(2);
	std::cout << "Temp[0] = " << temp[0] << std::endl;
	return (0);
}
