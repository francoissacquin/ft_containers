#include "../stack.hpp"
#include <stack>
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

int		main()
{
	{
		std::cout << "Constructors :" << std::endl;
		stack<int>		test;
	}
	{
		std::cout << "Empty :" << std::endl;
		stack<int>		test;

		std::cout << "Is stack empty? " << test.empty() << std::endl;
		test.push(1);
		std::cout << "Is stack empty? " << test.empty() << std::endl;
		test.pop();
		std::cout << "Is stack empty? " << test.empty() << std::endl;
	}
	{
		std::cout << "Size :" << std::endl;
		stack<int>		test;

		std::cout << "Stack size = " << test.size() << std::endl;

		for (int i = 0; i < 20; i++)
		{
			test.push(i * 2);
		}
		std::cout << "Stack size = " << test.size() << std::endl;

		for (int i = 0; i < 5; i++)
		{
			test.pop();
		}
		std::cout << "Stack size = " << test.size() << std::endl;
	}
	{
		std::cout << "Top :" << std::endl;
		stack<int>		test;

		for (int i = 0; i < 20; i++)
		{
			test.push(i * 2);
		}
		for (int i = 0; i < 20; i++)
		{
			std::cout << "top elem = " << test.top() << std::endl;
			test.pop();
		}
	}
	{
		std::cout << "Push and Pop :" << std::endl;
		stack<int>		test;

		for (int i = 0; i < 20; i++)
		{
			std::cout << "Pushing value : " << i << std::endl;
			test.push(i * 2);
		}
		for (int i = 0; i < 20; i++)
		{
			std::cout << "Poping value : " << test.top() << std::endl;
			test.pop();
		}
	}
	{
		std::cout << "Relationnal Operators:" << std::endl;
		stack<int>		test;
		stack<int>		test_2;
		stack<int>		test_copy;

		for (int i = 0; i < 20; i++)
		{
			std::cout << "Pushing value into test : " << i << std::endl;
			test.push(i * 2);
		}
		for (int i = 0; i < 20; i++)
		{
			std::cout << "Pushing value into test_2 : " << i << std::endl;
			test.push(i * -1);
		}
		for (int i = 0; i < 20; i++)
		{
			test_copy.push(i * 2);
		}

		std::cout << "Stack test == test_copy : " << (test == test_copy) << std::endl;
		std::cout << "Stack test != test_copy : " << (test != test_copy) << std::endl;
		std::cout << "Stack test < test_2 : " << (test < test_copy) << std::endl;
		std::cout << "Stack test <= test_2 : " << (test <= test_copy) << std::endl;
		std::cout << "Stack test > test_copy : " << (test >= test_copy) << std::endl;
		std::cout << "Stack test >= test_copy : " << (test >= test_copy) << std::endl;
	}
}
