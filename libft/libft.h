/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:33:33 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/15 20:43:54 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdarg.h>
# include "../MiniRT.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_world	t_world;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isalnum(int c);
int			ft_isupcase(int c);
int			ft_islowcase(int c);
int			ft_atoi(const char *nptr, t_world *world, int *i);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_lstsize(t_list *lst);
int			ft_printf(const char *str, ...);
int			ft_putcharf(char c);
int			ft_putnbrf(int nb);
int			ft_putstrf(char	*str);
int			ft_convert_hex(const char format, size_t nb);
int			ft_convert_pointer(size_t nb);
int			ft_put_unsigned(unsigned int nb);
int			ft_unsize(size_t n, int base, bool pointer);
float		ft_atof(char *str, t_world *world);
void		*ft_malloc(size_t	size, t_world *world);
char		*ft_substr(char const *s, unsigned int start, size_t len,
				t_world *world);
char		**ft_split(char const *s, char c, t_world *world);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlcat(char *dest, char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t	len);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		*ft_strjoin_gnl(char *s1, char *s2, t_world *world);
char		*recup_ligne(char *reserve, t_world *world);
char		*recup_reste(char *reserve, t_world *world);
char		*ft_read(int fd, char *str, t_world *world);
char		*get_next_line(int fd, t_world *world);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
t_list		*ft_lstnew(void *content, t_world *world);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_clear(t_list **lst, void *cont);

#endif
