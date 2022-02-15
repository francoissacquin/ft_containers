#include "RB_tree.hpp"

int main()
{
	ft::RB_tree<int, char>		bst;
	ft::pair<int, char>		a = ft::make_pair(1,'a');
	ft::pair<int, char>		b = ft::make_pair(8,'w');
	ft::pair<int, char>		c = ft::make_pair(12,'r');
	ft::pair<int, char>		d = ft::make_pair(4,'c');
	ft::pair<int, char>		e = ft::make_pair(7,'p');
	ft::pair<int, char>		f = ft::make_pair(-1,'s');
	bst.insert(a);
	bst.insert(b);
	bst.insert(c);
	// bst.insert(d);
	// bst.insert(e);
	// bst.insert(f);
	bst.print_tree();

}
