make re
make clean
clear
cc ./tests/binary_indices_tests.c -L. -l:./push_swap.a -o binary_indices_tests_main
./binary_indices_tests_main "5 1 3"