# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:02:02 by hlalouli          #+#    #+#              #
#    Updated: 2022/12/23 09:36:33 by hlalouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
INC = Cub3d.h get_next_line/get_next_line.h
SRCS = main.c \
        check_map.c\
        utils.c \
		utils1.c \
		utils2.c \
		utils3.c \
		utils4.c \
		utils5.c \
		utils6.c \
		ft_split.c \
		mlx_win.c \
        get_next_line/get_next_line_utils.c \
        get_next_line/get_next_line.c \
		move_player_mini_map.c \
		render.c \
		render_utils.c \
		player_positions.c \
		handler.c \
		img_3d.c \
		check_wall.c \
		check_wall_utils.c \
		wall_projection.c

OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all