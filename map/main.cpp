#include "map_RB_tree.hpp"

int main()
{
	ft::RB_tree<int, char>		bst;

	for (int i = 0; i < 30; i+=2)
	{
		ft::pair<int, char>		temp = ft::make_pair(i, i + 96);
		bst.insert(temp);
	}
	for (int i = 1; i < 30; i+=2)
	{
		ft::pair<int, char>		temp = ft::make_pair(i, i + 96);
		bst.insert(temp);
	}


	bst.print_tree();

	for (int i = 0; i < 15; i++)
	{
		ft::pair<int, char>		temp = ft::make_pair(i, i + 96);
		bst.delete_node(temp);
	}

	bst.print_tree();
	bst.nb_black_nodes_all_leaves_paths();

}
