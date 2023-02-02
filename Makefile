# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 10:32:25 by mparisse          #+#    #+#              #
#    Updated: 2023/02/02 12:18:51 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_of_life

SRCS = main.c cours_jm_moha_rayan.c


OBJS = ${SRCS:.c=.o}

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

LIBS = libmlx_Linux.a libft.a -lm -lX11 -lXext  

all : $(NAME)

YELLOW = \033[0;93m

$(NAME) : ${OBJS}
	@echo "$(YELLOW)Compiling mlx"
	@make --no-print-directory -C mlx_linux/ 
	@echo "Compiling libft"
	@cp mlx_linux/libmlx_Linux.a .
	@make --no-print-directory -C libft 
	@cp libft/libft.a . 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Bien joue!"

.c.o :
	${CC} -Wall -Werror -Wall -c $< -o ${<:.c=.o}

norme :
	norminette $(SRCS) fractol.h libft

clean : 
	make -C libft/ clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf libmlx_Linux.a libft.a

re : fclean $(NAME)

.PHONY : all clean fclean re libft mlx_linux
#.SILENT : all clean fclean re $(OBJS)
