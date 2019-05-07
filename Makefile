# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aberneli <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/03 17:23:46 by aberneli     #+#   ##    ##    #+#        #
#    Updated: 2018/03/02 17:50:19 by aberneli    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean

NAME = rtv1

SRCS = main.c vector.c viewplane.c scene_loader.c console.c elements.c init.c \
	   loader_routines_1.c input.c sphere.c ray.c render.c list_manage.c \
	   calc.c plane.c tools.c inter.c color.c cylinder.c loader_routines_2.c \
	   cone.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

INC = -I minilibx_macos -I libft

HEADERS = rtv1.h

LIBS_FLAGS = -framework OpenGL -framework AppKit

LIBS = minilibx_macos/libmlx.a libft/libft.a

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	gcc $(FLAGS) -O2 $(LIBS) $(LIBS_FLAGS) $(OBJS) -o $(NAME)

$(LIBS):
	make -C libft
	make -C minilibx_macos

./%.o: ./%.c $(HEADERS)
	gcc $(FLAGS) -O2 $(INC) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: $(LIBS) $(OBJS)
	gcc $(FLAGS) -ggdb $(LIBS) $(LIBS_FLAGS) $(OBJS) -o $(NAME)

normy:
	norminette $(SRCS) $(HEADERS)
