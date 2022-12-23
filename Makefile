# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 22:01:42 by hel-ayac          #+#    #+#              #
#    Updated: 2020/02/15 22:08:28 by hel-ayac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
NAMELIBFT= libft/libft.a
SRCS= ft_printf.c ft_printf_handler.c get_content.c parsedata.c getdata.c\
	  tools.c ft_printresult.c ft_printf_utils.c
OBJ= $(SRCS:.c=.o)
FLG= -Wall -Wextra -Werror
INCLUDE= ft_printf.h

all: $(NAMELIBFT) $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)

$(NAMELIBFT): 
	make -C libft/ all

clean:
	@/bin/rm -f $(OBJ)
	@echo "clean"

cleanlibft:
	@make -C libft/ clean

fclean: fcleanlibft clean
	@/bin/rm -f $(NAME)
	@echo "fclean"

fcleanlibft:
	@make -C libft/ fclean

%.o: %.c 
	gcc $(FLG) -c $< -I $(INCLUDE) 

re : relibft fclean all

relibft:
	@make -C libft/ re

