NAME = libft.a

BSDIR = basic_src/

PFDIR = printf_src/

SRC =	$(BSDIR)ft_putchar.c \
		$(BSDIR)ft_putstr.c \
		$(BSDIR)ft_putendl.c \
		$(BSDIR)ft_putnbr.c \
		$(BSDIR)ft_putchar_fd.c \
		$(BSDIR)ft_putstr_fd.c \
		$(BSDIR)ft_putendl_fd.c \
		$(BSDIR)ft_putnbr_fd.c \
		$(BSDIR)ft_strlen.c \
		$(BSDIR)ft_strcpy.c \
		$(BSDIR)ft_strncpy.c \
		$(BSDIR)ft_strcat.c \
		$(BSDIR)ft_strncat.c \
		$(BSDIR)ft_strchr.c \
		$(BSDIR)ft_strrchr.c \
		$(BSDIR)ft_strstr.c \
		$(BSDIR)ft_strnstr.c \
		$(BSDIR)ft_isalpha.c \
		$(BSDIR)ft_isdigit.c \
		$(BSDIR)ft_isalnum.c \
		$(BSDIR)ft_isprint.c \
		$(BSDIR)ft_toupper.c \
		$(BSDIR)ft_tolower.c \
		$(BSDIR)ft_memalloc.c \
		$(BSDIR)ft_memdel.c \
		$(BSDIR)ft_isascii.c \
		$(BSDIR)ft_strnew.c \
		$(BSDIR)ft_strdel.c \
		$(BSDIR)ft_strclr.c \
		$(BSDIR)ft_striter.c \
		$(BSDIR)ft_striteri.c \
		$(BSDIR)ft_strmap.c \
		$(BSDIR)ft_strmapi.c \
		$(BSDIR)ft_strequ.c \
		$(BSDIR)ft_strnequ.c \
		$(BSDIR)ft_strsub.c \
		$(BSDIR)ft_strjoin.c \
		$(BSDIR)ft_strtrim.c \
		$(BSDIR)ft_strsplit.c \
		$(BSDIR)ft_atoi.c \
		$(BSDIR)ft_ctoa.c \
		$(BSDIR)ft_itoa.c \
		$(BSDIR)ft_itoa_mod.c \
		$(BSDIR)ft_itoa_mod2.c \
		$(BSDIR)ft_itoa_mod3.c \
		$(BSDIR)ft_ftoa.c \
		$(BSDIR)ft_lftoa.c \
		$(BSDIR)ft_strdup.c \
		$(BSDIR)ft_strcmp.c \
		$(BSDIR)ft_strncmp.c \
		$(BSDIR)ft_memset.c \
		$(BSDIR)ft_bzero.c \
		$(BSDIR)ft_memcpy.c \
		$(BSDIR)ft_memccpy.c \
		$(BSDIR)ft_memmove.c \
		$(BSDIR)ft_memchr.c \
		$(BSDIR)ft_strlcat.c \
		$(BSDIR)ft_memcmp.c \
		$(BSDIR)ft_lstnew.c \
		$(BSDIR)ft_lstdelone.c \
		$(BSDIR)ft_lstdel.c \
		$(BSDIR)ft_lstadd.c \
		$(BSDIR)ft_lstiter.c \
		$(BSDIR)ft_lstmap.c \
		$(BSDIR)ft_puterror.c \
		$(BSDIR)get_next_line.c \
		$(BSDIR)ft_itoa_base.c \
		$(BSDIR)ft_itoa_base_mod.c \
		$(BSDIR)ft_upstr.c \
		$(BSDIR)ft_pow.c \
		$(BSDIR)ft_abs.c \
		$(BSDIR)ft_sqr.c \
		$(PFDIR)ft_get_var.c \
		$(PFDIR)ft_get_options.c \
		$(PFDIR)ft_get_len_modif.c \
		$(PFDIR)ft_printf.c \
		$(PFDIR)ft_check_var.c \
		$(PFDIR)ft_check_value.c \
		$(PFDIR)ft_saveret.c \
		$(PFDIR)ft_get_value.c \
		$(PFDIR)ft_create_str.c \
		$(PFDIR)ft_apply_options.c \
		$(PFDIR)ft_wchar.c \
		$(PFDIR)ft_wstoa.c \
		$(PFDIR)ft_masks.c \
		$(PFDIR)ft_strdup_mod.c

OBJ =	$(SRC:.c=.o)

HEAD = libft.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@echo "				Compiled with succes !!"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "				libft.a created and listed"
clean:
	@/bin/rm -f $(OBJ)
	@echo "				All libft's .o deleted"
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "				libft.a deleted"
re: fclean all

.PHONY: all clean fclean re