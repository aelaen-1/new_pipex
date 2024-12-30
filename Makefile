NAME = pipe
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = processes.c \
	ft_split.c \
	ft_strjoin.c \
	exec.c

OBJ = $(SRC:.o=.c)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re