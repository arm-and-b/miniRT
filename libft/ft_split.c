/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:11:22 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/05 20:38:34 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_worldocate(char **tab, char const *s, char sep, t_world *world)
{
	char		**tab_p;
	char const	*tmp;

	tmp = s;
	tab_p = tab;
	while (*tmp)
	{
		while (*s == sep)
			s++;
		tmp = s;
		while (*tmp && *tmp != sep)
			tmp++;
		if (*tmp == sep || tmp > s)
		{
			*tab_p = ft_substr(s, 0, tmp - s, world);
			s = tmp;
			tab_p++;
		}
	}
	*tab_p = NULL;
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != sep)
			s++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c, t_world *world)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)ft_malloc(sizeof(char *) * (size + 1), world);
	if (!new)
		return (NULL);
	ft_worldocate(new, s, c, world);
	return (new);
}
