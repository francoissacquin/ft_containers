#!/bin/zsh

make fclean
make time_bench
./std_containers > log_1
./ft_containers > log_2
diff log_1 log_2
rm log_1 log_2
make fclean
