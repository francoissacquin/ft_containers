#include "RB_tree.hpp"

int main()
{
	ft::RB_tree<int, char>		bst;

	for (int i = 0; i < 100; i+=2)
	{
		ft::pair<int, char>		temp = ft::make_pair(i, i + 96);
		bst.insert(temp);
	}
	for (int i = 1; i < 100; i+=2)
	{
		ft::pair<int, char>		temp = ft::make_pair(i, i + 96);
		bst.insert(temp);
	}

	// ft::pair<int, char>		a = ft::make_pair(1,'a');
	// ft::pair<int, char>		b = ft::make_pair(2,'b');
	// ft::pair<int, char>		c = ft::make_pair(3,'c');
	// ft::pair<int, char>		d = ft::make_pair(4,'d');
	// ft::pair<int, char>		e = ft::make_pair(5,'e');
	// ft::pair<int, char>		f = ft::make_pair(6,'f');
	// ft::pair<int, char>		f = ft::make_pair(6,'f');
	// ft::pair<int, char>		f = ft::make_pair(6,'f');
	// ft::pair<int, char>		f = ft::make_pair(6,'f');
	// ft::pair<int, char>		f = ft::make_pair(6,'f');

	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << c << std::endl;
	// std::cout << d << std::endl;
	// std::cout << e << std::endl;
	// std::cout << f << std::endl;
	// bst.insert(a);
	// bst.insert(b);
	// bst.insert(c);
	// bst.insert(d);
	// bst.insert(e);
	// bst.insert(f);
	bst.print_tree();
	bst.nb_black_nodes_all_leaves_paths();

}
