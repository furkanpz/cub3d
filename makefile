INCLUDES_MAC = -Imlx

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address


MLX_FLAGS_MAC = -Lmlx -lm -lmlx -framework OpenGL -framework AppKit 

SRCS = cub3d.c set_img.c lib/gnl/get_next_line.c lib/gnl/get_next_line_utils.c lib/libft/libft.a

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(INCLUDES_MAC) -c $< -o $@

$(NAME): $(OBJ)
	make -C mlx
	make -C lib/libft
	$(CC) $(OBJ) $(MLX_FLAGS_MAC) -o $(NAME) 

all: $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	make clean -C mlx
	rm -rf *.o
	rm -rf get_next_line/*.o

re: fclean all

.PHONY: all clean fclean re