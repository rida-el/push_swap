NAME		= checker

	
CC			= cc
# FLAGS		= -Wall -Wextra -Werror -I$(LIBDIR) $(TH)
FLAGS		= -Wall -Wextra -Werror -I$(LIBDIR)

FILES		=	checks/stack_is_empty.c \
				stack/new_node.c 

STACK		= $(addprefix stack/, new_node pop_node_top pop_node_bottom push_node_top push_node_bottom stack_init)
MOVES		= $(addprefix moves/, pa pb ra rb rr rra rrb rrr sa sb ss)
CHECKS		= $(addprefix checks/, stack_is_empty)
FREE		= $(addprefix free/, free_stack free_split free_utils)

# BONUS
CHECKER		= get_next_line

SRCS		= $(STACK) $(MOVES) $(CHECKS) $(FREE) $(CHECKER) main

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

re : fclean all $(BONUS)

$(LIB):
	$(MAKE) -C $(LIBDIR)
	mv $(LIBDIR)/$(LIB) $(LIB)
	$(MAKE) -C $(LIBDIR) fclean