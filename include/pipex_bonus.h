/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:15:59 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/03 14:54:07 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <libc.h>

int		ft_strcmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
void	print_msg_bonus(char *str);
char	*ft_strdup(char *s1);
void	error_msg_bonus(int num, char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);
char	*ft_strcpy(char *dst, char const *src, size_t len);
void	get_execve(char *av, char **env);
void	first_child(char **av, char **env, int pos, int *infile);
void	second_child(int ac, char **av, char **env);
char	*get_next_line(int fd);
void	here_doc(int ac, char **av, char **env);
void	sec_here_child(int ac, char **av, char **env);
void	first_here_child(char **av, char **env, int pos, int *infile);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoinn(char *s1, char *s2);



#endif