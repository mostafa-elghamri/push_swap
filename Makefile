NAME    = push_swap
FLAGS   = -Wall -Wextra -Werror
LIB     = -L./libft -lft

SRCS    = Instructions.c push_swap.c quicksort2.c quicksort.c sort.c Utils_functions.c Utilis2_functions.c add_function.c slit.c hilper.c 
OBJS    = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME) $(LIB)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

