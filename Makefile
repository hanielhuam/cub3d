CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/bin/libft.a
LDFLAGS = -L${LIBFT_DIR}/bin -lft -Lmlx -lmlx -lXext -lX11 -lm -lz
INCLUDE = -Iinclude -I${LIBFT_DIR}/include -Imlx

SRCS = ${SRC_DIR}/cub3d.c ${SRC_DIR}/validation/argc_validation.c \
	   ${SRC_DIR}/del/del_game.c ${SRC_DIR}/validation/validate_open_file.c \
	   ${SRC_DIR}/create_validate_game.c ${SRC_DIR}/validation/validate_game.c \
	   ${SRC_DIR}/validation/validate_game_file.c \
	   ${SRC_DIR}/validation/validate_token_list.c \
	   ${SRC_DIR}/create/extract_token_list.c ${SRC_DIR}/del/del_token.c \
	   ${SRC_DIR}/create/create_token_by_line.c \
	   ${SRC_DIR}/utils/compare_token.c ${SRC_DIR}/create/create_game.c \
	   ${SRC_DIR}/create/assign_assets.c ${SRC_DIR}/utils/dup_str.c \
	   ${SRC_DIR}/constructor/texture_constructor.c \
	   ${SRC_DIR}/constructor/color_constructor.c \
	   ${SRC_DIR}/constructor/map_constructor.c \
	   ${SRC_DIR}/validation/color_validation.c ${SRC_DIR}/del/del_split.c \
	   ${SRC_DIR}/utils/check_file.c ${SRC_DIR}/validation/board_validator.c \
	   ${SRC_DIR}/create/create_v_board.c ${SRC_DIR}/create/extract_colors.c

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
