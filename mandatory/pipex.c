/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:08:08 by ahomari           #+#    #+#             */
/*   Updated: 2024/02/12 16:11:11 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	int	stdin_;
	int	stdout_;
	int	infile;

	if (ac != 5)
		error_msg(-2, "Invalid Nmber of Arguments\n");
	stdin_ = dup(0);
	stdout_ = dup(1);
	error_msg(stdin_, "Dup Failed !!");
	error_msg(stdout_, "Dup Failed !!");
	infile = open(av[1], O_RDONLY);
	error_msg(infile, "Infile!!");
	error_msg(dup2(infile, STDIN_FILENO), "Dup Failed !!");
	error_msg(close(infile), "Close Failed !!");
	error_msg(ft_index(env), "unset PATH !!!!");
	first_child(av, env);
	second_child(av, env);
	error_msg(dup2(stdin_, STDIN_FILENO), "Dup Failed !!");
	error_msg(dup2(stdout_, STDOUT_FILENO), "Dup Failed !!");
	error_msg(close(stdin_), "Close Failed !!");
	error_msg(close(stdout_), "Close Failed !!");
	while (wait(0) != -1)
		;
}
