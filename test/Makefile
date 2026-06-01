CC = cc

CFLAGS = -Wall -Wextra -Werror -g

ROOT = ..

SRC_DIR = ${ROOT}/src

OBJ_DIR = obj

BIN_DIR = bin

LIBFT_DIR = ${ROOT}/libft

LIBFT = ${LIBFT_DIR}/bin/libft.a

INCLUDE = -I${ROOT}/include -I${LIBFT_DIR}/include -I${ROOT}/mlx

LDFLAGS = -L${LIBFT_DIR}/bin -lft

NAME = ${BIN_DIR}/validation_test

VPATH = .:${SRC_DIR}:${SRC_DIR}/del:${SRC_DIR}/validation:${SRC_DIR}/create \
	:${SRC_DIR}/utils:${SRC_DIR}/constructor

SRCS = validation_main.c del_mlx_stub.c del_game.c validate_open_file.c \
	create_validate_game.c validate_game.c validate_game_file.c \
	validate_token_list.c extract_token_list.c del_token.c \
	create_token_by_line.c compare_token.c create_game.c assign_assets.c \
	dup_str.c texture_constructor.c color_constructor.c map_constructor.c \
	color_validation.c del_split.c check_file.c board_validator.c \
	create_v_board.c extract_colors.c

OBJS = ${SRCS:%.c=${OBJ_DIR}/%.o}

all: test-validation

${NAME}: ${LIBFT} ${OBJS}
	mkdir -p ${BIN_DIR}
	${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: %.c
	mkdir -p $(dir $@)
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_DIR}

test-validation: ${NAME}
	cd ${ROOT} && bash test/run_validation.sh ./test/${NAME}

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${BIN_DIR}

re: fclean all