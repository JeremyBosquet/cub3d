# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbosquet <jbosquet@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 01:04:33 by mmosca            #+#    #+#              #
#    Updated: 2022/03/05 21:11:06 by jbosquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ~~ ---------------------------- Properties ---------------------------- ~~ ##

include		config/sources.mk

.PHONY:		all clean fclean re

NAME	:=	libft.a

IPATH	:=	inc
OPATH	:=	.objs
VPATH	:=	src/:src/ctype/:src/stdlib/:src/string/:src/strings/:src/utils/:src/utils/lists/

CFLAGS	:=	-Wall -Wextra -Werror -O2 -pipe #-march=native
IFLAGS	:=	-I $(IPATH)
RFLAGS	:=	rcs

## ~~ ----------------------------- Objects ------------------------------ ~~ ##

OBJS	:=			\
	$(addprefix $(OPATH)/, $(SRCS:.c=.o))

## ~~ ----------------------------- Headers ------------------------------ ~~ ##

INC		:=									\
	$(addprefix $(IPATH)/, libft.h)			\
	$(addprefix $(IPATH)/, ft_enums.h)		\
	$(addprefix $(IPATH)/, ft_prototypes.h)	\
	$(addprefix $(IPATH)/, ft_structures.h)	\
	$(addprefix $(IPATH)/, ft_verbose.h)

## ~~ ------------------------------- Rules ------------------------------- ~~ ##

#~~~~ Main Rules ~~~~#

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(RFLAGS) $@ $^

re:	fclean all

#~~~~ Compilation Rules ~~~~#

$(OPATH)/%.o:	%.c $(INC) config/sources.mk Makefile
	@mkdir -p $(dir $@);
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

#~~~~ Cleaning Rules ~~~~#

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
