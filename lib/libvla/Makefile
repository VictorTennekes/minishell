# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aaugusti <aaugusti@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/29 14:19:21 by aaugusti      #+#    #+#                  #
#    Updated: 2020/10/29 14:19:21 by aaugusti      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	libvla.a

SRCS			=	get\
					get_addr\
					get_index\
					init\
					memcpy\
					push\
					resize\
					set\
					shrink\


CFILES			=	$(SRCS:%=vla_%.c)
OFILES			=	$(SRCS:%=vla_%.o)

FLAGS			=	-Wall -Werror -Wextra -O3

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
	rm -f $(OFILES)

re: fclean all
