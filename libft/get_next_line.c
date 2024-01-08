/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekouch <mbekouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:21:03 by mbekouch          #+#    #+#             */
/*   Updated: 2023/12/05 20:38:34 by mbekouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*recup_ligne(char *reserve, t_world *world)
{
	int		i;
	char	*ligne;

	i = 0;
	if (!reserve[i])
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	ligne = (char *)ft_malloc((i + 2) * sizeof(char), world);
	if (!ligne)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		ligne[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		ligne[i] = reserve[i];
		i++;
	}
	return (ligne);
}

char	*recup_reste(char *reserve, t_world *world)
{
	int		i;
	int		c;
	char	*reste;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
		return (NULL);
	reste = (char *)ft_malloc((ft_strlen(reserve) - i + 1)
			* sizeof(char), world);
	if (!reste)
		return (NULL);
	i++;
	c = 0;
	while (reserve[i])
		reste[c++] = reserve[i++];
	return (reste);
}

char	*ft_read(int fd, char *str, t_world *world)
{
	char	*buffer;
	int		lus;

	buffer = ft_malloc((BUFFER_SIZE + 1) * sizeof(char), world);
	if (!buffer)
		return (NULL);
	lus = 1;
	if (!str)
		str = (char *)ft_malloc(sizeof(char) * 1, world);
	while (!ft_strchr(str, '\n') && lus != 0)
	{
		lus = read(fd, buffer, BUFFER_SIZE);
		if (lus == -1)
			return (NULL);
		buffer[lus] = '\0';
		str = ft_strjoin_gnl(str, buffer, world);
	}
	return (str);
}

char	*get_next_line(int fd, t_world *world)
{
	char		*ligne;
	static char	*reserve;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reserve = ft_read(fd, reserve, world);
	if (!reserve)
		return (NULL);
	ligne = recup_ligne(reserve, world);
	reserve = recup_reste(reserve, world);
	return (ligne);
}
