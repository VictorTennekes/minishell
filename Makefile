# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/23 13:07:19 by aaugusti          #+#    #+#              #
#    Updated: 2020/03/31 16:53:53 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

all: $(NAME)

# All source of the application
SRCS			=	\
					builtin/builtin_echo\
					builtin/builtin_exit\
					error\
					get_cmd\
					parser/parser\
					parser/parser_cases\
					parser/parser_functions\
					prompt\
					run_cmd\
					utils/file_wrapper\

# Sources which are just needed for the bonus part
BONUS_SRCS		=	\

# These are files that need to be recompiled when the bonus is made
BONUS_RECOMP	=	\

TEST_SRCS		=	\
					parser/parser\
					parser/parser_file\
					parser/parser_rand\
					parser/parser_single\


OFILES			=	$(SRCS:%=src/%.o)
BONUS_OFILES	=	$(BONUS_SRCS:%=src/%.o)
BONUS_RECOMP_O	=	$(BONUS_RECOMP:%=src/%.o)
TEST_OFILES		=	$(TEST_SRCS:%=tests/%.o)


# Paths to the headeres which are needed
INCLUDES		=	\
					-I include\
					-I lib/libft\
					-I lib/libftprintf\
					-I lib/libgnl\
					-I lib/libstring\
					-I lib/libvla\

# The location of al libraries
LIB_SRCS		=	\
					lib/libft/libft.a\
					lib/libftprintf/libftprintf.a\
					lib/libgnl/libgnl.a\
					lib/libstring/libstring.a\
					lib/libvla/libvla.a\

FLAGS			=	-Wall -Werror -Wextra

# Ability to compile with maximum optimization
ifeq ($(DEBUG),1)
FLAGS			+= -g -Og -fsanitize=address -fno-stack-protector
else
FLAGS			+= -Ofast
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


$(NAME): $(TARGETS_EXTRA) $(TARGETS) src/main.o
	$(CC) $(TARGETS) src/main.o $(FLAGS) -o $(NAME)

test: $(NAME) $(LIB_SRCS) $(TEST_OFILES) tests/main.o
	$(CC) $(TARGETS) $(TEST_OFILES) $(LIB_SRCS) tests/main.o $(FLAGS) -o test lib/libft/libft.a

# Rule for compiling the bonus part of the program. We just remove the existing
# executable and recompile the normal program with the BONUS env. variable set
# to 1.
bonus:
	rm -f $(NAME)
	@BONUS=1 make $(NAME)
	@touch bonus


# Generic rule for compiling any C-file into an object file
%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS) $(INCLUDES)

# Generic rule for compiling libraries
%.a:
	make -C $(@D)

lib/libft/libft.a:
	make bonus -C $(@D)

# Rules for cleaning files
clean:
	make clean -C lib/libft
	make clean -C lib/libftprintf
	make clean -C lib/libgnl
	make clean -C lib/libstring
	make clean -C lib/libvla
	rm -f $(OFILES) $(BONUS_OFILES) $(TEST_OFILES) src/main.o tests/main.o

fclean: clean
	make fclean -C lib/libft
	make fclean -C lib/libftprintf
	make fclean -C lib/libgnl
	make fclean -C lib/libstring
	make fclean -C lib/libvla
	rm -f $(NAME) test
	rm -f bonus

re: fclean all

testre: fclean test
