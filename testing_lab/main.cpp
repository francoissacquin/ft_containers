#include <vector>
#include <iostream>

int		main()
{
	std::vector<int> temp(0);
	std::allocator<int> temp_alloc;
	std::vector<int>::iterator	it;

	for (int i = 1; i <= 10; i++)
	{
		temp.push_back(i * 10);
	}
	temp.insert(temp.end(), 2);
	it = temp.begin();

	//TESTING INSERT WITH > _MAX_SIZE
	//std::cout << temp_alloc.max_size() << std::endl;
	//temp.insert(it, 2305843009213693953, 0);

	//TESTING DESTROY WITH THE ALLOCATOR
	//temp_alloc.destroy(&(temp[4]));
	temp_alloc.construct(&(temp[4]), 2);
	//temp.erase(temp.begin() + 3);
	//temp.pop_back();

	// DISPLAYING TEMP VECTOR
	for (unsigned long i = 0; i < temp.size(); i++)
		std::cout << "Temp[" << i << "] = " << temp[i] << std::endl;

	std::cout << std::endl;

	//TESTING ITERATOR DEREFERENCING
	std::vector<int>::iterator ptr = temp.begin();
	std::cout << *ptr << std::endl;
	*ptr++ = 25;
	std::cout << *ptr << std::endl;
	for (unsigned long i = 0; i < temp.size(); i++)
		std::cout << "Temp[" << i << "] = " << temp[i] << std::endl;
	return (0);
}

// int main()

// {

//     std::vector<char> vtr = {'P', 'Q', 'R', 'S', 'T', 'U'};

 

//     for (std::vector<char>::iterator it = vtr.begin(); it != vtr.end(); it++)

//         std::cout << *it << ' ';

//     std::cout << std::endl;

// 	std::cout << vtr.capacity() << " et " << vtr.size() << std::endl;

// 	std::vector<char>::iterator ite = vtr.begin();
 

//     vtr.clear();

// 	std::cout << vtr.capacity() << " et " << vtr.size() << std::endl;

//     for (std::vector<char>::iterator it = vtr.begin(); it != vtr.end(); it++)

//         std::cout << *it << ' ';

//     std::cout << std::endl;

 

//     return 0;

// }

