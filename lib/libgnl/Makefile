# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: aaugusti <aaugusti@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 11:05:37 by aaugusti       #+#    #+#                 #
#    Updated: 2020/01/27 11:03:12 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libgnl.a

SRCS			=	get_next_line\
					get_next_line_utils

CFILES			=	$(SRCS:%=%.c)
OFILES			=	$(SRCS:%=%.o)

BONUS_CFILES	=	$(SRCS:%=%_bonus.c)
BONUS_OFILES	=	$(SRCS:%=%_bonus.o)

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
	rm -f bonus
	rm -f $(OFILES) $(BONUS_OFILES)

re: fclean all

bonus: $(OFILES) $(BONUS_OFILES) $(NAME)
	$(AR_COMMAND) $(NAME) $(OFILES) $(BONUS_OFILES)
	@touch bonus
