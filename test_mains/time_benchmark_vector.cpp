#include "../vector.hpp"
#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <list>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif


using namespace NAMESPACE;

#define NB_OF_ELEMENTS 1000000
#define FALSE 0

unsigned long int	chrono_init(void)
{
	struct timeval		tv;
	unsigned long int	start_time;

	gettimeofday(&tv, NULL);
	start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (start_time);
}
 
unsigned long int	stamp_time(unsigned long int start_time)
{
	unsigned long int	actual_time;
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	actual_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - start_time;
	return (actual_time);
}

void	random_stuff()
{
	std::cout << "Random Stuff" << std::endl;
	size_t start = chrono_init();
	vector<int>	old_man;

	for (int i = 0; i < 1000000; i++)
	{
		old_man.push_back(i);
	}

	vector<int>		new_guy(old_man);

	for (int i = 0; i < 20; i++)
	{
		for (int i = 0; i < 1000000; i++)
		{
			new_guy.pop_back();
		}
		new_guy = old_man;
	}

	vector<int>		some_guy;

	some_guy.insert(some_guy.begin(), old_man.begin(), old_man.end());
	some_guy.clear();

	for (int i = 0; i < 1000000; i++)
	{
		some_guy.reserve(i);
	}

	for (int i = 0; i < 20; i++)
	{
		some_guy.assign(1000000, 12);
		some_guy.insert(some_guy.begin(), old_man.begin(), old_man.end());
		some_guy.erase(some_guy.begin(), some_guy.end());
	}
	std::cout << stamp_time(start) << "ms" << std::endl;
}

void constructor_bench()
{
    std::cout << "Constructor Bench" << std::endl;

    size_t start = chrono_init();

    NAMESPACE::vector<std::string> *test;
    std::cout << "Constructor Default" << std::endl;
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test = new NAMESPACE::vector<std::string>;
        delete test;
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    start = chrono_init();
    std::cout << "Constructor fill" << std::endl;
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test = new NAMESPACE::vector<std::string>(10, "blop");
        delete test;
    }
     std::cout << stamp_time(start) << "ms" << std::endl;


     std::list<std::string> just_a_list(15, "youhoo");
    std::cout << "Constructor range" << std::endl;
    start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test = new NAMESPACE::vector<std::string>(just_a_list.begin(), just_a_list.end());
        delete test;
    }
    std::cout << stamp_time(start) << "ms" << std::endl;

    std::cout << "Constructor copy" << std::endl;
    NAMESPACE::vector<std::string> little_things_in(15, "gift");
    start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test = new NAMESPACE::vector<std::string>(little_things_in);
        delete test;
    }
    std::cout << stamp_time(start) << "ms" << std::endl;

}

void operator_assign()
{
    std::cout << "Operator assign bench" << std::endl;

    NAMESPACE::vector<std::string> test;
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test.push_back("miaou");
    }
    NAMESPACE::vector<std::string> ditto;
    size_t start = chrono_init();
    ditto = test;
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    start = chrono_init();
}

void resize_bench()
{
    std::cout << "Resize bench" << std::endl;

    NAMESPACE::vector<std::string> test;
    std::cout << "size up one by one" << std::endl;
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test.resize(i);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    std::cout << "size decrease one by one" << std::endl;
    start = chrono_init();
    for (int i = NB_OF_ELEMENTS; i >= 0; i--)
    {
        test.resize(i);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
}

void reserve_bench()
{
    std::cout << "Reserve bench" << std::endl;

    NAMESPACE::vector<std::string> test;
    std::cout << "size up one by one" << std::endl;
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test.reserve(i);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
}

void crochet_bench()
{
    NAMESPACE::vector<std::string> test;
    std::cout << "Crochet bench" << std::endl;
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test.push_back("miaou");
    }
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test[i] = "waf";
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
}

void assign_bench()
{
    NAMESPACE::vector<std::string> test;

    std::cout << "Assign bench" << std::endl;
    std::cout << "fill version" << std::endl;
    size_t start = chrono_init();
    test.assign(NB_OF_ELEMENTS,  "welcome");
    test.assign(NB_OF_ELEMENTS,  "welcome");
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    NAMESPACE::vector<std::string> test2;
    std::cout << "range version" << std::endl;
    start = chrono_init();
    for (int i = 0; i < 20;i++)
    {
        test2.assign(test.begin(),  test.end());
        test.assign(test2.begin(), test2.end());
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
}

void push_pop_back_bench()
{
    NAMESPACE::vector<std::string> test;
    std::cout << "push_back bench" << std::endl;
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS * 2;i++)
    {
        test.push_back("sameastheprevious");
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    std::cout << "pop_back bench" << std::endl;
    start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS;i++)
    {
        test.pop_back();
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
}

void insert_bench()
{
    NAMESPACE::vector<std::string> test;
    std::cout << "insert bench" << std::endl;
    std::cout << "single element" << std::endl;
    size_t start = chrono_init();
    for (int i = 0; i < 15000 ;i++)
    {
        test.insert(test.begin() + i/2 , "sameastheprevious");
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    std::cout << "fill element" << std::endl;
    start = chrono_init();
    test.clear();
    for (int i = 0; i < 5000 ;i++)
    {
        test.insert(test.begin() + i/2 , 3 ,"sameastheprevious");
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    NAMESPACE::vector<std::string> test2;
    std::cout << "range element" << std::endl;
    start = chrono_init();
    for (int i = 0; i < 5000 ;i++)
    {
        test2.insert(test2.begin() + i/2 , test.begin() , test.begin() + 3);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
}

void swap_bench()
{
    NAMESPACE::vector<std::string> swap_a(100, "opop");
    NAMESPACE::vector<std::string> swap_b(100, "ploup");

    std::cout << "Swap Bench" << std::endl;
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        swap_a.swap(swap_b);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
}
int main()
{
    constructor_bench();
    operator_assign();
    resize_bench();
    reserve_bench();
    crochet_bench();
    assign_bench();
    push_pop_back_bench();
    swap_bench();
    insert_bench();
    random_stuff();

}
