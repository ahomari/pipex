/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmedomari <ahmedomari@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:08:08 by ahomari           #+#    #+#             */
/*   Updated: 2024/01/27 10:23:46 by ahmedomari       ###   ########.fr       */
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


int main(int ac, char **av, char  **env)
{	
	t_pipex pipex;

	if (ac != 5)
		return (print_msg("Invalid Number of Arguments\n"));
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		error_msg("Infile!!");
	pipex.outfile = open(av[4], O_CREAT | O_WRONLY, 0777);
	if(pipex.outfile < 0)
		error_msg("Outfile!!");
	if (pipe(pipex.pipe) < 0)
		error_msg("Pipe!!");
	pipex.find_path = ft_index(env);
	pipex.cmd_path = ft_split(env[pipex.find_path] + 5, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, av, env);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, av, env);
}
