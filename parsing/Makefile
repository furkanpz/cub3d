NAME = cub3d

CC = gcc

SRCS = main.c


LIBFT = ../lib/libft/libft.a

GNL = ../lib/get_next_line/get_next_line.a

INCLUDES = -I../lib/get_next_line \
	-I../lib/libft -I./inc

CFLAGS = #-O3 -Wall -Wextra -Werror $(DEBUG)

MLX_FLAGS_LINUX = $(GNL) $(LIBFT) -Bdynamic -L/usr/lib/X11 \
	-lXext -lX11 -lm

MLX_FLAGS_MAC = $(GNL) $(LIBFT) -Bdynamic -framework OpenGL \
	-framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(GNL)
	@echo "Compiling CUB3D..."
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDES) -o $@ $?


$(LIBFT):
	@echo "Compiling Libft..."
	@cd lib/libft && make USE_MATH=TRUE > /dev/null

$(GNL):
	@echo "Compiling get_next_line..."
	@cd lib/get_next_line && make > /dev/null

run: $(NAME)
	./$(NAME)

.PHONY: all re fclean clean run
