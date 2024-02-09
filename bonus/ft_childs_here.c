/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs_here.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:14:22 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/09 15:06:41 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	first_here_child(char **av, char **env, int pos)
{
	int		p[2];
	pid_t	pid1;

	error_msg_bonus(pipe(p), "Pipe!!");
	pid1 = fork();
	if (pid1 == 0)
	{
		close(p[0]);
		dup2(p[1], 1);
		close(p[1]);
		get_execve(av[pos], env);
	}
	else
	{
		close(p[1]);
		dup2(p[0], 0);
		close(p[0]);
	}
}

void	sec_here_child(int ac, char **av, char **env)
{
	int		outfile;
	pid_t	pid2;

	outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	error_msg_bonus(outfile, "Outfile!!");
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(outfile, 1);
		close(outfile);
		get_execve(av[ac - 2], env);
	}
	else
		close(outfile);
}
