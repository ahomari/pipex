/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmedomari <ahmedomari@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:01:36 by ahomari           #+#    #+#             */
/*   Updated: 2024/01/26 20:28:45 by ahmedomari       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libc.h>

typedef struct s_pipex
{
    int     pipe[2];
    int     infile;
    int     outfile;
    pid_t   pid1;
    pid_t   pid2;
    int     find_path;
    char    **cmd_path;
    char    **command;
    char    *cmd;
    
}t_pipex;

int		ft_strcmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
int     print_msg(char *str);
char	*ft_strdup(char *s1);
void    error_msg(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void    first_child(t_pipex pipe, char **av, char **env);
void    second_child(t_pipex pipe, char **av, char **env);

#endif