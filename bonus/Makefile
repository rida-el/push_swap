NAME		= checker

	
CC			= cc
# FLAGS		= -Wall -Wextra -Werror -I$(LIBDIR) $(TH)
FLAGS		= -Wall -Wextra -Werror -I$(LIBDIR)

FILES		=	checks/stack_is_empty.c \
				stack/new_node.c 

STACK		= $(addprefix stack/, new_node pop_node_top pop_node_bottom push_node_top push_node_bottom stack_init print_stack stack_is_sorted)
MOVES		= $(addprefix moves/, pa pb ra rb rr rra rrb rrr sa sb ss)
CHECKS		= $(addprefix checks/, stack_is_empty)
FREE		= $(addprefix free/, free_stack free_split free_utils)
INPUT		= $(addprefix input/, is_valid_input is_valid_individual_input parse_input)

# BONUS
CHECKER		= get_next_line

SRCS		= $(STACK) $(MOVES) $(CHECKS) $(FREE) $(CHECKER) $(INPUT) main ft_strcmp exit_error

LIBDIR := libft
LIB := libft.a

OBJ			= $(SRCS:=.o)
HEADER		= ./push_swap.h

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@


$(NAME):  $(LIB) $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME) 


bonus: $(NAME)


clean :
	rm -rf $(OBJ) main.o

fclean : clean
	rm -rf $(NAME) $(BONUS) $(LIB)

re : fclean bonus

$(LIB):
	$(MAKE) -C $(LIBDIR)
	mv $(LIBDIR)/$(LIB) $(LIB)
	$(MAKE) -C $(LIBDIR) fclean