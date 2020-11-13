# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aaugusti <aaugusti@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/29 14:26:30 by aaugusti      #+#    #+#                  #
#    Updated: 2020/10/29 14:28:15 by aaugusti      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	liblist.a

SRCS			=	\
					destroy\
					find_parent\
					foreach\
					last\
					new\
					new_back\
					new_front\
					remove\
					reverse\
					size\


CFILES			=	$(SRCS:%=lst_%.c)
OFILES			=	$(SRCS:%=lst_%.o)

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
	@rm -f $(OFILES)

re: fclean all
