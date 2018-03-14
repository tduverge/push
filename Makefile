# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kbedene <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/27 09:15:15 by kbedene      #+#   ##    ##    #+#        #
#    Updated: 2018/03/14 16:57:22 by kbedene     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CHECKR = checker

PSHSWP = push_swap

LIB = libft_rule

CHECKR_SRC_FILES = \
				main.c\
				parse.c\
				actions.c\
				apply_actions.c\
				display.c\
				check_io.c

PSHSWP_SRC_FILES = \
				main.c\
				parse.c\
				actions.c\
				apply_actions_pshswp.c\
				premade_moves.c\
				insertion_sort.c\
				simple_sort.c\
				simple_sort_b.c\
				quicksort.c\
				quick_a.c\
				quick_b.c\
				sort_3.c\
				change_to_index.c\
				get_elem_at_index.c\
				ft_lstis_sorted.c\
				ft_lstis_sorted_b.c

CHECKR_SRC = $(addprefix src_checker/, $(CHECKR_SRC_FILES))

PSHSWP_SRC = $(addprefix src_push_swap/, $(PSHSWP_SRC_FILES))

CHECKR_OBJ = $(CHECKR_SRC:.c=.o)

PSHSWP_OBJ = $(PSHSWP_SRC:.c=.o)

LIBFT = ./libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -ggdb

.PHONY: all clean fclean re $(LIB)

all: $(LIB) $(CHECKR) $(PSHSWP)

$(LIB):
	@make -C libft/

$(CHECKR): $(CHECKR_OBJ) $(PSHSWP_OBJ)
	@$(CC) $(FLAGS) $(CHECKR_OBJ) $(LIBFT) -o $(CHECKR)
	@$(CC) $(FLAGS) $(PSHSWP_OBJ) $(LIBFT) -o $(PSHSWP)
	@echo "\033[32mchecker and push_swap created.\033[0m"

./src_checker/%.o: ./src_checker/%.c
	@$(CC) $(FLAGS) -c $< -o $@

./src_push_swap/%.o: ./src_push_swap/%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(CHECKR_OBJ) $(PSHSWP_OBJ)
	@make clean -C ./libft
	@echo "\033[31mObjects deleted.\033[0m"

fclean: clean
	@/bin/rm -f $(CHECKR) $(PSHSWP)
	@/bin/rm -f $(LIBFT)
	@echo "\033[31mbinaries deleted.\033[0m"

re: fclean all
