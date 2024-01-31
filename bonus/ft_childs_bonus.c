/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:15:10 by ahomari           #+#    #+#             */
/*   Updated: 2024/01/31 18:33:50 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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