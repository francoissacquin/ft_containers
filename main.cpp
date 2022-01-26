#include "./vector/vector.hpp"
#include <iostream>
#include <>

int main()
{
	ft::vector<int> temp;

	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(4);
	temp.resize(10);
	for (unsigned long i = 0; i < temp.size(); i++)
		std::cout << "Temp[" << i << "] = " << temp[i] << std::endl;
	return 0;
}
