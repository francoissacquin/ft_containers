#!/bin/zsh

make fclean
make vector
make map
make stack
make set_
valgrind ./ft_vector > log_1
valgrind ./std_vector > log_2
diff log_1 log_2 > log_final
if [ -s log_final ]
then
	echo "VECTOR : \e[91m❌\e[0m"
else
	echo "VECTOR : \e[92m✅\e[0m"
fi
rm log_1 log_2 log_final

valgrind ./ft_map > log_1
valgrind ./std_map > log_2
diff log_1 log_2 > log_final
if [ -s log_final ]
then
	echo "MAP    : \e[91m❌\e[0m"
else
	echo "MAP    : \e[92m✅\e[0m"
fi
rm log_1 log_2 log_final

valgrind ./ft_stack > log_1
valgrind ./std_stack > log_2
diff log_1 log_2 > log_final
if [ -s log_final ]
then
	echo "STACK  : \e[91m❌\e[0m"
else
	echo "STACK  : \e[92m✅\e[0m"
fi
rm log_1 log_2 log_final

valgrind ./ft_set > log_1
valgrind ./std_set > log_2
diff log_1 log_2 > log_final
if [ -s log_final ]
then
	echo "SET    : \e[91m❌\e[0m"
else
	echo "SET    : \e[92m✅\e[0m"
fi
rm log_1 log_2 log_final

make --silent fclean
