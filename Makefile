NAME := fdf
LIB := printf/ft_printf.h get_next_line.h fdf.h
CFILES := end.c fdf_utils.c ft_atoi.c ft_bzero.c ft_split.c ft_strjointwo.c ft_strlcpy.c ft_strnstr.c get_next_line.c \
			get_next_line_utils.c fdf.c put_image.c render_image.c traces.c main.c
OFILES := $(CFILES:%.c=%.o)
CFLAGS := -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
CC := cc
PRINTF := printf/libftprintf.a
all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) -C printf
	$(CC) $(OFILES) $(PRINTF) -o fdf $(CFLAGS)
%.o: %.c $(LIB)
	$(CC) -Wall -Wextra -Werror $< -c
clean:
	$(MAKE) -C printf clean
	rm -rf $(OFILES) $(OBONUS)
fclean: clean
	$(MAKE) -C printf fclean
	rm -rf $(NAME) $(NAME_BONUS)
re: fclean all

.PHONY:	clean fclean re all