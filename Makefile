NAME := FdF
NAME_BONUS := FdF_bonus
LIB := printf/ft_printf.h get_next_line.h
CFILES := end.c fdf_utils.c ft_atoi.c ft_bzero.c ft_split.c ft_strjointwo.c ft_strlcpy.c ft_strnstr.c get_next_line.c \
			get_next_line_utils.c fdf.c put_image.c render_image.c traces.c main.c
CBONUS :=  end.c fdf_utils.c ft_atoi.c ft_bzero.c ft_split.c ft_strjointwo.c ft_strlcpy.c ft_strnstr.c get_next_line.c \
			get_next_line_utils.c put_image.c fdf_bonus.c render_image.c traces.c main.c
OBONUS := $(CBONUS:%.c=%.o)
OFILES := $(CFILES:%.c=%.o)
CFLAGS := -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -I printf
CC := gcc
PRINTF := printf/libftprintf.a
all: $(NAME)

$(NAME): $(OFILES) $(LIB) fdf.h 
	$(MAKE) -C printf
	$(CC) $(OFILES) $(PRINTF) -o FdF $(CFLAGS)
bonus: $(OBONUS) $(LIB) fdf_bonus.h
	$(MAKE) -C printf
	$(CC) $(OBONUS) $(PRINTF) -o FdF_bonus $(CFLAGS)
%.o: %.c $(LIB)
	$(CC) -Wall -Wextra -Werror $< -c
clean:
	$(MAKE) -C printf clean
	rm -rf $(OFILES) $(OBONUS)
fclean: clean
	$(MAKE) -C printf fclean
	rm -rf $(NAME) $(NAME_BONUS)
re: fclean all

.PHONY:	clean fclean re all bonus