# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 10:43:01 by tuytters          #+#    #+#              #
#    Updated: 2021/08/26 14:37:56 by tuytters         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftps.a

LIBFT	=		libft.a

CC 		=		gcc

DIR_LIBFT	=	./libft/
DIR_SRC		=	./
DIR_HEADERS =	./

CFLAGS	=		-Wall -Wextra -Werror 

SRCS	=		push_swap.c		\
				error.c			\
				move_s_p.c		\
				move_r.c		\
				tri.c			\
				radixsort.c		\
				solver3.c		\
				solver5.c		\
				free.c			\
				max_min_mid.c

OUT		=		push_swap

OBJS	=		$(SRCS:.c=.o)

MAIN	=		push_swap.c

RM		=		rm -f

all		:		$(NAME)

$(NAME)	:		$(OBJS)
				@$(MAKE) -s -C $(DIR_LIBFT)
				@$(CC) $(OBJS) -L$(DIR_LIBFT) -lft -o $(OUT)

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

test	:		fclean $(NAME)
					@$(CC) -o $(OUT) $(MAIN) $(NAME)

clean	:
				@$(RM) $(OBJS)
				@make clean -C ./libft/

fclean	:		clean
				@$(RM) $(NAME) $(OUT)
				@make fclean -C ./libft/

re		:		fclean all
.PHONY	:		all clean fclean re	test bonus