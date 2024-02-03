/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:41:32 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/03 14:42:35 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*ptr;
	int		i_s1;
	int		i_s2;

	i_s1 = 0;
	i_s2 = 0;
	if (!s1)
		return (free(s1), s1 = NULL, ft_strdup(s2));
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (free(s1), NULL);
	while (s1 && s1[i_s1])
	{
		ptr[i_s1] = s1[i_s1];
		i_s1++;
	}
	while (s2 && s2[i_s2])
	{
		ptr[i_s1 + i_s2] = s2[i_s2];
		i_s2++;
	}
	ptr[i_s1 + i_s2] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}
