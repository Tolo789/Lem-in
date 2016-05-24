
NAME = lem-in

SDIR = src/

SRC =	$(SDIR)main.c \
		$(SDIR)get_env.c \
		$(SDIR)get_rooms.c \
		$(SDIR)get_connections.c \
		$(SDIR)print_funct.c \
		$(SDIR)get_paths.c \
		$(SDIR)save_path.c \
		$(SDIR)get_options.c \
		$(SDIR)resolve.c \
		$(SDIR)sort_paths.c \
		$(SDIR)tools.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I .

CC = gcc

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L libft -lft
	@echo "				lem-in created"

lib:
	@make -C libft

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJ)
	@echo "				All lem-in's .o deleted"

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@echo "				lem-in deleted"

re: fclean all

.PHONY: all lib clean fclean re