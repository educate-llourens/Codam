# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: root <root@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2025/01/02 15:29:05 by root          #+#    #+#                  #
#    Updated: 2025/10/21 15:49:31 by lelouren      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFTNAME = libft/libft.a
PRINTFNAME = printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
export CFLAGS
INCLUDES = -I./includes -I./libft -I./printf
VPATH = src utils libft printf
PUSHSWAPDIR = push_swap
PRINTFDIR = printf
LIBFTDIR = libft

SRCS = push_swap.c \
src/02_init_stack.c \
src/03_sort_three.c \
src/04_sort_five.c \
src/05_sort_hundred.c \
src/06_assign_binary_indices.c \
src/07_radix_sort.c \
utils/error_handling.c \
utils/validation_utils.c \
utils/linked_list_utils.c \
utils/stack_operations.c \
utils/rotate_operations.c \
utils/reverse_rotate_operations.c \
utils/push_operations.c \
utils/stack_smallsort_utils.c \
utils/assign_binary_indices_utils.c \
utils/sort_hundred_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
debug: CFLAGS += -g
debug: re

%.a:
	+$(MAKE) -C $(dir $@)

$(NAME): $(OBJS) $(PRINTFNAME)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTFNAME) -o $(NAME) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -f $(OBJS)
	@make -C $(PRINTFDIR) clean
    
fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTFDIR) fclean
    
re: fclean all