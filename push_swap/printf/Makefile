NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS ?= -Wall -Werror -Wextra
LIBFTDIR = libft

SRCS =  ft_print_c.c ft_print_di.c ft_print_p.c ft_print_str.c ft_print_u.c ft_print_xx.c ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): $(OBJS) makelibft
	@ar -rcs $(NAME) $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all
