/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:15:10 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/09 21:57:50 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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
	return (-1);
}

char	*ft_get_cmd(char **path, char *cmd)
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
	if (ft_strchr(av, '/') == 1)
		error_msg_bonus(execve(av, command, NULL), "Command Not Found !!");
	find_path = ft_index(env);
	cmd_path = ft_split(env[find_path] + 5, ':');
	cmd = ft_get_cmd(cmd_path, command[0]);
	error_msg_bonus(execve(cmd, command, env), "Command Not Found !!");
}

void	first_child(char **av, char **env, int pos)
{
	int		p[2];
	pid_t	pid1;

	error_msg_bonus(pipe(p), "Pipe !!");
	pid1 = fork();
	if (pid1 == 0)
	{
		error_msg_bonus(close(p[0]), "Close Failed !!");
		error_msg_bonus(dup2(p[1], STDOUT_FILENO), "Dup Failed !!");
		error_msg_bonus(close(p[1]), "Close Failed !!");
		get_execve(av[pos], env);
	}
	else
	{
		error_msg_bonus(close(p[1]), "Close Failed !!");
		error_msg_bonus(dup2(p[0], STDIN_FILENO), "Dup Failed !!");
		error_msg_bonus(close(p[0]), "Close Failed !!");
	}
}

void	second_child(int ac, char **av, char **env)
{
	int		outfile;
	pid_t	pid2;

	if (ft_strcmp(av[1], "here_doc", 8) == 0 && av[1][8] == '\0')
		outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	error_msg_bonus(outfile, "Outfile!!");
	pid2 = fork();
	if (pid2 == 0)
	{
		error_msg_bonus(dup2(outfile, STDOUT_FILENO), "Dup Failed !!");
		error_msg_bonus(close(outfile), "Close Failed !!");
		get_execve(av[ac - 2], env);
	}
	else
		error_msg_bonus(close(outfile), "Close Failed !!");
}
