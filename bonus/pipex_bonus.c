/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:14:45 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/10 17:45:13 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	here_doc(int ac, char **av, char **env, int *stdin_, int *stdout_)
{
	int		p[2];
	int		len;
	int		i;
	char	*line;

	error_msg_bonus(close(*stdin_), "Close Failed !!");
	error_msg_bonus(close(*stdout_), "Close Failed !!");
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
	error_msg_bonus(close(p[1]), "Close Failed !!");
	error_msg_bonus(dup2(p[0], STDIN_FILENO), "Dup Failed !!");
	error_msg_bonus(close(p[0]), "Close Failed !!");
	while (i < ac - 2)
		first_child(av, env, i++);
	second_child(ac, av, env);
	while (wait(0) != -1)
			;
	exit (0);
}

void	ft_open(char **av, int *infile)
{
	*infile = open(av[1], O_RDONLY);
	error_msg_bonus(*infile, "Infile!!");
	error_msg_bonus(dup2(*infile, STDIN_FILENO), "Dup Failed !!");
	error_msg_bonus(close(*infile), "Close Failed !!");
}

void f()
{
	system("lsof -c pipex_bonus");
	system("leaks pipex_bonus");
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	infile;
	int	stdin_;
	int	stdout_;

	// atexit(f);
	stdin_ = dup(0);
	stdout_ = dup(1);
	i = 2;
	if (ac >= 5)
	{
		if (ft_strcmp(av[1], "here_doc", 8) == 0 && av[1][8] == '\0')
			here_doc(ac, av, env, &stdin_, &stdout_);
		ft_open(av, &infile);
		while (i < ac -2)
			first_child(av, env, i++);
		second_child(ac, av, env);
		error_msg_bonus(dup2(stdin_, STDIN_FILENO), "Dup Failed !!");
		error_msg_bonus(dup2(stdout_, STDOUT_FILENO), "Dup Failed !!");
		error_msg_bonus(close(stdin_), "Close Failed !!");
		error_msg_bonus(close(stdout_), "Close Failed !!");
		while (wait(0) != -1)
			;
	}
	else
		error_msg_bonus(-2, "Invalid Nmber of Arguments\n");
}
