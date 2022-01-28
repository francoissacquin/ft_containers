#include <vector>
#include <iostream>

int		main()
{
	std::vector<int> temp(0);
	//std::allocator<int> temp_alloc;

	
	temp.push_back(10);
	temp.push_back(20);
	temp.push_back(30);
	temp.resize(10, 40);
	for (unsigned long i = 0; i < temp.size(); i++)
		std::cout << "Temp[" << i << "] = " << temp[i] << std::endl;

	std::cout << std::endl;

	std::vector<int>::iterator ptr = temp.begin();
	std::cout << *ptr << std::endl;
	*ptr++ = 25;
	std::cout << *ptr << std::endl;
	for (unsigned long i = 0; i < temp.size(); i++)
		std::cout << "Temp[" << i << "] = " << temp[i] << std::endl;
	return (0);
}
