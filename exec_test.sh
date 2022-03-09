#!/bin/zsh

make re
./ft_containers > log_1
./std_containers > log_2
diff log_1 log_2
rm log_1 log_2
