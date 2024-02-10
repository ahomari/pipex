/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:16:40 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/10 13:44:11 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static char	*read_fun(int fd, char *tmp)
{
	char	*buff;
	int		read_line;

	read_line = 1;
	buff = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (free(tmp), tmp = NULL, NULL);
	while (read_line > 0)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if (read_line == -1)
			return (free(buff), buff = NULL, NULL);
		buff[read_line] = '\0';
		tmp = ft_strjoinn(tmp, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	if (!tmp)
		return (free(tmp), tmp = NULL, NULL);
	return (tmp);
}

static size_t	ft_len_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

static char	*ft_print_line(char *line)
{
	char	*tmp;
	size_t	i;

	i = ft_len_line(line);
	tmp = (char *)malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, line, i);
	return (tmp);
}

static char	*ft_skip(char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_len_line(line);
	j = 0;
	while (line[i + j])
		j++;
	tmp = (char *)malloc(j + 1 * sizeof(char));
	if (!tmp)
		return (free(line), line = NULL, NULL);
	ft_strcpy(tmp, line + i, j + 1);
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX
		|| BUFFER_SIZE > INT_MAX || read(fd, 0, 0) == -1)
		return (free(tmp), tmp = NULL, NULL);
	tmp = read_fun(fd, tmp);
	if (!tmp || tmp[0] == '\0')
		return (free(tmp), tmp = NULL, NULL);
	line = ft_print_line(tmp);
	if (!line)
		return (free(tmp), tmp = NULL, NULL);
	tmp = ft_skip(tmp);
	return (line);
}
