# include "../vector.hpp"
# include <vector>
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

int main()
{
	vector<int>			test(3, 3);

	std::cout << "self assignation test\n";
	vector<vector<int> >	self_assign;
	vector<vector<int> >	*ptr = &self_assign;
	vector<vector<int> >	*ptr2 = &self_assign;

	self_assign.assign(4, test);
	*ptr = *ptr2;

	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';



	vector<vector<int> > JOHN;
	vector<vector<int> > BOB(5, test);
	std::cout << "BOB(5, test(test, 5)) : \n";
	for (size_t i = 0; i < BOB.size(); i++)
	{
		for (size_t j = 0; j < BOB[i].size(); j++)
			std::cout << BOB[i][j] << ' ';
		std::cout << '\n';
	}
	vector<vector<int> > MIKE(BOB);

	// CTORs
	std::cout << "\nCTORS\n";
	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	std::cout << "BOB is empty? " << BOB.empty() << '\n';

	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;

	// RESIZE
	size_t	bob_resize = 2;
	std::cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, test);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
		{
			std::cout << MIKE[i][j] << ' ';
		}
	std::cout << std::endl;
	}

	// RESERVE
	std::cout << "\nRESERVE\n";

	size_t	john_reserve = 0;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 4;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}


	//AT
	std::cout << "\nAT\n";
	try
	{
		std::cout << MIKE.at(2).front() << '\n';
		std::cout << MIKE.at(87).back() << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		std::cout << "OOR error caught\n";
	}

	// FRONT / BACK
	std::cout << "\nFRONT / BACK\n";
	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	//ASSIGN
	std::cout << "\nASSIGN\n";
	test.assign(3, 17);
	BOB.assign(3, test);

	//ASSIGN RANGE
	std::cout << "\nASSIGN RANGE\n";
	vector<vector<int> >	assign_range;
	assign_range.assign(8, test);
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	std::cout << "\nEMPTY\n";
	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

	//PUSH/POP_BACK
	std::cout << "\nPUSH/POP_BACK\n";
	test.assign(2, 42);
	BOB.push_back(test);
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
	BOB.pop_back();
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';


	//INSERT
	std::cout << "\nINSERT\n";
	vector<vector<int> >	insert_in_me;
	for (int i = 0; i < 15; i++)
	{
		vector<int>	j(2, i);
		insert_in_me.push_back(j);
	}
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}

	//
	vector<vector<int> >::iterator	tmp;
	test.assign(23, 19);
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, test);

	
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}

	vector<vector<int> >::const_iterator const_it(insert_in_me.begin());
	std::cout << "Const it.front() : " << std::endl;
	std::cout << (*const_it).front() << '\n';


	//INSERT
	std::cout << "\nINSERT\n";
	vector<vector<int> >	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).front() << ' ';
	std::cout << '\n';

	vector<vector<int> >::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).back() << ' ';
	std::cout << '\n';


	//INSERT RANGE
	std::cout << "\nINSERT RANGE\n";
	vector<vector<int> >	insert_bis;
	for (int i = 0; i < 7; i++)
	{
		vector<int>	j(2, i * 3);
		insert_bis.push_back(j);
	}
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';
	
	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());

	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';


	//ERASE
	std::cout << "\nERASE\n";
	vector<vector<int> >	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		vector<int>	j(1, i);
		erase_in_me.push_back(j);
	}
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';
	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	//SWAP
	std::cout << "\nSWAP\n";
	john_reserve = 4;
	JOHN.reserve(john_reserve);
	BOB.swap(MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	MIKE.swap(JOHN);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//CLEAR
	std::cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//NON MEMBER Functions
	std::cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//RELATIONAL OPERATORS
	std::cout << "\nRELATIONAL OPERATORS\n";
	vector<vector<int> > MIKE_2(MIKE);
	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	std::cout << "\nReal vector\n";
	vector<vector<int> > real;
	real.assign(5, test);
	for (vector<vector<int> >::iterator it = real.begin(); it != real.end(); it++)
		std::cout << (*it).front() << " ";
	std::cout << '\n';

	std::cout << std::endl;


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	srand(time(0));

	// Default constructor
	{
		std::cout << "|||------------------------------ Default constructor -------------------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "Size of default constructed vector : " << temp.size() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Fill constuctor
	{
		std::cout << "|||-------------------------------- Fill Constructor --------------------------------|||" << std::endl;
		vector<int>		temp(10);
		std::cout << "Size of fill constructed vector : " << temp.size() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Range constuctor
	{
		std::cout << "|||------------------------------- Range constructor --------------------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "cool" << std::endl;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "Displaying original vector          : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Constructing a vector from begin() + 2 to end() - 1..." << std::endl;
		vector<int>		temp_copy(temp.begin() + 2, temp.end() - 1);

		std::cout << "Displaying range constructed vector : ";
		for (unsigned long i = 0; i < temp_copy.size(); i++)
		{
			std::cout << temp_copy[i];
			if (i != temp_copy.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}


	// Copy constuctor
	{
		std::cout << "|||-------------------------------- Copy constructor --------------------------------|||" << std::endl;
		vector<int>		temp;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "Displaying original vector          : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		vector<int>		temp_copy(temp);
		std::cout << "Displaying copy constructed vector : ";
		for (unsigned long i = 0; i < temp_copy.size(); i++)
		{
			std::cout << temp_copy[i];
			if (i != temp_copy.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Constructing vectors with all possible variable types
	{
		// empty for now, might add some things later
	}

	//Operator overload
	{
		std::cout << "|||----------------------------------- Operators ------------------------------------|||" << std::endl;
		vector<int>		origin;
		vector<int>		receptor;

		for (int i = 0; i < 10; i++)
			origin.push_back(i * 10);
		for (int i = 0; i < 10; i++)
			receptor.push_back(i * -5);
		std::cout << "Displaying original vector          : ";
		for (unsigned long i = 0; i < origin.size(); i++)
		{
			std::cout << origin[i];
			if (i != origin.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Displaying receptor vector          : ";
		for (unsigned long i = 0; i < receptor.size(); i++)
		{
			std::cout << receptor[i];
			if (i != receptor.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Assigning origin to receptor : receptor = origin;" << std::endl;
		std::cout << "Displaying new receptor vector      : ";
		for (unsigned long i = 0; i < receptor.size(); i++)
		{
			std::cout << receptor[i];
			if (i != receptor.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Iterator Functions
	{
		std::cout << "|||------------------------------- Iterator Functions -------------------------------|||" << std::endl;
		vector<int>		temp;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "temp.begin() = " << *(temp.begin()) << std::endl;
		std::cout << "temp.end() - 1 = " << *(temp.end() - 1) << std::endl;
		std::cout << "temp.rbegin() = " << *(temp.rbegin()) << std::endl;
		std::cout << "temp.rend() - 1 = " << *(temp.rend() - 1) << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Size
	{
		std::cout << "|||------------------------------------- Size() -------------------------------------|||" << std::endl;
		vector<int>		temp;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "Creating a temp vector with 10 elements..." << std::endl;
		std::cout << "temp.size() = " <<temp.size() << std::endl;
		std::cout << "Removing 4 elements..." << std::endl;
		for (int i = 0; i < 4; i++)
			temp.pop_back();
		std::cout << "temp.size() = " <<temp.size() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Max_size
	{
		std::cout << "|||----------------------------------- Max_size() -----------------------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "Creating a default constructed vector called temp..." << std::endl;
		std::cout << "temp.max_size() = " << temp.max_size() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Resize
	{
		std::cout << "|||------------------------------------ Resize() -----------------------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "temp size = " << temp.size() << std::endl;
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Resizing the vector to 100 elements of value 5..." << std::endl;
		temp.resize(100, 5);
		std::cout << "temp size = " << temp.size() << std::endl;
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Resizing the vector to 15 elements of value 0..." << std::endl;
		temp.resize(15, 0);
		std::cout << "temp size = " << temp.size() << std::endl;
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Capacity & Reserve
	{
		std::cout << "|||------------------------------- Capacity() & Reserve() -----------------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "Creating a default constructed vector called temp..." << std::endl;
		std::cout << "temp.capacity = " << temp.capacity() << std::endl;
		std::cout << "Reserving the vector to 50 elements..." << std::endl;
		temp.reserve(50);
		std::cout << "temp.capacity = " << temp.capacity() << std::endl;
		std::cout << "Reserving the vector to 5000 elements..." << std::endl;
		temp.reserve(5000);
		std::cout << "temp.capacity = " << temp.capacity() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Empty
	{
		std::cout << "|||-------------------------------------- Empty() -------------------------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "Creating a default constructed vector called temp..." << std::endl;
		std::cout << "temp.empty() = " << temp.empty() << std::endl;
		std::cout << "Resizing the vector to 15 elements of value 0..." << std::endl;
		temp.resize(15, 0);
		std::cout << "temp.empty() = " << temp.empty() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Bracket element access
	{
		std::cout << "|||------------------------------ Bracket Element Access[] ----------------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "Creating a default constructed vector called temp ..." << std::endl;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Displaying vector elements through brackets : " << std::endl;
		std::cout << "temp[3] = "<< temp[3] << std::endl;
		std::cout << "temp[9] = "<< temp[9] << std::endl;
		std::cout << "temp[2] = "<< temp[2] << std::endl;
		std::cout << "temp[6] = "<< temp[6] << std::endl;
		// std::cout << "Displaying incorrect vector elements through brackets : " << std::endl;
		std::cout << "size of the vector = " << temp.size() << std::endl;
		//std::cout << "temp[50] = "<< temp[50] << std::endl;
		// std::cout << "temp[-5] = "<< temp[-5] << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// at() function
	{
		std::cout << "|||----------------------------- vector.at() Element Access ---------------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "Creating a default constructed vector called temp ..." << std::endl;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Displaying vector elements through at() member function: " << std::endl;
		std::cout << "temp.at(3) = "<< temp.at(3) << std::endl;
		std::cout << "temp.at(9) = "<< temp.at(9) << std::endl;
		std::cout << "temp.at(2) = "<< temp.at(2) << std::endl;
		std::cout << "temp.at(6) = "<< temp.at(6) << std::endl;
		// std::cout << "Displaying incorrect vector elements through at() member function: " << std::endl;
		// std::cout << "Displaying incorrect vector elements through brackets : " << std::endl;
		// std::cout << "size of the vector = " << temp.size() << std::endl;
		// try
		// {
		// 	std::cout << "temp.at(50) = "<< temp.at(50) << std::endl;
		// }
		// catch (std::exception & error)
		// {
		// 	std::cout << "Error out_of_range returned for " << error.what() << std::endl;
		// }
		// try
		// {
		// 	std::cout << "temp.at(-5) = "<< temp.at(-5) << std::endl;
		// }
		// catch (std::exception & error)
		// {
		// 	std::cout << "Error out_of_range returned for " << error.what() << std::endl;
		// }
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Front() and Back() Element Access
	{
		std::cout << "|||------------------------- front() and back() Element Access ------------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "Creating a default constructed vector called temp..." << std::endl;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "temp.front() = "<< temp.front() << std::endl;
		std::cout << "temp.back() = "<< temp.back() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Assign modifier
	{
		std::cout << "|||--------------------------------- Assign() Modifier --------------------------------|||" << std::endl;
		vector<int>		temp;
		{
			vector<int>		cool;
			cool.assign(7, 100);
		}
		std::cout << "Creating a default constructed vector called temp ..." << std::endl;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;


		std::cout << "Creating a default constructed vector called temp_2 ..." << std::endl;
		vector<int>		temp_2;
		std::cout << "Assigning the end half of temp to temp_2 through iterators ..." << std::endl;
		temp_2.assign(temp.begin() + (temp.size() / 2), temp.end());
		std::cout << "Displaying vector temp_2: ";
		for (unsigned long i = 0; i < temp_2.size(); i++)
		{
			std::cout << temp_2[i];
			if (i != temp_2.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;


		std::cout << "Creating a default constructed vector called temp_3 ..." << std::endl;
		vector<int>		temp_3;
		std::cout << "Assigning a size of 15 with value 64 to temp_3 ..." << std::endl;
		temp_3.assign(15, 64);
		std::cout << "Displaying vector temp_3: ";
		for (unsigned long i = 0; i < temp_3.size(); i++)
		{
			std::cout << temp_3[i];
			if (i != temp_3.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// push_back() and pop_back()
	{
		std::cout << "|||------------------------ push_back() and pop_back() Modifier -----------------------|||" << std::endl;
		vector<int>		temp;
		std::cout << "Creating a default constructed vector called temp ..." << std::endl;
		std::cout << "Trying to pop_back an empty vector : " << std::endl;
		std::cout << "temp.popback()" << std::endl;
		//temp.pop_back();
		std::cout << std::endl;
		std::cout << "Adding 20 values with push_back : " << std::endl;
		for (int i = 0; i < 20; i++)
			temp.push_back(i * 20);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Size of vector is " << temp.size() << std::endl;
		std::cout << "Removing 15 random values with pop_back : " << std::endl;
		for (int i = 0; i < 15; i++)
			temp.pop_back();
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "New size of vector is " << temp.size() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Insert
	{
		std::cout << "|||--------------------------------- Insert() Modifier --------------------------------|||" << std::endl;
		vector<int>		temp;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "Creating a default constructed vector called temp ..." << std::endl;
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "Inserting value -5 in position 2, 5 and 8..." << std::endl;
		temp.insert(temp.begin() + 2, -5);
		temp.insert(temp.begin() + 5, -5);
		temp.insert(temp.begin() + 8, -5);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "Inserting 5 times value 32 in position 6..." << std::endl;
		temp.insert(temp.begin() + 6, 5, 32);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "Creating a default constructed vector called insert_vector ..." << std::endl;
		vector<int>		insert_vector;
		insert_vector.assign(8, 0);
		std::cout << "Displaying insert_vector : ";
		for (unsigned long i = 0; i < insert_vector.size(); i++)
		{
			std::cout << insert_vector[i];
			if (i != insert_vector.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Inserting insert_vector inside temp using iterators at position 7..." << std::endl;
		temp.insert(temp.begin() + 7, insert_vector.begin(), insert_vector.end());
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Erase
	{
		std::cout << "|||--------------------------------- Erase() Modifier ---------------------------------|||" << std::endl;
		vector<int>		temp;
		for (int i = 0; i < 20; i++)
			temp.push_back(i * 10);
		std::cout << "Creating a default constructed vector called temp ..." << std::endl;
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "Erasing elements in positions 14, 8 and 3 ..." << std::endl;
		temp.erase(temp.begin() + 14);
		temp.erase(temp.begin() + 8);
		temp.erase(temp.begin() + 3);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "Erasing all elements between begin() + 2 and end() - 2 ..." << std::endl;
		temp.erase(temp.begin() + 2, temp.end() - 2);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Swap
	{
		std::cout << "|||--------------------------------- Swap() Modifier ---------------------------------|||" << std::endl;
		std::cout << "Creating 2 vectors with different sizes and elements ..." << std::endl;
		vector<int>		temp;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		vector<int>		temp_2;
		for (int i = 0; i < 15; i++)
			temp_2.push_back((i + 1) * -5);
		std::cout << "Displaying vector 1 : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Displaying vector 2 : ";
		for (unsigned long i = 0; i < temp_2.size(); i++)
		{
			std::cout << temp_2[i];
			if (i != temp_2.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "Creating 4 iterators, 2 begin() iterators and 2 end() iterators for each vector ..." << std::endl;
		vector<int>::iterator		temp_begin = temp.begin();
		vector<int>::iterator		temp_end = temp.end();
		vector<int>::iterator		temp_2_begin = temp_2.begin();
		vector<int>::iterator		temp_2_end = temp_2.end();
		std::cout << "iterator 1 = vector 1 begin     = " << *temp_begin << std::endl;
		std::cout << "iterator 2 = vector 1 end() - 1 = " << *(temp_end - 1) << std::endl;
		std::cout << "iterator 3 = vector 2 begin     = " << *temp_2_begin << std::endl;
		std::cout << "iterator 4 = vector 2 end() - 1 = " << *(temp_2_end - 1) << std::endl;
		std::cout << std::endl;
		std::cout << "Swapping vector 1 and vector 2 :  temp.swap(temp_2)" << std::endl;
		temp.swap(temp_2);
		std::cout << "Displaying vector 1 : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Displaying vector 2 : ";
		for (unsigned long i = 0; i < temp_2.size(); i++)
		{
			std::cout << temp_2[i];
			if (i != temp_2.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "iterator 1 = " << *temp_begin << std::endl;
		std::cout << "iterator 2 = " << *(temp_end - 1) << std::endl;
		std::cout << "iterator 3 = " << *temp_2_begin << std::endl;
		std::cout << "iterator 4 = " << *(temp_2_end - 1) << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Clear
	{
		std::cout << "|||--------------------------------- Clear() Modifier ---------------------------------|||" << std::endl;
		std::cout << "Creating a default constructed vector called temp ..." << std::endl;
		vector<int>		temp;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Vector size = " << temp.size() << std::endl;
		std::cout << std::endl;
		std::cout << "Clearing the contents of vector ..." << std::endl;
		temp.clear();
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Vector size = " << temp.size() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	//get_allocator
	{
		std::cout << "|||----------------------------- Get_allocator() Modifier -----------------------------|||" << std::endl;
		std::cout << "Creating a default constructed vector called temp ..." << std::endl;
		vector<int>		temp;
		temp.assign(10, 0);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Deconstructing and constructing memory through get_allocator() (destroying index 1, 5 and 7 and constructing value 7 on top) and displaying the result" << std::endl;
		temp.get_allocator().destroy(&temp[5]);
		temp.get_allocator().construct(&temp[5], 7);
		temp.get_allocator().destroy(&temp[1]);
		temp.get_allocator().construct(&temp[1], 7);
		temp.get_allocator().destroy(&temp[7]);
		temp.get_allocator().construct(&temp[7], 7);
		std::cout << "Displaying vector : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Relational Operators
	{
		std::cout << "|||------------------------------- Relational Operators -------------------------------|||" << std::endl;
		std::cout << "Creating 3 default constructed vectors called temp, temp_2 and temp_copy ..." << std::endl;
		vector<int>		temp;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		vector<int>		temp_2;
		for (int i = 0; i < 12; i++)
			temp_2.push_back((i + 1) * -5);
		vector<int>		temp_copy(temp);
		std::cout << "Displaying vector temp : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Displaying vector temp_2: ";
		for (unsigned long i = 0; i < temp_2.size(); i++)
		{
			std::cout << temp_2[i];
			if (i != temp_2.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Displaying vector temp_copy : ";
		for (unsigned long i = 0; i < temp_copy.size(); i++)
		{
			std::cout << temp_copy[i];
			if (i != temp_copy.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "temp == temp_2    -> " << (temp == temp_2) << std::endl;
		std::cout << "temp == temp_copy -> " << (temp == temp_copy) << std::endl;
		std::cout << "temp != temp_2    -> " << (temp != temp_2) << std::endl;
		std::cout << "temp != temp_copy -> " << (temp != temp_copy) << std::endl;
		std::cout << "temp < temp_2     -> " << (temp < temp_2) << std::endl;
		std::cout << "temp < temp_copy  -> " << (temp < temp_copy) << std::endl;
		std::cout << "temp <= temp_2    -> " << (temp <= temp_2) << std::endl;
		std::cout << "temp <= temp_copy -> " << (temp <= temp_copy) << std::endl;
		std::cout << "temp > temp_2     -> " << (temp > temp_2) << std::endl;
		std::cout << "temp > temp_copy  -> " << (temp > temp_copy) << std::endl;
		std::cout << "temp >= temp_2    -> " << (temp >= temp_2) << std::endl;
		std::cout << "temp >= temp_copy -> " << (temp >= temp_copy) << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Non-member swap()
	{
		std::cout << "|||-------------------------------- Non-member swap() --------------------------------|||" << std::endl;
		std::cout << "Creating 2 vectors with different sizes and elements ..." << std::endl;
		vector<int>		temp;
		for (int i = 0; i < 10; i++)
			temp.push_back(i * 10);
		vector<int>		temp_2;
		for (int i = 0; i < 15; i++)
			temp_2.push_back((i + 1) * -5);
		std::cout << "Displaying vector 1 : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Displaying vector 2 : ";
		for (unsigned long i = 0; i < temp_2.size(); i++)
		{
			std::cout << temp_2[i];
			if (i != temp_2.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "Creating 4 iterators, 2 begin() iterators and 2 end() iterators for each vector ..." << std::endl;
		vector<int>::iterator		temp_begin = temp.begin();
		vector<int>::iterator		temp_end = temp.end();
		vector<int>::iterator		temp_2_begin = temp_2.begin();
		vector<int>::iterator		temp_2_end = temp_2.end();
		std::cout << "iterator 1 = vector 1 begin     = " << *temp_begin << std::endl;
		std::cout << "iterator 2 = vector 1 end() - 1 = " << *(temp_end - 1) << std::endl;
		std::cout << "iterator 3 = vector 2 begin     = " << *temp_2_begin << std::endl;
		std::cout << "iterator 4 = vector 2 end() - 1 = " << *(temp_2_end - 1) << std::endl;
		std::cout << std::endl;
		std::cout << "Swapping vector 1 and vector 2 :  swap(temp, temp_2)" << std::endl;
		swap(temp, temp_2);
		std::cout << "Displaying vector 1 : ";
		for (unsigned long i = 0; i < temp.size(); i++)
		{
			std::cout << temp[i];
			if (i != temp.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl;
		std::cout << "Displaying vector 2 : ";
		for (unsigned long i = 0; i < temp_2.size(); i++)
		{
			std::cout << temp_2[i];
			if (i != temp_2.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
		std::cout << "iterator 1 = " << *temp_begin << std::endl;
		std::cout << "iterator 2 = " << *(temp_end - 1) << std::endl;
		std::cout << "iterator 3 = " << *temp_2_begin << std::endl;
		std::cout << "iterator 4 = " << *(temp_2_end - 1) << std::endl;
	}

	return 0;
} 
