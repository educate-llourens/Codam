# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/11 17:51:04 by llourens      #+#    #+#                  #
#    Updated: 2025/03/07 20:42:39 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFTNAME = libft/libft.a
PRINTFNAME = printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
export CFLAGS
INCLUDES = -I./libft -I./printf -I.
VPATH = src utils libft printf testing
PUSHSWAPDIR = push_swap
PRINTFDIR = printf
LIBFTDIR = libft

SRCS = pipex.c \
	   02_input_and_cmd1.c \
	   03_output_and_cmd2.c \
	   get_cmd_path.c \
	   error_handling.c \
	   input_checks.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)
debug: CFLAGS += -g3 -fsanitize=address
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
	@rm -f $(NAME) files
	@make -C $(PRINTFDIR) fclean
    
re: fclean all