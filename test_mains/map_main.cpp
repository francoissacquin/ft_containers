#include "../map.hpp"
#include <map>
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

void	print_map(map<int, char> x)
{
	map<int, char>::iterator		it = x.begin();
	map<int, char>::iterator		ite = x.end();

	if (it == ite)
		std::cout << "Map is empty :c" << std::endl;
	while (it != ite)
	{
		std::cout << "key = " << it->first << "| value = " << it->second << std::endl;
		++it;
	}
}
void	print_map(map<char, int> x)
{
	map<char, int>::iterator		it = x.begin();
	map<char, int>::iterator		ite = x.end();

	if (it == ite)
		std::cout << "Map is empty :c" << std::endl;
	while (it != ite)
	{
		std::cout << "key = " << it->first << "| value = " << it->second << std::endl;
		++it;
	}
}

void	print_iterators(map<int, char>::iterator it, map<int, char>::iterator ite)
{
	if (it == ite)
		std::cout << "Both iterators given point to the same value" << std::endl;
	while (it != ite)
	{
		std::cout << "key = " << it->first << "| value = " << it->second << std::endl;
		++it;
	}
}

int main()
{
	{
		std::cout << "Constructors : " << std::endl;
		map<char, int>		test;
	
		test['a'] = 1;
		test['b'] = 2;
		test['c'] = 3;
		test['d'] = 4;

		map<char, int>		test_2(test.begin(), test.end());
		map<char, int>		test_3(test);
		print_map(test);
		print_map(test_2);
		print_map(test_3);
	}
	{
		std::cout << "Operator = : " << std::endl;
		map<char, int>		test;

		test['a'] = 1;
		test['b'] = 2;
		test['c'] = 3;
		test['d'] = 4;

		map<char, int>		test_2;

		print_map(test_2);
		test_2 = test;
		print_map(test_2);
	}
	{
		std::cout << "Iterators : " << std::endl;
		map<char, int>		test;

		char	c = 'a';
		for (int i = 0; i < 10; i++)
		{
			test[c + i] = i;
		}
		print_map(test);
		std::cout << "key = " << test.begin()->first << "| value = " << test.begin()->second << std::endl;
		std::cout << "key = " << (--(test.end()))->first << "| value = " << --test.end()->second << std::endl;
		std::cout << "key = " << test.rbegin()->first << "| value = " << test.rbegin()->second << std::endl;
		std::cout << "key = " << (--(test.rend()))->first << "| value = " << --test.rend()->second << std::endl;
	}
	{
		std::cout << "Empty : " << std::endl;
		map<char, int>		test;

		std::cout << "Is map empty? " << test.empty() << std::endl;
		test['a'] = 1;
		std::cout << "Is map empty? " << test.empty() << std::endl;
		test.clear();
		std::cout << "Is map empty? " << test.empty() << std::endl;
	}
	{
		std::cout << "Size : " << std::endl;
		map<char, int>		test;

		char	c = 'a';
		for (int i = 0; i < 10; i++)
		{
			test[c + i] = i;
		}
		std::cout << "map size = " << test.size() << std::endl;
		test.clear();
		std::cout << "map size = " << test.size() << std::endl;
		test['a'] = 1;
		test['b'] = 2;
		test['c'] = 3;
		std::cout << "map size = " << test.size() << std::endl;
	}
	{
		std::cout << "Max_Size : " << std::endl;
		map<char, int>		test;

		std::cout << test.max_size() << std::endl;
	}
	{
		std::cout << "Operator [] : " << std::endl;
		map<char, int>		test;

		test['a'] = 1;
		test['b'] = 2;
		test['c'] = 3;
		test['d'] = 4;
		std::cout << "key = " << (test.lower_bound('a'))->first << "| value = " << (test.lower_bound('a'))->second << std::endl;
		std::cout << "key = " << (test.lower_bound('b'))->first << "| value = " << (test.lower_bound('b'))->second << std::endl;
		std::cout << "key = " << (test.lower_bound('c'))->first << "| value = " << (test.lower_bound('c'))->second << std::endl;
		std::cout << "key = " << (test.lower_bound('d'))->first << "| value = " << (test.lower_bound('d'))->second << std::endl;
	}
	{
		std::cout << "Insert : " << std::endl;
		map<int, char>		test;

		for (int i = 0; i < 30; i++)
		{
			pair<int, char>		temp = make_pair(i * 2, i + 96);
			test.insert(temp);
		}
		print_map(test);
		test.insert(test.begin(), make_pair(11, 'w'));
		test.insert(test.begin(), make_pair(7, 'w'));
		test.insert(test.begin(), make_pair(23, 'w'));
		print_map(test);
		map<int, char>		test_2;
		test_2.insert(test.begin(), test.end());
		print_map(test_2);
	}
	{
		std::cout << "Erase : " << std::endl;
		map<int, char>		test;

		for (int i = 0; i < 15; i++)
		{
			pair<int, char>		temp = make_pair(i, i + 96);
			test.insert(temp);
		}
		print_map(test);
		test.erase(test.begin());
		test.erase(++(test.begin()));
		print_map(test);
		test.erase('m');
		test.erase('l');
		print_map(test);
		test.erase(test.begin(), test.end());
		print_map(test);
	}
	///////////////////////////////////////////////
	{
		std::cout << "Swap : " << std::endl;
		map<int, char>		test;

		for (int i = 0; i < 20; i++)
		{
			pair<int, char>		temp = make_pair(i * 2, i + 96);
			test.insert(temp);
		}

		map<int, char>		test_2;

		for (int i = 0; i < 15; i++)
		{
			pair<int, char>		temp = make_pair(i * -1, i + 96);
			test_2.insert(temp);
		}

		map<int, char>::iterator		it_1 = test.begin();
		map<int, char>::iterator		it_2 = test_2.begin();

		test.swap(test_2);

		std::cout << "Previous test iterators :" << std::endl;
		print_iterators(it_1, test_2.end());
		std::cout << "Previous test_2 iterators :" << std::endl;
		print_iterators(it_2, test.end());
	}
	{
		std::cout << "Clear : " << std::endl;
		map<int, char>		test;

		for (int i = 0; i < 20; i++)
		{
			pair<int, char>		temp = make_pair(i * 2, i + 96);
			test.insert(temp);
		}

		print_map(test);
		test.clear();
		print_map(test);
	}
	{
		std::cout << "Key_comp and Value_comp : " << std::endl;
		map<int, char>		test;

		for (int i = 0; i < 20; i++)
		{
			pair<int, char>		temp = make_pair(i * 2, i + 96);
			test.insert(temp);
		}
		std::cout << test.key_comp()(test.begin()->first, (++(test.begin()))->first) << std::endl;
		std::cout << test.value_comp()(*(test.find(2)), *(test.find(8))) << std::endl;
	}
	{
		std::cout << "Find : " << std::endl;
		map<int, char>		test;

		for (int i = 0; i < 20; i++)
		{
			pair<int, char>		temp = make_pair(i * 2, i + 96);
			test.insert(temp);
		}
		print_iterators(test.find(6), test.find(12));
		print_iterators(test.find(36), test.find(-42735));
	}
	{
		std::cout << "Count : " << std::endl;
		map<int, char>		test;

		for (int i = 0; i < 20; i++)
		{
			pair<int, char>		temp = make_pair(i * 2, i + 96);
			test.insert(temp);
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
		map<int, char>		test;

		for (int i = 0; i < 20; i++)
		{
			pair<int, char>		temp = make_pair(i * 2, i + 96);
			test.insert(temp);
		}
		print_iterators(test.lower_bound(6), test.upper_bound(6));
		print_iterators(test.lower_bound(12), test.upper_bound(12));
		print_iterators(test.lower_bound(18), test.upper_bound(18));
	}
	{
		std::cout << "Equal_range : " << std::endl;
		map<int, char>		test;

		for (int i = 0; i < 20; i++)
		{
			pair<int, char>		temp = make_pair(i * 2, i + 96);
			test.insert(temp);
		}
		pair<map<int, char>::iterator, map<int, char>::iterator>		p;
		p = test.equal_range(6);
		print_iterators(p.first, p.second);
		p = test.equal_range(12);
		print_iterators(p.first, p.second);
		p = test.equal_range(18);
		print_iterators(p.first, p.second);
	}
	return (0);
}
