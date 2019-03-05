# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkelest <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/25 16:09:58 by tkelest           #+#    #+#              #
#    Updated: 2018/08/03 17:21:44 by tkelest          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rc
RANLIB  = ranlib

NAME    = libft.a
HEAD    = libft.h
SRC     = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c \
ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_strcat.c ft_strchr.c ft_strcmp.c \
ft_strcpy.c ft_strdup.c \
ft_strlcat.c ft_strlen.c ft_strncat.c ft_strnstr.c \
ft_strncmp.c ft_strncpy.c ft_strrchr.c \
ft_strstr.c ft_tolower.c ft_toupper.c \
ft_memalloc.c ft_memdel.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
ft_putendl.c ft_putstr_fd.c ft_putstr.c ft_strclr.c \
ft_strdel.c ft_strequ.c ft_strjoin.c ft_strnequ.c ft_strnew.c ft_strsub.c \
ft_itoa.c ft_putnbr_fd.c ft_putnbr.c ft_striter.c ft_striteri.c ft_strmap.c \
ft_strmapi.c ft_strsplit.c ft_strtrim.c \
ft_isspace.c ft_isspaceall.c ft_wordcount.c ft_wordlen.c ft_strnlen.c \
ft_lstnew.c get_next_line.c ft_strsplittoint.c

OBJ     = $(SRC:.c=.o)

SRCDIR  = ./srcs/

OBJDIR  = ./objs/

INCDIR  = ./includes/

SRCS    = $(addprefix $(SRCDIR), $(SRC))

OBJS    = $(addprefix $(OBJDIR), $(OBJ))

INCS    = $(addprefix $(INCDIR), $(INC))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) -c $(SRCS) -I$(INCDIR)
		@mkdir -p $(OBJDIR)
		@mv $(OBJ) $(OBJDIR)
		@$(AR) $(NAME) $(OBJS)
		@$(RANLIB) $(NAME)
		@echo "[INFO] Library [$(NAME)] created!"

clean:
		@rm -rf $(OBJS)
		@rm -rf $(OBJDIR)
		@echo "[INFO] Objects removed!"

fclean: clean
		@rm -rf $(NAME)
		@echo "[INFO] Library [$(NAME)] removed!"

re:		fclean all
