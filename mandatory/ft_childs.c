/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:08:02 by ahomari           #+#    #+#             */
/*   Updated: 2024/01/31 18:11:51 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_index(char **env)
{
	int i;
	
	i = 0;
	while (env[i])
	{
		if (ft_strcmp("PATH", env[i] , 4) == 0)
			return(i);
		i++;
	}
	return(-1);
}
static char *ft_get_cmd(char **path, char *cmd)
{
    char    *tmp;
    char    *ptr;
    int     i;

    i = 0;
    while(path[i])
    {
        tmp = ft_strjoin(path[i], "/");
        ptr = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(ptr, X_OK) == 0)
            return (ptr);
        free(ptr);
        i++;
    }
    return (NULL);
}

void    get_execve(char *av, char **env)
{
    int     find_path;
    char    **cmd_path;
    char    **command;
    char    *cmd;

    if (ft_strchr(av, '/') == 1)
    {
        if (execve(av, NULL, NULL) == -1)
            error_msg("command not found");
    }
    find_path = ft_index(env);
    cmd_path = ft_split(env[find_path] + 5, ':');
    command = ft_split(av, ' ');
    cmd = ft_get_cmd(cmd_path, command[0]);
    if (execve(cmd, command, env) == -1)
            error_msg("command not found");
}

void    first_child(char **av, char **env)
{
    int     infile;
    int     p[2];
    pid_t   pid1;

    infile = open(av[1], O_RDONLY);
	if (infile < 0)
		error_msg("Infile!!");
    if (pipe(p) < 0)
		error_msg("Pipe!!");
	pid1 = fork();
	if (pid1 == 0)
    {
        close(p[0]);
        dup2(p[1], 1);
        dup2(infile, 0);
        close(p[1]);
        close(infile);
        get_execve(av[2], env);
    }
    else
    {
        close(infile);
        close(p[1]);
        dup2(p[0], 0);
        close(p[0]);
    }
}

void    second_child(char **av, char **env)
{
    int outfile;
    pid_t   pid2;

    outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC , 0644);
	if(outfile < 0)
		error_msg("Outfile!!");
    pid2 = fork();
    if(pid2 == 0)
    {
        dup2(outfile, 1);
        close(outfile);
        get_execve(av[3], env);
    }
    else
        close(outfile);
}
