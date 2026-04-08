CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/bin/libft.a
LDFLAGS = -L${LIBFT_DIR}/bin -lft 
INCLUDE = -Iinclude -I${LIBFT_DIR}/include

SRCS = ${SRC_DIR}/cub3d.c ${SRC_DIR}/validation/argc_validation.c \
	   ${SRC_DIR}/del/del_game.c ${SRC_DIR}/validate/validate_open_file.c \
	   ${SRC_DIR}/create_validate_game.c ${SRC_DIR}/validate/validate_game.c \
	   ${SRC_DIR}/validate/validate_geme_file.c \
	   ${SRC_DIR}/create/extract_token_list.c ${SRC_DIR}/del/del_token.c \
	   ${SRC_DIR}/create/create_token_by_line.c

OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

NAME = cub3D

all: ${NAME}

$(NAME): ${LIBFT} ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_DIR}

clean:
	rm -rf ${OBJ_DIR} && make -C ${LIBFT_DIR} clean

fclean: clean
	rm -rf ${NAME} && rm -rf ${LIBFT}

re: fclean all
