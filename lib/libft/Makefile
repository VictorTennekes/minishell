# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:    :+:             #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/08 19:44:01 by aaugusti          #+#    #+#              #
#    Updated: 2020/04/28 11:28:37 by aaugusti      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

SRCS			=	atoi\
					bzero\
					isalnum\
					isalpha\
					isascii\
					isdigit\
					isprint\
					memccpy\
					memchr\
					memcmp\
					memcpy\
					memmove\
					memset\
					strchr\
					strlcat\
					strlcpy\
					strlen\
					strncmp\
					strnstr\
					strrchr\
					tolower\
					toupper\
					calloc\
					itoa\
					putchar_fd\
					putendl_fd\
					putstr_fd\
					putnbr_fd\
					split\
					strjoin\
					strmapi\
					strtrim\
					substr\
					strdup\
					strcmp\

BONUS_SRCS		=	arrfree\
					arrlen\
					atoi_ui\
					atoi_ul\
					atoi_ull\
					cchr\
					hexlen\
					intlen\
					lstadd_back\
					lstadd_front\
					lstclear\
					lstcount_condition\
					lstdelone\
					lstiter\
					lstlast\
					lstmap\
					lstnew\
					lstsize\
					puthex_fd\
					putnbr_ll_fd\
					putstr_n_fd\
					putunsigned_fd\
					strdup_c\
					strldup\
					strlen_c\
					unsignedlen\
					xalloc\

CFILES			=	$(SRCS:%=ft_%.c)
OFILES			=	$(SRCS:%=ft_%.o)

BONUS_CFILES	=	$(BONUS_SRCS:%=ft_%_bonus.c)
BONUS_OFILES	=	$(BONUS_SRCS:%=ft_%_bonus.o)

FLAGS			=	-Wall -Werror -Wextra

AR_COMMAND		= ar rs

all: $(NAME)

$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS)

clean: _clean

fclean: _clean
	rm -f $(NAME)

_clean:
	@rm -f bonus
	rm -f $(OFILES) $(BONUS_OFILES)

re: fclean all

bonus: $(OFILES) $(BONUS_OFILES) $(NAME)
	$(AR_COMMAND) $(NAME) $(OFILES) $(BONUS_OFILES)
	@touch bonus
