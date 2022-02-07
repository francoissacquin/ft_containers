#include "./vector/vector.hpp"
#include <iostream>

int main()
{
	// Default constructor
	{
		std::cout << "|||------------------------------ Default constructor -------------------------------|||" << std::endl;
		ft::vector<int>		temp;
		std::cout << "Size of default constructed vector : " << temp.size() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Fill constuctor
	{
		std::cout << "|||-------------------------------- Fill Constructor --------------------------------|||" << std::endl;
		ft::vector<int>		temp(10);
		std::cout << "Size of fill constructed vector : " << temp.size() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Range constuctor
	{
		std::cout << "|||------------------------------- Range constructor --------------------------------|||" << std::endl;
		ft::vector<int>		temp;
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
		ft::vector<int>		temp_copy(temp.begin() + 2, temp.end() - 1);

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
		ft::vector<int>		temp;
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
		ft::vector<int>		temp_copy(temp);
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
		ft::vector<int>		origin;
		ft::vector<int>		receptor;

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
		ft::vector<int>		temp;
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
		ft::vector<int>		temp;
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
		ft::vector<int>		temp;
		std::cout << "Creating a default constructed vector called temp..." << std::endl;
		std::cout << "temp.max_size() = " << temp.max_size() << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Resize
	{
		std::cout << "|||------------------------------------ Resize() -----------------------------------|||" << std::endl;
		ft::vector<int>		temp;
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
		ft::vector<int>		temp;
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
		ft::vector<int>		temp;
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
		ft::vector<int>		temp;
		std::cout << "Creating a fill constructed vector called temp with size 10..." << std::endl;
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
		std::cout << "Displaying incorrect vector elements through brackets : " << std::endl;
		std::cout << "size of the vector = " << temp.size() << std::endl;
		std::cout << "temp[50] = "<< temp[50] << std::endl;
		std::cout << "temp[-5] = "<< temp[-5] << std::endl;
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// at() function
	{
		std::cout << "|||----------------------------- vector.at() Element Access ---------------------------|||" << std::endl;
		ft::vector<int>		temp;
		std::cout << "Creating a fill constructed vector called temp with size 10..." << std::endl;
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
		std::cout << "Displaying incorrect vector elements through at() member function: " << std::endl;
		std::cout << "Displaying incorrect vector elements through brackets : " << std::endl;
		std::cout << "size of the vector = " << temp.size() << std::endl;
		try
		{
			std::cout << "temp.at(50) = "<< temp.at(50) << std::endl;
		}
		catch (std::exception & error)
		{
			std::cout << "Error out_of_range returned for " << error.what() << std::endl;
		}
		try
		{
			std::cout << "temp.at(-5) = "<< temp.at(-5) << std::endl;
		}
		catch (std::exception & error)
		{
			std::cout << "Error out_of_range returned for " << error.what() << std::endl;
		}
		//std::cout << "|||----------------------------------------------------------------------------------|||" << std::endl;
		std::cout << std::endl << std::endl;
	}

	// Front() and Back() Element Access
	{
		std::cout << "|||------------------------- front() and back() Element Access ------------------------|||" << std::endl;
		ft::vector<int>		temp;
		std::cout << "Creating a fill constructed vector called temp with size 10..." << std::endl;
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

	return 0;


	// temp.push_back(2);
	// temp.push_back(3);
	// temp.push_back(4);
	// temp.resize(10);
	// for (unsigned long i = 0; i < temp.size(); i++)
	// 	std::cout << "Temp[" << i << "] = " << temp[i] << std::endl;
	// return 0;


	// ft::vector<int> temp(0);
	// std::allocator<int> temp_alloc;
	// ft::random_access_iterator<int>	it;

	// for (int i = 1; i <= 10; i++)
	// {
	// 	temp.push_back(i * 10);
	// }
	// it = temp.begin();

	// //TESTING INSERT WITH > _MAX_SIZE
	// //std::cout << temp_alloc.max_size() << std::endl;
	// //temp.insert(it, 2305843009213693953, 0);

	// //TESTING DESTROY WITH THE ALLOCATOR
	// //temp_alloc.destroy(&(temp[4]));
	// temp_alloc.construct(&(temp[4]), 2);
	// //temp.erase(temp.begin() + 3);
	// //temp.pop_back();

	// // DISPLAYING TEMP VECTOR
	// for (unsigned long i = 0; i < temp.size(); i++)
	// 	std::cout << "Temp[" << i << "] = " << temp[i] << std::endl;

	// std::cout << std::endl;

	// //TESTING ITERATOR DEREFERENCING
	// std::vector<int>::iterator ptr = temp.begin();
	// std::cout << *ptr << std::endl;
	// *ptr++ = 25;
	// std::cout << *ptr << std::endl;
	// for (unsigned long i = 0; i < temp.size(); i++)
	// 	std::cout << "Temp[" << i << "] = " << temp[i] << std::endl;
	// return (0);
}
