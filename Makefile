.PHONY: all clean fclean re

CC = cc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = push_swap
B_NAME = checker

CFILES = Mandatory/main.c\
		 Mandatory/algo_moves.c\
		 Mandatory/algo_sort.c\
		 Mandatory/algo_three_sort.c\
		 Mandatory/algo_utils.c\
		 Mandatory/build_stack.c\
		 Mandatory/build_stack_utils.c\
		 Mandatory/check_input.c\
		 Mandatory/error_handle.c\
		 Mandatory/Free_handle.c\
		 Mandatory/rules_push.c\
		 Mandatory/rules_rotate.c\
		 Mandatory/rules_rrotate.c\
		 Mandatory/rules_swap.c\
		 Mandatory/utils.c

BFILES = Bonus/checker_bonus.c\
		 Bonus/rules_push_bonus.c\
		 Bonus/rules_rotate_bonus.c\
		 Bonus/rules_rrotate_bonus.c\
		 Bonus/rules_swap_bonus.c\
		 Bonus/utils_bonus.c\
		 Bonus/Free_handle_bonus.c\
		 Bonus/error_handle_bonus.c\
		 Bonus/check_input_bonus.c\
		 Bonus/build_stack_bonus.c\
		 Bonus/build_stack_utils_bonus.c\
		 Bonus/get_next_line.c\
		 Bonus/get_next_line_utils.c
		 
OBJ = $(patsubst %.c, %.o, $(CFILES))
B_OBJ = $(patsubst %.c, %.o, $(BFILES))

all: $(NAME)

libft/libft.a:
	make -C libft

$(OBJ): %.o: %.c Mandatory/push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : libft/libft.a $(OBJ) Mandatory/push_swap.h
	$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

bonus : $(B_NAME)

$(B_OBJ): %.o: %.c Bonus/checker_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

$(B_NAME) : libft/libft.a $(B_OBJ) Bonus/checker_bonus.h
	$(CC) $(FLAGS) $(B_OBJ) libft/libft.a -o $(B_NAME)

clean:
	$(RM) $(OBJ) $(B_OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) $(B_NAME)
	make -C libft fclean

re: fclean all