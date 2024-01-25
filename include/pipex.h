/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:01:36 by ahomari           #+#    #+#             */
/*   Updated: 2024/01/25 10:38:33 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libc.h>

typedef stract s_pipex
{
	
}

int		ft_strcmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif