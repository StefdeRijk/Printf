NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

OBJS = $(FILES:.c=.o)

FILES =	ft_printf.c\
		ft_char.c\
		ft_string.c\
		ft_pointer.c\
		ft_int.c\
		ft_unsigned_int.c\
		ft_unsigned_hex.c\

%.o : %.c
		@$(CC) $(FLAGS) -c $<
		@echo "Compiling $<"

$(NAME): $(OBJS)
	@ar -cr $(NAME) $(OBJS)
	@echo "Creating archive file"

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "Removing object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removing archive file"

re: fclean all

.PHONY: all clean fclean re