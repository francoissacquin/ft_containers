#include "../set.hpp"
#include "../map/pair.hpp"
#include <set>
#include <iterator>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

void	print_set(set<int> x)
{
	set<int>::iterator		it = x.begin();
	set<int>::iterator		ite = x.end();

	if (it == ite)
		std::cout << "set is empty :c" << std::endl;
	while (it != ite)
	{
		std::cout << "key = " << *it << std::endl;
		++it;
	}
}

void	print_iterators(set<int>::iterator it, set<int>::iterator ite)
{
	if (it == ite)
		std::cout << "Both iterators given point to the same value" << std::endl;
	while (it != ite)
	{
		std::cout << "key = " << *it << std::endl;
		++it;
	}
}

int main()
{
	{
		std::cout << "Constructors : " << std::endl;
		set<int>		test;
	
		test.insert(1);
		test.insert(2);
		test.insert(3);
		test.insert(4);

		set<int>		test_2(test.begin(), test.end());
		set<int>		test_3(test);
		print_set(test);
		print_set(test_2);
		print_set(test_3);
	}
	{
		std::cout << "Operator = : " << std::endl;
		set<int>		test;

		test.insert(1);
		test.insert(2);
		test.insert(3);
		test.insert(4);

		set<int>		test_2;

		print_set(test_2);
		test_2 = test;
		print_set(test_2);
	}
	{
		std::cout << "Iterators : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 10; i++)
		{
			test.insert(i * 2);
		}
		print_set(test);
		std::cout << "begin key = " << *(test.begin()) << std::endl;
		std::cout << "--end key = " << *(--(test.end())) << std::endl;
		std::cout << "rbegin key = " << *(test.rbegin()) << std::endl;
		std::cout << "--rend key = " << *(--(test.rend())) << std::endl;
	}
	{
		std::cout << "Empty : " << std::endl;
		set<int>		test;

		std::cout << "Is set empty? " << test.empty() << std::endl;
		test.insert(8);
		std::cout << "Is set empty? " << test.empty() << std::endl;
		test.clear();
		std::cout << "Is set empty? " << test.empty() << std::endl;
	}
	{
		std::cout << "Size : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 10; i++)
		{
			test.insert(i * 2);
		}
		std::cout << "set size = " << test.size() << std::endl;
		test.clear();
		std::cout << "set size = " << test.size() << std::endl;
		test.insert(1);
		test.insert(2);
		test.insert(3);
		std::cout << "set size = " << test.size() << std::endl;
	}
	{
		std::cout << "Max_Size : " << std::endl;
		set<int>		test;

		std::cout << test.max_size() << std::endl;
	}
	{
		std::cout << "Insert : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 30; i++)
		{
			test.insert(i * 2);
		}
		print_set(test);
		test.insert(test.begin(), 123);
		test.insert(test.begin(), 456);
		test.insert(test.begin(), -34);
		print_set(test);
		set<int>		test_2;
		test_2.insert(test.begin(), test.end());
		print_set(test_2);
	}
	{
		std::cout << "Erase : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 15; i++)
		{
			test.insert(i * 2);
		}
		print_set(test);
		test.erase(test.begin());
		test.erase(++(test.begin()));
		print_set(test);
		test.erase(16);
		test.erase(24);
		print_set(test);
		test.erase(test.begin(), test.end());
		print_set(test);
	}
	///////////////////////////////////////////////
	{
		std::cout << "Swap : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 20; i++)
		{
			test.insert(i * 2);
		}

		set<int>		test_2;

		for (int i = 0; i < 15; i++)
		{
			test_2.insert(i * -1);
		}

		set<int>::iterator		it_1 = test.begin();
		set<int>::iterator		it_2 = test_2.begin();

		test.swap(test_2);

		std::cout << "Previous test iterators :" << std::endl;
		print_iterators(it_1, test_2.end());
		std::cout << "Previous test_2 iterators :" << std::endl;
		print_iterators(it_2, test.end());
	}
	{
		std::cout << "Clear : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 20; i++)
		{
			test.insert(i * 2);
		}

		print_set(test);
		test.clear();
		print_set(test);
	}
	{
		std::cout << "Key_comp and Value_comp : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 20; i++)
		{
			test.insert(i * 2);
		}
		std::cout << test.key_comp()(*(test.begin()), *(++(test.begin()))) << std::endl;
		std::cout << test.value_comp()(*(test.find(2)), *(test.find(8))) << std::endl;
	}
	{
		std::cout << "Find : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 20; i++)
		{
			test.insert(i * 2);
		}
		print_iterators(test.find(6), test.find(12));
		print_iterators(test.find(36), test.find(-42735));
	}
	{
		std::cout << "Count : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 20; i++)
		{
			test.insert(i * 2);
		}
		std::cout << "Count of element 2 : " << test.count(2) << std::endl;
		std::cout << "Count of element 10 : " << test.count(10) << std::endl;
		std::cout << "Count of element 17 : " << test.count(17) << std::endl;
		std::cout << "Count of element 26 : " << test.count(26) << std::endl;
		std::cout << "Count of element 5000 : " << test.count(5000) << std::endl;
		std::cout << "Count of element -1 : " << test.count(-1) << std::endl;
	}
	{
		std::cout << "Lower_bound and Upper_bound : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 20; i++)
		{
			test.insert(i * 2);
		}
		print_iterators(test.lower_bound(6), test.upper_bound(6));
		print_iterators(test.lower_bound(12), test.upper_bound(12));
		print_iterators(test.lower_bound(18), test.upper_bound(18));
	}
	{
		std::cout << "Equal_range : " << std::endl;
		set<int>		test;

		for (int i = 0; i < 20; i++)
		{
			test.insert(i * 2);
		}
		pair<set<int>::iterator, set<int>::iterator>		p;
		p = test.equal_range(6);
		print_iterators(p.first, p.second);
		p = test.equal_range(12);
		print_iterators(p.first, p.second);
		p = test.equal_range(18);
		print_iterators(p.first, p.second);
	}
	return (0);
}