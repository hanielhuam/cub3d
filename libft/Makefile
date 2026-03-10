CC = cc
CFLAGS = -Wall -Werror -Wextra -g
DBGFLAGS = -g 
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE = -Iinclude
SRCS = ${SRC_DIR}/ft_isalpha.c ${SRC_DIR}/ft_isdigit.c \
	${SRC_DIR}/ft_isalnum.c ${SRC_DIR}/ft_isascii.c ${SRC_DIR}/ft_isprint.c \
	${SRC_DIR}/ft_strlen.c ${SRC_DIR}/ft_memset.c ${SRC_DIR}/ft_bzero.c \
	${SRC_DIR}/ft_memcpy.c ${SRC_DIR}/ft_memmove.c ${SRC_DIR}/ft_strlcpy.c \
	${SRC_DIR}/ft_strlcat.c ${SRC_DIR}/ft_toupper.c ${SRC_DIR}/ft_tolower.c \
	${SRC_DIR}/ft_strchr.c ${SRC_DIR}/ft_strrchr.c ${SRC_DIR}/ft_strncmp.c \
	${SRC_DIR}/ft_memchr.c ${SRC_DIR}/ft_memcmp.c ${SRC_DIR}/ft_strnstr.c \
	${SRC_DIR}/ft_atoi.c ${SRC_DIR}/ft_calloc.c ${SRC_DIR}/ft_strdup.c \
	${SRC_DIR}/ft_substr.c ${SRC_DIR}/ft_strjoin.c ${SRC_DIR}/ft_strtrim.c \
	${SRC_DIR}/ft_split.c ${SRC_DIR}/ft_itoa.c ${SRC_DIR}/ft_strmapi.c \
	${SRC_DIR}/ft_striteri.c ${SRC_DIR}/ft_putchar_fd.c \
	${SRC_DIR}/ft_putstr_fd.c ${SRC_DIR}/ft_putendl_fd.c \
	${SRC_DIR}/ft_putnbr_fd.c ${SRC_DIR}/ft_separate.c \
	${SRC_DIR}/ft_litoa_base.c ${SRC_DIR}/ft_ulitoa_base.c \
	${SRC_DIR}/ft_atol.c ${SRC_DIR}/ft_isspace.c ${SRC_DIR}/ft_strmerge.c \
	${SRC_DIR}/stack/ft_stcknew.c ${SRC_DIR}/stack/ft_stckadd_front.c \
	${SRC_DIR}/stack/ft_stcksize.c ${SRC_DIR}/stack/ft_stcklast.c \
	${SRC_DIR}/stack/ft_stckadd_back.c ${SRC_DIR}/stack/ft_stckdelone.c \
	${SRC_DIR}/stack/ft_stckclear.c ${SRC_DIR}/stack/ft_stckiter.c \
	${SRC_DIR}/stack/ft_stckmap.c ${SRC_DIR}/stack/ft_stckiter_s.c \
	${SRC_DIR}/stack/ft_stckswap.c ${SRC_DIR}/stack/ft_stckpush.c \
	${SRC_DIR}/stack/ft_stckrotate.c \
	${SRC_DIR}/list/ft_lstnew.c ${SRC_DIR}/list/ft_lstadd_front.c \
	${SRC_DIR}/list/ft_lstsize.c ${SRC_DIR}/list/ft_lstlast.c \
	${SRC_DIR}/list/ft_lstadd_back.c ${SRC_DIR}/list/ft_lstdelone.c \
	${SRC_DIR}/list/ft_lstclear.c ${SRC_DIR}/list/ft_lstiter.c \
	${SRC_DIR}/list/ft_lstmap.c \
	${SRC_DIR}/ft_printf/ft_printf.c ${SRC_DIR}/ft_printf/ft_transl_chars.c \
	${SRC_DIR}/ft_printf/ft_transl_digits.c \
	${SRC_DIR}/ft_printf/ft_transl_no.c \
	${SRC_DIR}/ft_printf/ft_transl_udigits.c ${SRC_DIR}/ft_printf/t_print.c \
	${SRC_DIR}/GNL/get_next_line.c ${SRC_DIR}/GNL/get_next_line_utils.c \
	${SRC_DIR}/GNL/get_next_delimiter.c ${SRC_DIR}/dlist/ft_dlstadd_back.c \
	${SRC_DIR}/dlist/ft_dlstclear.c ${SRC_DIR}/dlist/ft_dlstiter.c \
	${SRC_DIR}/dlist/ft_dlstlast.c ${SRC_DIR}/dlist/ft_dlstnew.c \
	${SRC_DIR}/dlist/ft_dlstadd_front.c ${SRC_DIR}/dlist/ft_dlstdelone.c \
	${SRC_DIR}/dlist/ft_dlstmap.c ${SRC_DIR}/dlist/ft_dlstsize.c \
	${SRC_DIR}/tree/ft_treenew.c ${SRC_DIR}/tree/ft_treefar_left.c \
	${SRC_DIR}/tree/ft_treefar_right.c ${SRC_DIR}/tree/ft_treeadd_left.c \
	${SRC_DIR}/tree/ft_treeadd_right.c ${SRC_DIR}/tree/ft_treedelone.c \
	${SRC_DIR}/tree/ft_treeclear.c ${SRC_DIR}/tree/ft_treeiter.c
	
OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

NAME = ${BIN_DIR}/libft.a

all: ${NAME}

${NAME}: ${OBJS}
	@mkdir -p ${BIN_DIR}
	ar rcs ${NAME} ${OBJS}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

clean: 
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -rf ${BIN_DIR}

re: fclean all
