#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 16:32:46 by ahjadani          #+#    #+#              #
#    Updated: 2021/12/31 14:05:21 by ahjadani         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FILES =	lib/ft_addstr.c lib/ft_atoi.c lib/ft_bubble_sort.c lib/ft_bzero.c lib/ft_calloc.c lib/ft_check_is_sorted.c lib/ft_check_stack.c lib/ft_error_handler.c lib/ft_find_in_stack.c lib/ft_find_max.c lib/ft_find_min.c lib/ft_get_index.c lib/ft_is_duplicate.c lib/ft_is_valid.c lib/ft_isdigit.c lib/ft_isspace.c lib/ft_lstadd_back.c lib/ft_lstadd_front.c lib/ft_lstlast.c lib/ft_lstnew.c lib/ft_lstsize.c lib/ft_memset.c lib/ft_sort_args.c lib/ft_split.c lib/ft_stack_creator.c lib/ft_strcmp.c lib/ft_strdup.c lib/ft_strjoin.c lib/ft_strlen.c lib/ft_strncpy.c lib/ft_strndup.c lib/instra_push.c lib/instra_rev_rotate.c lib/instra_rotate.c lib/instra_swap.c

BONUS_FILES = checker_/checker.c checker_/get_next_line.c checker_/get_next_line_utils.c checker_/verify_instra.c

CFLAGS = -Werror -Wextra -Wall

OBJECTS = $(FILES:.c=.o)

BONUS_OBJECTS = $(BONUS_FILES:.c=.o)

NAME = push_swap
CHECKER = checker
CC = cc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) push_swap.c -o $(NAME)


bonus: $(CHECKER)

$(CHECKER) : $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) checker/$(BONUS_OBJECTS) -o $(CHECKER)

lib/%.o:%.c
	$(CC) $(CFLAGS) -c $^

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all, clean, fclean, re, startall, bonus