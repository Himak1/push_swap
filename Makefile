# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhille <jhille@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 18:05:04 by jhille        #+#    #+#                  #
#    Updated: 2021/12/17 15:40:02 by jhille        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

ALL_FILES = $(MAIN_FILES) $(OPERATION_FILES)\
			$(SORTING_FILES)

MAIN_FILES = push_swap.c\
			error_exit.c\
			input_conversion.c

OPERATION_FILES = swap_operations.c\
				push_operations.c\
				lst_2nd_to_last.c\
				rotate_operations.c\
				rotate_reverse_operations.c

SORTING_FILES = sorting/select_algo.c\
				sorting/sorting_3.c\
				sorting/sorting_4_5.c\
				sorting/insert_sort.c\
				sorting/insert_standardize.c\
				sorting/insert_push_chunk.c\
				sorting/move_to_top.c\
				sorting/sorting_utils.c

LIBFT = libft.a

CFLAGS = -Wextra -Wall -Werror

OBJ = $(ALL_FILES:.c=.o)
OBJDIR = obj

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) libft/$(LIBFT) -o $(NAME)

$(OBJDIR):
	mkdir obj

$(OBJDIR)/%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
		make bonus -C libft

clean:
	rm -f $(OBJ)
	make fclean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re make
