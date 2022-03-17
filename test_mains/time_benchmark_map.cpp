#include "../map.hpp"
#include <map>
#include <iterator>
#include <iostream>
#include <time.h>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <poll.h>
#include <list>


#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif


using namespace NAMESPACE;


#define NB_OF_ELEMENTS 10000
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

void constructor_bench()
{
    std::cout << "Constructor Bench" << std::endl;
    size_t start = chrono_init();

    NAMESPACE::map<int, std::string> *test;
    std::cout << "Constructor Default" << std::endl;
    for (int i = 0; i < NB_OF_ELEMENTS * 10; i++)
    {
        test = new NAMESPACE::map<int , std::string>;
        delete test;
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;


    std::list<NAMESPACE::pair<int, std::string> > just_a_list;
    for (int i = 0; i < NB_OF_ELEMENTS/20; i++)
    {
        just_a_list.push_back(NAMESPACE::make_pair(NB_OF_ELEMENTS, "same"));
    }

    std::cout << "Constructor range" << std::endl;
    start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test = new NAMESPACE::map<int, std::string>(just_a_list.begin(), just_a_list.end());
        delete test;
    }
    std::cout << stamp_time(start) << "ms" << std::endl;

    NAMESPACE::map<int, std::string> original;
    std::string blop("blop");
    for (int i = 0; i < 100; i++)
    {
        original.insert(NAMESPACE::make_pair(i, blop));
    }
    std::cout << "Constructor copy" << std::endl;
    start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS; i++)
    {
        test = new NAMESPACE::map<int, std::string>(original);
        delete test;
    }
    std::cout << stamp_time(start) << "ms" << std::endl;
}

void operator_assign()
{
    std::cout << "Operator assign bench" << std::endl;

    NAMESPACE::map<int, std::string> test;
    for (int i = 0; i < NB_OF_ELEMENTS * 100; i++)
    {
        test.insert(NAMESPACE::make_pair(i, "pair"));
    }
    NAMESPACE::map<int, std::string> ditto;
    size_t start = chrono_init();
    ditto = test;
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    start = chrono_init();
}



void crochet_bench()
{
    NAMESPACE::map<int, std::string> test;
    std::cout << "Crochet bench" << std::endl;
    for (int i = 0; i < NB_OF_ELEMENTS * 100; i++)
    {
        test.insert(NAMESPACE::make_pair(i, "woof"));
    }
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS * 100; i++)
    {
        test[i] = "waf";
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
}



void insert_erase_bench()
{
    NAMESPACE::map<int,std::string> test;
    std::cout << "insert bench" << std::endl;
    std::cout << "single element" << std::endl;
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        test.insert(NAMESPACE::make_pair(i, "poisson"));
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    std::cout << "single element with hint" << std::endl;
    test.clear();
    start = chrono_init();
    for (int i = 0; i < 500000 ;i++)
    {
        test.insert(test.begin() , NAMESPACE::make_pair(i, "poisson"));
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    NAMESPACE::map<int,std::string> test2;
    std::cout << "range element" << std::endl;
    start = chrono_init();
    for (int i = 0; i < 3 ;i++)
    {
        test2.insert(test.begin() , test.end());
        test2.clear();
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    //std::cout << "cool" << std::endl;
    for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        test.insert(NAMESPACE::make_pair(i, "poisson"));
    }
    std::cout << "\nErase bench" << std::endl;
    std::cout << "single iterator" << std::endl;
    start = chrono_init();  
    for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        test.erase(test.begin());
    }
     std::cout << stamp_time(start) <<  "ms" <<std::endl;
    for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        test.insert(NAMESPACE::make_pair(i, "poisson"));
    }
    std::cout << "Range iterator" << std::endl;
    start = chrono_init();  
    test.erase(test.begin() , test.end());
     std::cout << stamp_time(start) <<  "ms" <<std::endl;
     for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        test.insert(NAMESPACE::make_pair(i, "poisson"));
    }
    std::cout << "by key" << std::endl;
    start = chrono_init();  
    for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        test.erase(i);
    }
     std::cout << stamp_time(start) <<  "ms" <<std::endl;
}

void swap_bench()
{
    NAMESPACE::map<int , std::string> swap_a;
    NAMESPACE::map<int , std::string> swap_b;

     for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        swap_a.insert(NAMESPACE::make_pair(i, "poisson"));
    }
     for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        swap_b.insert(NAMESPACE::make_pair(i, "poisson"));
    }
    std::cout << "Swap Bench" << std::endl;
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS * 100;i++)
    {
        swap_a.swap(swap_b);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
}

void find_count_bench()
{
    NAMESPACE::map<int,std::string> test;
    std::cout << "Find bench" << std::endl;
    for (int i = 0; i < NB_OF_ELEMENTS * 100 ;i++)
    {
        test.insert(NAMESPACE::make_pair(i, "poisson"));
    }
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS * 100 ;i++)
    {
        test.find(i);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
    std::cout << "Count bench" << std::endl;
    start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS * 100 ;i++)
    {
        test.count(i);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;

}

void lower_upper_bound_bench()
{
    NAMESPACE::map<int,std::string> test;
    std::cout << "Lower bound bench" << std::endl;
    for (int i = 0; i < NB_OF_ELEMENTS ;i++)
    {
        test.insert(NAMESPACE::make_pair(i * 2, "poisson"));
    }
    size_t start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS * 2 ;i++)
    {
        test.lower_bound(i);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;
     std::cout << "Upper bound bench" << std::endl;
     start = chrono_init();
    for (int i = 0; i < NB_OF_ELEMENTS * 2 ;i++)
    {
        test.upper_bound(i);
    }
    std::cout << stamp_time(start) <<  "ms" <<std::endl;


}
int main()
{
    constructor_bench();
    operator_assign();
    crochet_bench();

    insert_erase_bench();
    swap_bench();

    find_count_bench();
    lower_upper_bound_bench();
}
