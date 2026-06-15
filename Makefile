CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -DDEFAULT_DEBUG_VIEW=1
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/bin/libft.a
MLX_DIR = mlx
MLX = ${MLX_DIR}/libmlx_Linux.a
LDFLAGS = -L${LIBFT_DIR}/bin -lft -L${MLX_DIR} -lmlx_Linux \
		  -lXext -lX11 -lm -lz
INCLUDE = -Iinclude -I${LIBFT_DIR}/include -I${MLX_DIR}

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
	   ${SRC_DIR}/create/extract_colors.c \
	   ${SRC_DIR}/del/del_mlx.c ${SRC_DIR}/del/del_textures.c \
	   ${SRC_DIR}/configure/configure_game.c \
	   ${SRC_DIR}/configure/configure_textures.c \
	   ${SRC_DIR}/run.c ${SRC_DIR}/input/window_handlers.c \
	   ${SRC_DIR}/configure/configure_player.c \
	   ${SRC_DIR}/render/render_utils.c ${SRC_DIR}/render/render_frame.c \
	   ${SRC_DIR}/render/render_minimap.c ${SRC_DIR}/render/color_utils.c \
	   ${SRC_DIR}/render/render_background.c \
	   ${SRC_DIR}/input/input_hooks.c ${SRC_DIR}/input/player_move.c \
	   ${SRC_DIR}/input/player_rotate.c \
	   ${SRC_DIR}/raycast/init_ray.c ${SRC_DIR}/raycast/dda.c \
	   ${SRC_DIR}/raycast/render_raycast.c \
	   ${SRC_DIR}/raycast/texture_utils.c

OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}
DEBUG_OBJ_DIR = obj_debug
DEBUG_OBJS = ${SRCS:${SRC_DIR}/%.c=${DEBUG_OBJ_DIR}/%.o}
VALIDATE_OBJ = ${OBJ_DIR}/validation_main.o
VALIDATE_OBJS = $(filter-out ${OBJ_DIR}/cub3d.o,${OBJS}) ${VALIDATE_OBJ}

NAME = cub3D
DEBUG_NAME = cub3D_debug
VALIDATE_NAME = cub3D_validate

all: ${NAME}

$(NAME): ${LIBFT} ${MLX} ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

debug: ${DEBUG_NAME}

${DEBUG_NAME}: ${LIBFT} ${MLX} ${DEBUG_OBJS}
	$(CC) ${CFLAGS} ${DEBUG_OBJS} ${LDFLAGS} -o ${DEBUG_NAME}

${DEBUG_OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) ${INCLUDE} -c $< -o $@

validation: ${VALIDATE_NAME}

${VALIDATE_NAME}: ${LIBFT} ${MLX} ${VALIDATE_OBJS}
	$(CC) ${CFLAGS} ${VALIDATE_OBJS} ${LDFLAGS} -o ${VALIDATE_NAME}

test: validation
	$(MAKE) -C tests run

${LIBFT}:
	make -C ${LIBFT_DIR}

${MLX}:
	make -C ${MLX_DIR}

clean:
	rm -rf ${OBJ_DIR} ${DEBUG_OBJ_DIR}
	make -C ${LIBFT_DIR} clean
	make -C ${MLX_DIR} clean

fclean: clean
	rm -rf ${NAME} ${DEBUG_NAME} ${VALIDATE_NAME}
	rm -rf ${LIBFT}

re: fclean all

.PHONY: all clean fclean re debug validation test
