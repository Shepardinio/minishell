NAME = minishell
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
LIBFT = ./libft/libft.a
SRC = 	src/main.c\
		src/builtins/cd/cd.c\
		src/builtins/echo/echo.c\
		src/builtins/env/env.c\
		src/builtins/export/export.c\
		src/builtins/export/export_utils.c\
		src/builtins/pwd/pwd.c\
		src/builtins/unset/unset.c\
		src/init/init_data.c\
		src/utils/free_fonction.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -lm $(OBJ) $(LIBFT) -o $(NAME) -g

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./libft
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all