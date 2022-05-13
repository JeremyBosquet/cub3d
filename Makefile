# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbosquet <jbosquet@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 21:39:42 by mmosca            #+#    #+#              #
#    Updated: 2022/03/11 19:43:17 by jbosquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ~~ ---------------------------- Properties ---------------------------- ~~ ##

include		config/sources.mk

.PHONY:		all bonus clean fclean libraries norm re test

NAME	:=	cub3D
NAMEB	:=	cub3D_bonus

APATH	:=	assets
IPATH	:=	inc
LPATH	:=	libs
OPATH	:=	.objs
VPATH	:=	src/:src/controller/:src/hud/:src/parsing/:src/parsing/treat/:src/raycasting/:src/structures/:src/utils/

LIBFT	:=	$(LPATH)/libft
MLX		:=	$(LPATH)/minilibx

CFLAGS	:=	-Wall -Wextra -Werror -O2 -pipe
IFLAGS	:=	-I $(IPATH) -I $(LIBFT)/$(IPATH) -I $(MLX)
LFLAGS	:=	-framework Appkit -framework OpenGL

LIBS	:=	$(MLX)/libmlx.a $(LIBFT)/libft.a

OBJS	:=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
OBJSB	:=	$(addprefix $(OPATH)/, $(SRCSB:.c=.o))

INC		:=										\
	$(addprefix $(IPATH)/, cub3d.h)				\
	$(addprefix $(IPATH)/, enums.h)				\
	$(addprefix $(IPATH)/, key.h)				\
	$(addprefix $(IPATH)/, prototypes.h)		\
	$(addprefix $(IPATH)/, structures.h)		\
	$(addprefix $(IPATH)/, verbose.h)			\
	$(addprefix $(LIBFT)/inc/, libft.h)			\
	$(addprefix $(LIBFT)/, libft.a)				\
	$(addprefix $(MLX)/, mlx.h)					\
	$(addprefix $(MLX)/, mlx_int.h)				\
	$(addprefix $(MLX)/, mlx_new_window.h)		\
	$(addprefix $(MLX)/, mlx_opengl.h)			\
	$(addprefix $(MLX)/, mlx_png.h)				\
	$(addprefix $(MLX)/, libmlx.a)

## ~~ ------------------------------- Rules ------------------------------- ~~ ##

#~~~~ Main Rules ~~~~#

all:	libraries $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(LIBS) $^ -o $@

$(NAMEB):	$(OBJSB)
	$(CC) $(CFLAGS) $(LFLAGS) $(LIBS) $^ -o $@

libraries:
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)

re:	fclean all

bonus:	libraries $(NAMEB)

norm:
	@norminette $(IPATH) src/ $(LIBFT)

#~~~~ Compilation Rules ~~~~#

$(OPATH)/%.o:	%.c $(INC) config/sources.mk Makefile
	@mkdir -p $(dir $@);
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

#~~~~ Cleaning Rules ~~~~#

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT)
	$(MAKE) clean -C $(MLX)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAMEB)
	$(MAKE) fclean -C $(LIBFT)
