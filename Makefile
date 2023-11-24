NAME = cub3D
LIB_ARC = ./libft/libft.a
UNAME := $(shell uname)


CC := cc
CFLAGS := -Wall -Wextra -Werror -g -I includes

ifeq ($(UNAME), Darwin)
	CFLAGS += -Imlx
	CXXFLAGS = -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit -lm
else ifeq ($(UNAME), Linux)
	CFLAGS += -Imlx_linux
	CXXFLAGS = -Lmlx_linux -lmlx_Linux -Llibft -lft -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	$(error Unsupported OS: $(UNAME))
endif


UTILS = ${addprefix utils/, }
PARSE = ${addprefix parse/, ft_error p_check p_cpy_map p_init p_map \
		p_map_utilis p_parse p_text_utilis p_texture p_wall p_wall_utilis parsing_utils}
SAUCE = ${addprefix sauce/, ${addsuffix .c, execution movement ray_cast \
		events window texture movement_director movement_handler error_handler \
		parse_assist parse_assist_ex main ${UTILS} ${PARSE}}}
OBJS = ${SAUCE:c=o}


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS} ${LIB_ARC}
	${CC} ${OBJS} $(CXXFLAGS) -o ${NAME}

${LIB_ARC}: libft
	make -C libft

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

clib:
	make clean -C libft

fclib : clib
	make fclean -C libft

fall : fclib fclean

re: fclean all

.PHONY: all clean clib fclean fclib re
