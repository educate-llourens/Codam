make re
make clean
clear
cc ./tests/tiny_sorts_tests.c -L. -l:./push_swap.a -o tiny_sorts_main
./tiny_sorts_main "5 1 3"