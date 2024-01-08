# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 13:21:55 by mbekouch          #+#    #+#              #
#    Updated: 2023/12/10 00:08:05 by mbekouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_atof.c ft_bzero.c ft_calloc.c ft_is.c ft_itoa.c ft_lst.c ft_lst2.c \
ft_memory.c ft_printf_utils.c ft_printf_utils2.c ft_printf.c ft_put_fd.c \
ft_str_mem.c ft_str.c ft_split.c ft_striteri.c ft_strn.c ft_strtrim.c \
ft_to.c get_next_line.c get_next_line_utils.c \
ft_malloc.c

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = Objs

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

all : $(NAME)
	
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@clang $(CFLAGS) -o $@ -c $<

$(OBJS_DIR) :
	@mkdir -p $@

clean :
	@rm -fr $(OBJS_DIR)

fclean : clean
	@rm -f libft.a

re : fclean all

.PHONY : all clean fclean re