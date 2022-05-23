NAME		= push_swap
	
CC			= cc
# FLAGS		= -Wall -Wextra -Werror -I$(LIBDIR) $(TH)
FLAGS		= -Wall -Wextra -Werror -I$(LIBDIR)

FILES		=	checks/stack_is_empty.c \
				stack/new_node.c 

STACK		= $(addprefix stack/, new_node pop_node_top pop_node_bottom push_node_top push_node_bottom stack_init)
MOVES		= $(addprefix moves/, pa pb ra rb rr rra rrb rrr sa sb ss)
ALGO		= $(addprefix algo/, push_swap get_optimal_divisor)
CHECKS		= $(addprefix checks/, stack_is_empty)
FREE		= $(addprefix free/, free_stack free_split free_utils)

SRCS		= $(STACK) $(MOVES) $(CHECKS) $(ALGO) $(FREE) main

LIBDIR := libft
LIB := libft.a
# TH := -lpthread

# SRC			= $(SRCS:=.c)
OBJ			= $(SRCS:=.o)
HEADER		= ./push_swap.h

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@


$(NAME):  $(LIB) $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME) 



all: $(NAME)

clean :
	rm -rf $(OBJ) main.o
fclean : clean
	rm -rf $(NAME) $(LIB)
re : fclean all

$(LIB):
	$(MAKE) -C $(LIBDIR)
	mv $(LIBDIR)/$(LIB) $(LIB)
	$(MAKE) -C $(LIBDIR) fclean