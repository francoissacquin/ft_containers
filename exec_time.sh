#!/bin/zsh

make fclean
make time_bench
make time_bench_2
./std_time_vector > log_1
./ft_time_vector > log_2
echo "\033[0;36m __      ________ _____ _______ ____  _____  
 \ \    / /  ____/ ____|__   __/ __ \|  __ \ 
  \ \  / /| |__ | |       | | | |  | | |__) |
   \ \/ / |  __|| |       | | | |  | |  _  / 
    \  /  | |___| |____   | | | |__| | | \ \ 
     \/   |______\_____|  |_|  \____/|_|  \_\\ \n\033[0m"
diff -y log_1 log_2
rm log_1 log_2


./std_time_map > log_1
./ft_time_map > log_2
echo "\033[0;36m  __  __          _____  
 |  \/  |   /\   |  __ \ 
 | \  / |  /  \  | |__) |
 | |\/| | / /\ \ |  ___/ 
 | |  | |/ ____ \| |     
 |_|  |_/_/    \_\_|     \n\033[0m"
diff -y log_1 log_2
rm log_1 log_2


make --silent fclean
