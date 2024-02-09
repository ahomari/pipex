/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:14:45 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/09 20:50:44 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	here_doc(int ac, char **av, char **env)
{
	int		p[2];
	int		len;
	int		i;
	char	*line;
	
	error_msg_bonus(pipe(p), "Here Doc Pipe!!");
	len = ft_strlen(av[2]);
	while (1)
	{
		ft_putstr_fd("here_doc> ", 0);
		line = get_next_line(0);
		if (ft_strcmp(line, av[2], len) == 0 && line[len] == '\n')
			break ;
		ft_putstr_fd(line, p[1]);
		free(line);
	}
	i = 3;
	close(p[1]);
	dup2(p[0], STDIN_FILENO);
	close(p[0]);
	while (i < ac - 2)
	{
		first_here_child(av, env, i);
		i++;
	}
	sec_here_child(ac, av, env);
	exit (0);
}

void	leak()
{
	system("leaks pipex_bonus");
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	infile;
	int	stdin_;
	int	stdout_;

	stdin_ = dup(0);
	stdout_ = dup(1);
	i = 2;
	if (ac >= 5)
	{
		if (ft_strcmp(av[1], "here_doc", 8) == 0 && av[1][8] == '\0')
			here_doc(ac, av, env);
		infile = open(av[1], O_RDONLY);
		dup2(infile, 0);
		close(infile);
		error_msg_bonus(infile, "Infile!!");
		while (i < ac -2)
		{
			first_child(av, env, i);
			i++;
		}
		second_child(ac, av, env);
		dup2(stdin_, 0);
		dup2(stdout_, 1);
		while (wait(0) != -1)
			;
	}
	else
		error_msg_bonus(-2, "Invalid Nmber of Arguments\n");
}
