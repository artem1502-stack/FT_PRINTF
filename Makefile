CC := gcc
FLAG := -Wall -Wextra -c
CNAMES := ft_out_1.c ft_out_2.c ft_printf.c ft_utility_1.c ft_utility_2.c
ONAMES := $(CNAMES:.c=.o)
HNAMES := ft_printf.h
NAME := libftprintf.a
RM := rm -f
AR := ar r
all: obj $(NAME)

obj: $(CNAMES)

.c.o:
	$(CC) $(FLAG) $< -o $@

$(NAME): $(ONAMES)
	$(AR) $(NAME) $(ONAMES)

clean:
	$(RM) $(ONAMES) $(BONAMES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
