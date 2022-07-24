/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:55:22 by macourio          #+#    #+#             */
/*   Updated: 2022/07/24 09:50:01 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	get_dict_size(int fd)
{
	int		i;
	int		size;
	int		state;
	char	c;

	i = 1;
	c = 0;
	size = 0;
	while (i > 0)
	{
		if (c != '\n' && state != 1)
			state = 1;
		if (c == '\n' && state == 1)
			size++;
		i = read(fd, &c, 1);
	}
	close(fd);
	return (size);
}

char	*parse_key(int fd)
{
	char	c;
	char	*temp;
	char	*key;
	int		size;

	size = 0;
	key = malloc(1 * sizeof(char));
	*key = 0;
	while (c == ' ' || (c >= 9 && c <= 13))
		read(fd, &c, 1);
	while (c >= '0' && c <= '9')
	{
		temp = key;
		key = (char *)malloc(++size * sizeof(char));
		while (*temp)
			*key++ = *temp++;
		*key++ = c;
		*key = 0;
		free(temp);
		read(fd, &c, 1);
	}
	while (c != ':')
		read(fd, &c, 1);
	return(key);
}

char	*parse_value(int fd)
{
	char	c;
	char	*temp;
	char	*value;
	int		size;

	size = 0;
	value = malloc(1 * sizeof(char));
	*value = 0;
	while (c == ' ' || (c >= 9 && c <= 13))
		read(fd, &c, 1);
	while (c != '\n')
	{
		temp = value;
		value = (char *)malloc(++size * sizeof(char));
		while (*temp)
			*value++ = *temp++;
		*value++ = c;
		*value = 0;
		free(temp);
		read(fd, &c, 1);
	}
	return (value);
}

t_element_dict	*fill_dict(t_element_dict *tab, int size, char *filename)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (i < size)
	{
		tab[i] = *(t_element_dict *)malloc(sizeof(t_element_dict));
		tab[i].key = parse_key(fd);
		read(fd, NULL, 1);
		tab[i].value = parse_value(fd);
		i++;
	}
	close(fd);
	return (tab);
}

int	parse_dict(t_element_dict *tab, char *filename)
{
	int				file;
	int				size;

	file = open(filename, O_RDONLY);
	size = get_dict_size(file);
	tab = (t_element_dict *)malloc(size * sizeof(t_element_dict));
	tab = fill_dict(tab, size, filename);
	return (size);
}

int	main(void)
{
	t_element_dict *tab;
	int	size;
	int	i;

	size = parse_dict(tab, "../numbers.dict");
	i = 0;
	while (i < size)
	{
		printf("%s : %s\n", tab[i].key, tab[i].value);
		i++;
	}
}
