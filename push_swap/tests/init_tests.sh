make re
make clean
clear
cc ./tests/init_tests.c -L. -l:./push_swap.a -o init_tests_main
./init_tests_main