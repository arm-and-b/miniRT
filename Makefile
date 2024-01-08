# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbekouch <mbekouch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:30:10 by jsabound          #+#    #+#              #
#    Updated: 2023/12/13 17:54:56 by mbekouch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR = Objs
SRCS_DIR = $(shell find ./ -type d)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir))
SRCS =		check_params.c	\
		getters.c	\
		getters2.c	\
		error.c	\
		getters_utils.c	\
		element_utils.c	\
		colors.c	\
		utils.c	\
		canva.c	\
		vectors.c	\
		vectors2.c	\
		vectors3.c	\
		matrix.c	\
		matrix2.c	\
		matrix3.c	\
		matrix4.c	\
		maths_utils.c	\
		rays.c	\
		hits.c	\
		discriminants.c	\
		intersection.c	\
		lighting.c	\
		camera.c	\
		shadows.c	\
		main.c	\


OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

DEPS = $(OBJS:.o=.d)

FILE_TO_CHECK = "Makefile.gen"

NAME = miniRT

NAME_TEST = test_crit

NORM = norminette

LIB_DIR	= ./libft

MLX_DIR	= ./mlx

LIBFT	= ./libft/libft.a

MLX	= ./mlx/libmlx.a

FLAGS_LIB    = -lmlx -lm -lXext -lX11

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3

######### TEST CRITERION ########

SRCS_TEST_FILES = test_atof.c  utils_criterion.c test_colors.c test_matrices.c \
				test_camera.c test_view_transform.c test_tuples.c #test_intersections.c test_rays.c
SRC_TEST_DIR = test_criterion/
SRCS_TEST = $(addprefix $(SRC_TEST_DIR), $(SRCS_TEST_FILES))
#CRITERION = -Wl,-rpath=/mnt/nfs/homes/mbekouch/Criterion/build/src -L/mnt/nfs/homes/mbekouch/Criterion/build/src -lcriterion
CRITERION = -Wl,-rpath=/mnt/nfs/homes/abinet/Criterion/build/src -L/mnt/nfs/homes/abinet/Criterion/build/src -lcriterion

#INCLUDE_TEST = -I/mnt/nfs/homes/mbekouch/Criterion/include/criterion
INCLUDE_TEST = -I/mnt/nfs/homes/abinet/Criterion/include/criterion

################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@${CC} ${CFLAGS} ${OBJS} -L ${MLX_DIR} ${FLAGS_LIB} -o ${NAME} ${LIBFT}
	@echo "\033[1;32m---------------- Compiled ----------------\033[0m"

${LIBFT}    :
		  @echo "\033[31m----Building libft----\033[0m"
		  @make -sC ${LIB_DIR}
		  @echo "\033[31m\t----Done----\033[0m"

${MLX}	:
		  @echo "\033[35m----Building MLX----\033[0m"
		  @make -sC ${MLX_DIR}
		  @echo "\033[35m\t----Done----\033[0m"

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $@

test:
	${CC} ${CFLAGS} $(INCLUDE_TEST) $(CRITERION) -L${MLX_DIR} $(SRCS_TEST) -o $(NAME_TEST) ${OBJS} ${FLAGS_LIB} ${LIBFT}


clean:
	@make clean -sC ${LIB_DIR}
	@make clean -sC ${MLX_DIR}
	@$(RM) $(OBJS) $(OBJSBONUS) $(DEPS) -r $(OBJS_DIR)

fclean: clean
	@make fclean -sC ${LIB_DIR}
	@$(RM) $(NAME) $(NAME_TEST) $(BONUS) $(DEPS)

norm:
	@echo "***CHECK NORM FILES***"
	@$(NORM)

re: fclean all

.PHONY: all clean fclean re
