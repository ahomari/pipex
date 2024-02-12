/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:08:02 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/12 15:58:55 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_index(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp("PATH", env[i], 4) == 0)
			return (i);
		i++;
	}
	return (-2);
}

static char	*ft_get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*ptr;
	int		i;

	i = 0;
	while (path[i])
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

void	get_execve(char *av, char **env)
{
	int		find_path;
	char	**cmd_path;
	char	**command;
	char	*cmd;

	command = ft_split(av, ' ');
	find_path = ft_index(env);
	if (ft_strchr(av, '/') == 1)
		error_msg(execve(av, command, NULL), "command not found");
	cmd_path = ft_split(env[find_path] + 5, ':');
	cmd = ft_get_cmd(cmd_path, command[0]);
	error_msg(execve(cmd, command, env), "command not found");
}

void	first_child(char **av, char **env)
{
	int		p[2];
	pid_t	pid1;

	error_msg(pipe(p), "Pipe!!");
	pid1 = fork();
	if (pid1 == 0)
	{
		error_msg(close(p[0]), "Close Failed !!");
		error_msg(dup2(p[1], STDOUT_FILENO), "Dup Failed !!");
		error_msg(close(p[1]), "Close Failed !!");
		get_execve(av[2], env);
	}
	else
	{
		error_msg(close(p[1]), "Close Failed !!");
		error_msg(dup2(p[0], STDIN_FILENO), "Dup Failed !!");
		error_msg(close(p[0]), "Close Failed !!");
	}
}

void	second_child(char **av, char **env)
{
	int		outfile;
	pid_t	pid2;

	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	error_msg(outfile, "Outfile!!");
	pid2 = fork();
	if (pid2 == 0)
	{
		error_msg(dup2(outfile, 1), "Dup Failed !!");
		error_msg(close(outfile), "Close Failed !!");
		get_execve(av[3], env);
	}
	else
		error_msg(close(outfile), "Close Failed !!");
}
