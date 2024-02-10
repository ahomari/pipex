/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:14:45 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/10 22:32:59 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_dup(int fd0, int fd1)
{
	error_msg_bonus(close(fd1), "Close Failed !!");
	error_msg_bonus(dup2(fd0, STDIN_FILENO), "Dup Failed !!");
	error_msg_bonus(close(fd0), "Close Failed !!");
}

void	ft_close_files(int fd0, int fd1)
{
	error_msg_bonus(close(fd0), "Close Failed !!");
	error_msg_bonus(close(fd1), "Close Failed !!");
}

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
	ft_dup(p[0], p[1]);
	i = 3;
	while (i < ac - 2)
		first_child(av, env, i++);
	second_child(ac, av, env);
	while (wait(0) != -1)
			;
	exit (0);
}

void	ft_open(int ac, char **av, char **env)
{
	int	infile;
	int	i;
	
	i = 2;
	infile = open(av[1], O_RDONLY);
	error_msg_bonus(infile, "Infile!!");
	error_msg_bonus(dup2(infile, STDIN_FILENO), "Dup Failed !!");
	error_msg_bonus(close(infile), "Close Failed !!");
	while (i < ac -2)
			first_child(av, env, i++);
		second_child(ac, av, env);
}
void f()
{
	system("lsof -c pipex");
	system("leaks pipex");
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	stdin_;
	int	stdout_;

	atexit(f);
	stdin_ = dup(0);
	stdout_ = dup(1);
	i = 2;
	if (ac >= 5)
	{
		if (ft_strcmp(av[1], "here_doc", 8) == 0 && av[1][8] == '\0')
		{
			ft_close_files(stdin_, stdout_);
			here_doc(ac, av, env);
		}
		ft_open(ac, av, env);
		error_msg_bonus(dup2(stdin_, STDIN_FILENO), "Dup Failed !!");
		error_msg_bonus(dup2(stdout_, STDOUT_FILENO), "Dup Failed !!");
		ft_close_files(stdin_, stdout_);
		while (wait(0) != -1)
			;
	}
	else
		error_msg_bonus(-2, "Invalid Nmber of Arguments\n");
}
