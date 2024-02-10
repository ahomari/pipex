/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:08:08 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/10 17:36:44 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void f()
{
	system("lsof -c pipex");
	system("leaks pipex");
}

int	main(int ac, char **av, char **env)
{
	int	stdin_;
	int	stdout_;
	int	infile;

	atexit(f);
	stdin_ = dup(0);
	stdout_ = dup(1);
	if (ac != 5)
		error_msg(-2, "Invalid Nmber of Arguments\n");
	infile = open(av[1], O_RDONLY);
	error_msg(infile, "Infile!!");
	error_msg(dup2(infile, STDIN_FILENO), "Dup Failed !!");
	error_msg(close(infile), "Close Failed !!");
	first_child(av, env);
	second_child(av, env);
	error_msg(dup2(stdin_, STDIN_FILENO), "Dup Failed !!");
	error_msg(dup2(stdout_, STDOUT_FILENO), "Dup Failed !!");
	error_msg(close(stdin_), "Close Failed !!");
	error_msg(close(stdout_), "Close Failed !!");
	while (wait(0) != -1)
		;
}
