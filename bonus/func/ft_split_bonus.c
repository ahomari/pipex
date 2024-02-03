/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:06:20 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/03 13:52:40 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] != c && check == 0)
		{
			check = 1;
			count++;
		}
		else if (str[i] == c)
			check = 0;
		i++;
	}
	return (count);
}

static char	**ft_print(char **ptr, char *s, char c)
{
	int		start;
	size_t	end;
	int		j;

	end = 0;
	j = 0;
	start = -1;
	while (end <= ft_strlen(s))
	{
		if (s[end] != c && start < 0)
			start = end;
		else if ((s[end] == c || end == ft_strlen(s)) && start >= 0)
		{
			ptr[j] = ft_substr(s, start, end - start);
			if (!(ptr[j]))
				return (ft_free(ptr, j));
			start = -1;
			j++;
		}
		end++;
	}
	return (ptr);
}

char	**ft_split(char *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = ft_calloc((ft_count_word(s, c) + 1), sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = ft_print(ptr, s, c);
	return (ptr);
}
