# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/23 13:07:19 by aaugusti          #+#    #+#              #
#    Updated: 2020/03/23 13:53:53 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

all: $(NAME)

# All source of the application
SRCS			=	builtin/builtin_echo\
					error\
					get_cmd\
					main\
					prompt\
					run_cmd\

# Sources which are just needed for the bonus part
BONUS_SRCS		=	\

# These are files that need to be recompiled when the bonus is made
BONUS_RECOMP	=	\


CFILES			=	$(SRCS:%=src/%.c)
OFILES			=	$(SRCS:%=src/%.o)

BONUS_CFILES	=	$(BONUS_SRCS:%=src/%.c)
BONUS_OFILES	=	$(BONUS_SRCS:%=src/%.o)

BONUS_RECOMP_O	=	$(BONUS_RECOMP:%=src/%.o)


# Paths to the headeres which are needed
INCLUDES		=	-I include\
					-I lib/libft\
					-I lib/libgnl\
					-I lib/libftprintf\

# The location of al libraries
LIB_SRCS		=	lib/libft/libft.a\
					lib/libftprintf/libftprintf.a\
					lib/libgnl/libgnl.a\

FLAGS			=	-Wall -Werror -Wextra

# Ability to compile with maximum optimization
ifeq ($(FAST),1)
FLAGS			+= -Ofast
else
FLAGS			+= -O0
endif

# OS detection for libs and headers
UNAME_S			:=	$(shell uname -s)

ifeq ($(UNAME_S),Linux)
FLAGS			+=	-DLINUX
endif #Linux

ifeq ($(UNAME_S),Darwin)
endif #Darwin


TARGETS			=	$(OFILES) $(LIB_SRCS)

ifeq ($(BONUS),1)
TARGETS			+=	$(BONUS_OFILES)
FLAGS			+=	-DBONUS
endif #Bonus

# This means that the build before this one was indeed bonus, so we need to
# recompile the bonus-specific files and remove the bonus file.
ifeq ($(shell ls bonus 2> /dev/null),bonus)
TARGETS_EXTRA	= clean_bonus
endif #Last was bonus

# Another case in which we need to recompile the bonus files. This is true when
# we build the bonus, but the previous build was not bonus.
ifeq ($(BONUS),1)
ifneq ($(shell ls bonus 2> /dev/null),bonus)
TARGETS_EXTRA	= clean_bonus
endif #Last was bonus
endif #Bonus 

clean_bonus:
	rm -f $(BONUS_RECOMP_O)
	rm -f bonus


$(NAME): $(TARGETS_EXTRA) $(TARGETS)
	$(CC) $(TARGETS) $(DYLIB) $(FLAGS) $(LIBS) -o $(NAME) -g

# Rule for compiling the bonus part of the program. We just remove the existing
# executable and recompile the normal program with the BONUS env. variable set
# to 1.
bonus:
	rm -f $(NAME)
	@BONUS=1 make $(NAME)
	@touch bonus


# Generic rule for compiling any C-file into an object file
%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES) $(LIBS) -g

# Generic rule for compiling libraries
%.a:
	make -C $(@D)

libft.a:
	make bonuc -C $(@D)

# Rules for cleaning files
clean:
	rm -f $(OFILES) $(BONUS_OFILES) src/main.o

fclean: clean
	rm -f $(NAME)
	rm -f bonus

re: fclean all
