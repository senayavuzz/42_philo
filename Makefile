SRC = 	main.c   \
		init.c   \
		status.c \
		dinner.c \
		tools.c
		
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAG = -Wall -Wextra -Werror  -fsanitize=address
RM = rm -rf
NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(CFLAG) -pthread -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
