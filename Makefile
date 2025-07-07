NAME 		= render
CF 			= -Wall -Wextra -Werror
CC 			= gcc -g
MLX_CF 		= -lm -lbsd -lmlx -lXext -lX11

MLX 		= libmlx_Linux.a
MLX_PATH 	= ./mlx_linux/
LIBFT 		= libft.a
LIBFT_PATH 	= ./libft/

SRC         = main.c \
              auxilary.c \
              read_map.c \
              draw_map.c \
              draw_menu.c \
              colouring.c \
              event_handlers.c \
              rotation_projection.c

SRC         := $(addprefix ./srcs/, $(SRC))

OBJ         = $(SRC:.c=.o)

RM =rm -f


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CF) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -L $(MLX_PATH) $(LIBFT_PATH)/$(LIBFT) $(MLX_CF)


%.o: %.c
	$(CC) $(CF) -I./include -c $< -o $@

$(MLX):
	make -C $(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make clean -C $(MLX_PATH)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: clean fclean re all 

