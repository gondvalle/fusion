# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdel-val <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 18:38:42 by gdel-val          #+#    #+#              #
#    Updated: 2023/10/03 18:39:10 by gdel-val         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CCFLAGS = -Wall -Werror -Wextra # FLAGS

SRCs = ft_isalpha.c \
  ft_isdigit.c \
  ft_isalnum.c \
  ft_isascii.c \
  ft_isprint.c \
  ft_strlen.c \
  ft_memset.c \
  ft_bzero.c \
  ft_memcpy.c \
  ft_memmove.c \
  ft_strlcpy.c \
  ft_strlcat.c \
  ft_toupper.c \
  ft_tolower.c \
  ft_strchr.c \
  ft_strrchr.c \
  ft_strncmp.c \
  ft_memchr.c \
  ft_memcmp.c \
  ft_strnstr.c \
  ft_atoi.c \
  ft_calloc.c \
  ft_strdup.c \
  ft_substr.c \
  ft_strjoin.c \
  ft_strtrim.c \
  ft_split.c \
  ft_itoa.c \
  ft_strmapi.c \
  ft_striteri.c \
  ft_putchar_fd.c \
  ft_putstr_fd.c \
  ft_putendl_fd.c \
  ft_putnbr_fd.c \
  get_next_line_utils.c \
  get_next_line.c \

OBJS = $(SRCs:.c=.o) # cambia el nombre a los *.c por .o

BONUS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar crs $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@ar crs $(NAME) $(OBJS) $(BONUS_OBJS)

#bonus: $(NAME)

%.o : %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(OBJS) $(NAME)

re: fclean all # Esto practicamente borra todo y crea de nuevo todo.

#el phony se utiliza para indicar a Make que la regla debe ejecutarse siempre que se invoque,
#independientemente de si existe un archivo con el mismo nombre.

.PHONY: norma test clean fclean re all
