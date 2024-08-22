NAME = so_long

SRCS =  main.c \
        read_map.c \
        valid_map.c \
        char_check.c \
        pathfinder.c \
        render_map.c \
        image.c \
        key_hook.c \
        libft/get_next_line/get_next_line.c \
        libft/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
LIBFT = -L$(LIBFT_DIR) -lft

MLX = ./MLX42
LIBMLX = $(MLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADERS = -I $(MLX)/include

REPO_URL=https://github.com/codam-coding-college/MLX42.git
REPO_DIR=MLX42

# Default target
all: clone libmlx $(NAME)

# Clone MLX42 if not present
clone:
	@if [ ! -d "$(REPO_DIR)" ]; then \
		git clone $(REPO_URL); \
	else \
		echo "$(REPO_DIR) already exists."; \
	fi

# Build MLX42
libmlx:
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4

# Build the executable
$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	$(CC) $(OBJS) $(LIBFT) $(LIBMLX) $(HEADERS) -o $(NAME)

# Compile libft and ft_printf
$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(FT_PRINTF_DIR) all
	@$(MAKE) -C $(LIBFT_DIR) all
	@touch $(LIBFT_DIR)/libft.a

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

# Clean object files
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@rm -rf $(MLX)/build

# Clean all, including the executable
fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re libmlx clone
