CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address
SRC_FILES	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c \
				ft_lstnew.c ft_lstsize.c ft_atoi.c final_moves.c \
				push_swap.c push_to_list.c reverse_rotate.c rotate.c \
				sort.c swap.c input_values_checking.c \
				rotating_or_reverse_rotating.c ft_strcmp.c \
				if_stack_is_sorted.c ft_isdigit.c indexing.c \
				positioning.c cost_calculation.c
OBJ_FILES 	=	$(SRC_FILES:.c=.o)
NAME		=	push_swap

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "\033[1;33m🎉 Compilation \033[1;32mSUCCESS! 🎉\033[0m"

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
