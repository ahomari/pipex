/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:01:36 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/12 15:56:05 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

int		ft_strcmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	error_msg(int num, char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);
void	get_execve(char *av, char **env);
void	first_child(char **av, char **env);
void	second_child(char **av, char **env);
void	print_msg(char *str);
int		ft_index(char **env);
#endif