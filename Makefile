NAME = so_long
CC = cc
CCFLAGS = -Wall -Wextra -Werror
CFLAGS  = -Iincludes
LDFLAGS = -L/home/hawild/.local/lib -lmlx_Linux -lXext -lX11

SRC = ./src/input_check.c\
./src/get_next_line.c\
./src/get_next_line_utils.c\
./src/main.c\
./src/ft_split.c\
./src/map_check.c\
./src/path_check.c\
./src/flood_fill.c\

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
