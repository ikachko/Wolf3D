#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikachko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 13:27:39 by ikachko           #+#    #+#              #
#    Updated: 2018/03/31 13:27:39 by ikachko          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
HEAD = includes/
RM = rm -f
SRC =	ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_memchr.c			\
		ft_memcmp.c 		\
		ft_strlen.c 		\
		ft_strdup.c 		\
		ft_strcpy.c 		\
		ft_strncpy.c 		\
		ft_strcat.c 		\
		ft_strncat.c 		\
		ft_strlcat.c 		\
		ft_strchr.c 		\
		ft_strrchr.c 		\
		ft_strstr.c 		\
		ft_strnstr.c 		\
		ft_strcmp.c 		\
		ft_strncmp.c 		\
		ft_atoi.c 			\
		ft_isalpha.c 		\
		ft_isdigit.c 		\
		ft_isalnum.c 		\
		ft_isascii.c 		\
		ft_isprint.c 		\
		ft_iswhitespace.c	\
		ft_toupper.c 		\
		ft_tolower.c 		\
		ft_pow.c 			\
		ft_memalloc.c 		\
		ft_memdel.c 		\
		ft_strnew.c 		\
		ft_strdel.c 		\
		ft_strclr.c 		\
		ft_striter.c 		\
		ft_striteri.c 		\
		ft_strmap.c 		\
		ft_strmapi.c 		\
		ft_strequ.c 		\
		ft_strnequ.c 		\
		ft_strsub.c 		\
		ft_strjoin.c 		\
		ft_strtrim.c 		\
		ft_strsplit.c 		\
		ft_itoa.c 			\
		ft_putchar.c 		\
		ft_putstr.c 		\
		ft_putendl.c 		\
		ft_putnbr.c 		\
		ft_putchar_fd.c 	\
		ft_putstr_fd.c 		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c 		\
		ft_intdigitsize.c	\
		ft_lstnew.c			\
		ft_lstdelone.c 		\
		ft_lstdel.c 		\
		ft_lstadd.c 		\
		ft_lstiter.c 		\
		ft_lstmap.c			\
		ft_strrev.c			\
		ft_lstaddback.c		\
		ft_list_size.c 		\
		ft_list_last.c		\
		get_next_line.c		\
		ft_count_words.c	\
		ft_strtol.c			
CC = gcc $(FLAGS)
OBJ = $(SRC:.c=.o)
INC = -I.
HEAD = libft.h 
FLAGS = -Wall -Wextra -Werror
C_MAGENTA = \033[35m
C_RED = \033[31m
C_MAGENTA = \033[35m
C_NONE = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $@ $^
		@ranlib $@
		@printf "$(C_MAGENTA)LIBFT:$(C_NONE) %-25s$(C_GREEN) [done]$(C_NONE)\n" $@
%.o : %.c libft.h
		@$(CC) -c $(INC) $< -o $@
		@printf "$(C_MAGENTA)LIBFT:$(C_NONE) %-25s$(C_GREEN) [done]$(C_NONE)\n" $@
clean:
		@$(RM) $(OBJ)
		@printf "$(C_MAGENTA)LIBFT:$(C_NONE) %-25s$(C_RED) [done]$(C_NONE)\n" $@
fclean: clean
		@$(RM) $(NAME)
		@printf "$(C_MAGENTA)LIBFT:$(C_NONE) %-25s$(C_RED) [done]$(C_NONE)\n" $@
re: fclean all