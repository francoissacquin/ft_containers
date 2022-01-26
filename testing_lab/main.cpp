#include <vector>
#include <iostream>

int		main()
{
	std::vector<std::string> temp(1);
	//std::allocator<int> temp_alloc;

	
	temp.push_back("a");
	temp.push_back("b");
	temp.push_back("c");
	temp.resize(10, "w");
	for (unsigned long i = 0; i < temp.size(); i++)
		std::cout << "Temp[" << i << "] = " << temp[i] << std::endl;
	return (0);
}
