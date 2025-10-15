make re
make clean
clear
cc ./tests/operations_tests.c -L. -l:./push_swap.a -o ops_main
./ops_main