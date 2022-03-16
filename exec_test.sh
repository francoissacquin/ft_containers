#!/bin/zsh

make fclean
make vector
make map
make stack
make set_
./ft_vector > log_1
./std_vector > log_2
diff log_1 log_2 > log_final
if [ -s log_final ]
then
	echo "vector : \e[91m❌\e[0m"
else
	echo "vector : \e[92m✅\e[0m"
fi
rm log_1 log_2 log_final

./ft_map > log_1
./std_map > log_2
diff log_1 log_2 > log_final
if [ -s log_final ]
then
	echo "map    : \e[91m❌\e[0m"
else
	echo "map    : \e[92m✅\e[0m"
fi
rm log_1 log_2 log_final

./ft_stack > log_1
./std_stack > log_2
diff log_1 log_2 > log_final
if [ -s log_final ]
then
	echo "stack  : \e[91m❌\e[0m"
else
	echo "stack  : \e[92m✅\e[0m"
fi
rm log_1 log_2 log_final

./ft_set > log_1
./std_set > log_2
diff log_1 log_2 > log_final
if [ -s log_final ]
then
	echo "set    : \e[91m❌\e[0m"
else
	echo "set    : \e[92m✅\e[0m"
fi
rm log_1 log_2 log_final

make --silent fclean
