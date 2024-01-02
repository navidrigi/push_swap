CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address
SRC_FILES	=	$(wildcard *.c)
OBJ_DIR     =   obj
OBJ_FILES 	=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
NAME		=	push_swap

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "\033[1;33m🎉 Compilation \033[1;32mSUCCESS! 🎉\033[0m"

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
	rmdir $(OBJ_DIR)

re: fclean all
